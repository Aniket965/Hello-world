decimalToBinary :: Int -> [Int]
decimalToBinary 0 = [0]
decimalToBinary 1 = [1]
decimalToBinary n = decimalToBinary (n `div` 2) ++ [(n `mod` 2)]