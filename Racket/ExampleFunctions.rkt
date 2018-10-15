#lang racket
; Divisible by x, takes 2 inputs, checks if the first number is
; divisible by the second number
(define (divisible-by-x? x y)
  (= (remainder y x) 0)
  )

; Function-9, takes one function as input, and passes 9 to it
(define (function-9 x)
  (x 9)
  )

; my-map takes one function as input, and applies it to a list
(define (my-map f lst)
  (cond
   [(empty? lst)(0)]
   [else (cons (f (first lst))
               (my-map f (rest lst)))]))

