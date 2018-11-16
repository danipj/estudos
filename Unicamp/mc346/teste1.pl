conta(_,[],0).
conta(I,[I|R],N) :- conta(I,R,NN), N is NN+1.
conta(I,[_|R],N) :- conta(I,R,N).

remove(_,[],[]).
remove(I,[I|R],X) :- X = R.
remove(I,[Y|R],X) :- remove(I,R,XX), X = [Y|XX].