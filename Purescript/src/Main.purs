module Main where

import Prelude
import Effect (Effect)
import Effect.Console (log)

-- | STEPS TO RUN THIS CODE
-- | 1. Navigate to Purescript directory (cd Purescript)
-- | 2. Install purescript with it's dependencies
-- |    npm install -g purescript pulp bower
-- | 3. Run this in terminal
-- |    pulp run

main :: Effect Unit
main = do
  log "Hello world."
