main :-
    read_file(user_input,Lines),
    close(user_input),combina(Lines,[]).

read_file(Stream,[]) :-
    at_end_of_stream(Stream).

read_file(Stream,[X|L]) :-
    \+ at_end_of_stream(Stream),
    read_line_to_codes(Stream,Codes),
    atom_string(X, Codes),
    read_file(Stream,L), !.
    
concatena(Y,X,N):-
sub_string(Y, _, L, 0, Sub),
sub_string(X, 0, L,_, Sub),
L > 3,
string_concat(Sub,R,X),
string_concat(Y,R,N).

testa(X,Y,Z) :- concatena(X,Y,Z);concatena(Y,X,Z).

combina([X|[Y|Z]],R) :- testa(X,Y,N),append([N|R],Z,L),combina(L,[]);combina([X|Z],[Y|R]).
combina([X,Y],R) :- testa(X,Y,N),combina([N|R],[]);combina([Y|R],[]),write(X),nl.
combina([X|[]],[]):-write(X),nl.






append([],X,X).                            
append([X|Y],Z,[X|W]) :- append(Y,Z,W).
