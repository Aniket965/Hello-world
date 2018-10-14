"""
Script for convert image from webp to png format
Script required for use Pillow library
"""
import os
from PIL import Image


def img_rename(img):
    """ Convert and rename image """
    image = Image.open(img)
    image_name = img.replace('.webp', '')
    image.save('Out/{}.png'.format(image_name))


if __name__ == "__main__":
    FILES = os.listdir()
    IMGS = filter(lambda x: x.endswith('.webp'), FILES)
    if not os.path.exists('Out'):
        os.mkdir('Out')
    [img_rename(img) for img in IMGS]