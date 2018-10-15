coinRow :: [Integer] -> Integer
coinRow cs = fs !! (length cs)
    where fs = 0 : head cs : zipWith (max) (zipWith (+) (tail cs) fs) fs

fib n = fibs !! n
    where fibs = 0 : 1 : zipWith (+) fibs (drop 1 fibs)
