replace :: Int -> Int -> [Int] -> [Int]
replace _ _ [] = []
replace a b (x:xs)
    | a == x = b : replace a b xs
    | otherwise = x : replace a b xs