open import System.IO using ( _>>_ ; putStr ; commit )

module System.IO.Examples.HelloWorld where

main = putStr "Hello, World\n" >> commit
