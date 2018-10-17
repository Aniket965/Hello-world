def dec_to_bin(num):
    #my original method was not as nice as this one
    if num<2: return str(num)
    else:
        return dec_to_bin(num//2) + dec_to_bin(num%2)

print(dec_to_bin(100000))

#if n gets really big a while loop may be better something along the lines of this
# def dec_to_bin(number):
#     binary = ''
#     while(number > 0):
#         binary += str(number % 2)
#         number //= 2
#     return binary[::-1]
