def AFD(M, cadeia):
    (Q, Sigma, delta, q0, F) = M
    qA = q0
    try:
        for x in cadeia:
            qA = delta[(qA, x)]
        return qA in F
    except:
        return False

delta = { ('Passeia','v'): 'Persegue', ('Persegue','n'): 'Passeia', ('Persegue','e'): 'Foge',
    ('Foge','a'): 'Passeia', ('Passeia','e'): 'Foge', ('Foge','c'): 'Retorna' }
Q = ['Passeia', 'Persegue', 'Foge', 'Retorna']
F = ['Retorna']

# Vê o pacman, Não vê o pacman, Especial do pacman, Acaba especial, Comido pelo pacman (FIM)
#     |               |                  |                 |                |
#     V               N                  E                 A                C

Sigma = ['v', 'n', 'e', 'a', 'c']

#--------------------------------------------------------------------------------------------#

string_processada = 'vec'

print(AFD((Q, Sigma, delta, 'Passeia', F), string_processada)) 