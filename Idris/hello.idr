{-
HOW TO:
1) install cabal and idris
2) run:
$ idris hello.idr -o hello
$ ./hello
-}

module Main

main : IO ()
main = putStrLn "Hello world"
