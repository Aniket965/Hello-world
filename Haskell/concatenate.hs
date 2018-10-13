concatenate :: [Int] -> [Int] -> [Int]
concatenate x [] = x
concatenate [] x = x
concatenate (x:xs) (y:ys)
    | x < y = [x] ++ concatenate xs ([y] ++ ys)
    | otherwise = [y] ++ concatenate ([x] ++ xs) ys