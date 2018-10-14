linearize :: [[Int]] -> [Int]
linearize [] = []
linearize [x] = x
linearize (x:xs) = linearize [x] ++ linearize xs