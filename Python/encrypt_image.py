from PIL import Image

# INTERNAL
import brutus

# Consider a picture made up of pixels in an array M x N.
# MOTIVATION:
# 256 = 2^8. Use these rgb values in an RSA type scheme.
# Pick p < 256 prime, p != 2.
# if a is even, take a + 1 (mod 256) [1 different wont matter, image should be largely the same]
# then a ^ 128+1 = a, (phi totient = 128).as # 129 = 43*3

# this scrambles but can be easily decrypted if method is known

def main():
    im, im_arr = load_image("Images/fest.png")
    #im, im_arr = load_image("../Images/encrypt.png")

    x_size, y_size = im.size
    basic_encrypt_scramble(im_arr, x_size, y_size)
    two_key_encryption(im_arr, x_size, y_size, 123, 4574574)
    save_image("Images/encrypt.png", im)
    two_key_decryption(im_arr, x_size, y_size, 123, 4574574)
    basic_decrypt_unscramble(im_arr, x_size, y_size)
    save_image("Images/decrypt.png", im)
    pass

def encrypt_image(file_path, key1, key2, outpath = "Images/encrypt.png"):
    im, im_arr = load_image(file_path)
    x_size, y_size = im.size

    basic_encrypt_scramble(im_arr, x_size, y_size)
    two_key_encryption(im_arr, x_size, y_size, key1, key2)
    save_image(outpath, im)

def decrypt_image(file_path, key1, key2, outpath = "Images/decrypt.png"):
    im, im_arr = load_image(file_path)
    x_size, y_size = im.size

    two_key_decryption(im_arr, x_size, y_size, key1, key2)
    basic_decrypt_unscramble(im_arr, x_size, y_size)
    save_image(outpath, im)

def load_image(file_path):
    im = Image.open(file_path, 'r')
    arr = im.load()
    print("Image loaded")
    return im, arr

def save_image(file_path, im):
    im.save(file_path)
    print("Image saved")


def basic_encrypt_scramble(im_arr, x_size, y_size):
    # Might be worth adding small noise to images with lots of solid colour.
    for x in range(x_size):
        if x % 100 == 0:
            print("Encrypting: ", x, "/", x_size)
        for y in range(y_size):
            pixel = im_arr[x, y]
            coprime_pixel = ((c+1 if c % 2 == 0 else c) for c in pixel)
            im_arr[x, y] = tuple(int(c**43 % 256) for c in coprime_pixel)

def basic_decrypt_unscramble(im_arr, x_size, y_size):
    for x in range(x_size):
        if x % 100 == 0:
            print("Decrypting: ", x, "/", x_size)
        for y in range(y_size):
            pixel = im_arr[x, y]
            im_arr[x, y] = tuple(int(c**3 % 256) for c in pixel)

def two_key_encryption(im_arr, x_size, y_size, k1, k2):
    size = x_size*y_size

    permut = brutus.two_kdp(size, k1, k2)

    temp_hold = []

    for x in range(x_size):
        temp_hold.append([])
        for y in range(y_size):
            temp_hold[x].append(im_arr[x, y])

    for x in range(x_size):
        for y in range(y_size):
            p_index = permut[x*y_size + y]
            p_x_index = int(p_index / y_size)
            p_y_index = int(p_index - (p_x_index * y_size))
            im_arr[x, y] = temp_hold[p_x_index][p_y_index]
    pass


def two_key_decryption(im_arr, x_size, y_size, k1, k2):
    size = x_size*y_size

    permut = brutus.two_kdp(size, k1, k2)

    for p in permut:
        if type(p) is not int:
            print(p)
            assert False
    temp_hold = []

    for x in range(x_size):
        temp_hold.append([])
        for y in range(y_size):
            temp_hold[x].append(im_arr[x, y])

    for x in range(x_size):
        for y in range(y_size):
            p_index = permut[x*y_size + y]
            p_x_index = int(p_index / y_size)
            p_y_index = int(p_index - (p_x_index * y_size))
            im_arr[p_x_index, p_y_index] = temp_hold[x][y]
    pass

def rotation_cipher(key, im, im_arr):
    # Use a 128 bit key which goes into an injective map that produces permutations.
    # This key should be chosen using crypto-safe methods - system values etc.
    # For bit n: rotate incrementally blocks of proportion 1/n. Use rounding to make things work.
    # If image is too small then a smaller key can be produced.
    #
    # worked example: 1010 - rotate whole image pi/2, then take blocks which have size 1/3 of whole image,
    # rotate block in top left corner, then move 1 pixel right, etc. at end of row, go back to left and 1 pixel down.

    for b in key:
        if b is not '0' and b is not '1':
            raise ValueError("Key must be a binary string.")

    x_size, y_size = im.size

    x_min = True

    if x_size <= y_size:
        min_side_size = x_size
        max_side_size = y_size
    else:
        x_min = False
        min_side_size = y_size
        max_side_size = x_size

    for bit_index in range(len(key)):
        print("Doing rotation ", bit_index, "/", len(key))
        if key[bit_index] == '1':
            # make rotation
            blk_size = min_side_size / (bit_index+1)

            for max_side_index in range(max_side_size-blk_size+1):
                for min_side_index in range(min_side_size-blk_size+1):
                    if x_min:
                        # rotate size blk_size starting min_side_index, max_side_index
                        rot(im_arr, blk_size, min_side_index, max_side_index)
                        pass
                    else:
                        # rotate size blk_size starting max_side_index, min_side_index
                        rot(im_arr, blk_size, max_side_index, min_side_index)
                        pass
    pass

def rot(im_arr, blk_size, x1, y1):
    temple = []
    for i in range(blk_size):
        temple.append([])
        for j in range(blk_size):
            temple[i].append(im_arr[x1+i, y1+j])
    for i in range(blk_size):
        for j in range(blk_size):
            im_arr[x1+i, y1+j] = temple[blk_size-1-i][blk_size-1-j]


def reverse_rotation_cipher():
    # Same as above code, but we run backwards through the key and the array for each block.
    pass

if __name__ == '__main__':
    main()