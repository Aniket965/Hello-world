;; Author- Dedipyaman Das (2d@twodee.me)
;; Successive squaring to find fibonacci
;; Derived by given formula

(define (is-even? x)
  (= (remainder x 2) 0))
(define (square x) (* x x))

(define (fib n)
  (define (fib-iter a b p q count)

    (cond ((= count 0) b)
	  ((is-even? count) ;; Do successive squaring
	   (fib-iter a
		     b
		     (+ (square p) (square q))
		     (+ (* 2 p q) (square q))
		     (/ count 2)))
	  (else ;; Odd stuff
	   (fib-iter (+ (* b q) (* a q) (* a p))
		     (+ (* b p) (* a q))
		     p q (- count 1)))))
  (fib-iter 1 0 0 1 n))
