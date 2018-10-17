# https://www.codewars.com/users/Kueen
# https://www.codewars.com/kata/roman-numerals-decoder/python

def solution(roman):
   ans=0
   curr=0
   arr={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
   rom_to_int=[arr[i] for i in roman]
   for r in rom_to_int[::-1]:
       ans+=r if r>=curr else -r
       curr=r
   return ans
