#! /usr/bin/env hy
(defn greet [thing]
   (-> (.format "Hello, {}!" thing) 
       (print)))

(greet "World")
