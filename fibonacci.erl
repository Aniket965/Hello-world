-module(source).
    -export([entry_point/0]).
    
    fib(1,_,Res) -> 
        io:format("~B, ",[Res]);
    fib(N,Prev,Res) when N > 1 -> 
        io:format("~B, ",[Res]),
        fib(N-1, Res, Res+Prev).
     
    entry_point() -> 
        fib(16,0,1),
        io:format("...~n").
