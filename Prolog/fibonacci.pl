main :-
    show_fibo(100).

is_fibo([1, 0]).
is_fibo([X,Y,Z|FIBO]):-
    is_fibo([Y,Z|FIBO]),
    X is Y+Z.

write_nl([]).
write_nl([X|L]):-
    write_nl(L),
    write(X), nl.

show_fibo(N):-
    length(L, N),
    is_fibo(L),
    write_nl(L).
