import Prelude
import Effect.Console (log)

show :: String -> String
show name = "Hello, " <> name <> "!"

main = log (show "World")
