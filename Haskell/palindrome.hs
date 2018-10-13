palindrome :: [Int] -> Bool
palindrome [] = False
palindrome x = x == reversed x

reversed :: [Int] -> [Int]
reversed [] = []
reversed (x:xs) = reversed xs ++ [x]