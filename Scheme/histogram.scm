(define (update_histagram ls val)
	(if (null? ls) (list (list val 1))
		(if (equal? (car (car ls)) val)
				(cons (list val (+ (car (cdr (car ls))) 1)) (cdr ls))
				(cons (car ls) (update_histagram (cdr ls) val)))))

(define (histogram ls)
	(if (null? ls) '()
		(update_histagram (histogram (cdr ls)) (car ls))))
