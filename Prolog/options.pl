:- inicio.
inicio :-
    repeat,
    write('1 - Listar os relacionamentos pai'), nl,
    write('2 - Adicionar um relacionamento pai'), nl,
    write('3 - Remover um relacionamento pai'), nl,
    write('4 - Sair do programa'), nl,
    write('Opcao: '),
    read(Resp),
    (Resp = 4, nl, write('Fim!!!!');
        write('Você escolheu a opção correta'), nl).
