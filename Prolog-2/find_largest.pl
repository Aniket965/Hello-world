/*
------------------------------------------------------------------------------------------

Usage: find the largest number from a list 
largest([3,4,[5,2],[1,7,2]],N). -> N=7.
------------------------------------------------------------------------------------------
*/

largest(L, N) :- flatten(L, NewL), listlargest(NewL,N).

% First flatten the list to remove the nested list 
% Second find the largest value of the fiven list 

flatten([], []) :- !.
flatten([A|L], [A|R]) :- atomic(A), !, flatten(L, R).
flatten([A|L], R) :- flatten(A, NewL), flatten(L, OldL), append(NewL, OldL, R).

listlargest([X|L],Max) :- listlargesthelper(L,X,Max).
listlargesthelper([],Max,Max).
listlargesthelper([X|L],LocalMax,Max) :- max(X,LocalMax,NewLocalMax), listlargesthelper(L,NewLocalMax,Max).

max(X,Y,X) :- X >= Y, !.
max(X,Y,Y).