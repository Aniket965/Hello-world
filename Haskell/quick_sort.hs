main = do
    input <- getContents
    let numbers = map read (words input) :: [Integer]
    print $ quicksort numbers

quicksort:: (Ord a) => [a] -> [a]
quicksort []     = []
quicksort (x:xs) =
    let lesser   = quicksort filter (<x) xs
        greater  = quicksort filter (>= x) xs
     in lesser ++ [x] ++ greater
