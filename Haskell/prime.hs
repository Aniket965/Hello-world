prime :: Int -> Bool
prime 0 = False
prime 1 = False
prime n = checkPrime n (n `div` 2)

checkPrime :: Int -> Int -> Bool
checkPrime _ 1 = True
checkPrime num x
    | (num `mod` x == 0) = False
    | otherwise = checkPrime num (x-1)