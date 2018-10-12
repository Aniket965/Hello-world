(defn sieve [limit]
  (loop [candidates (range 2 (* limit limit)) current 2]
    (if (>= current limit)
        candidates
        (let [multiples
               (set (map
                      #(* current %)
                      (range 2 (/ (* limit limit) current))))
              updated (vec (remove multiples candidates))]
          (recur updated (first (drop-while #(<= % current) updated)))))))

