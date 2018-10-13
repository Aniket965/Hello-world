moneyChange :: Int -> [Int]
moneyChange x
    | x >= 100 = moneyChange (x-100) ++ [100]
    | x >= 50 = moneyChange (x-50) ++ [50]
    | x >= 10 = moneyChange (x-10) ++ [10]
    | x >= 5 = moneyChange (x-5) ++ [5]
    | x >= 1 = moneyChange (x-1) ++ [1]
    | otherwise = []