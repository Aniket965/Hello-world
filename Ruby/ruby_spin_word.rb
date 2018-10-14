# This program takes 2 strings s1 and s2 including only letters from a to z. Returns a new sorted string, the longest possible, containing distinct letters. each taken only once - coming from s1 or s2. Examples:  a = "xyaabbbccccdefww" b = "xxxxyyyyabklmopq" longest(a, b) -> "abcdefklmopqwxy"

def longest(a1, a2)
  s3 = a1 + a2
  s4 = s3.split('').sort.uniq.join("")
  return s4
end



longest("aretheyhere", "yestheyarehere")
longest("loopingisfunbutdangerous", "lessdangerousthancoding")
longest("inmanylanguages", "theresapairoffunctions")