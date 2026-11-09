soma = lambda x, y : x + y
lst = [1, 2]

laco = lambda lst : next(
    (x for x in lst if x<5), None)

#print(laco(lst))
#print(soma(6, 4))

a = 1
s = 2
while s > 1:
    a = a/2
    s = 1 + a
    p = 2*a
print(p)

# Precisão da máquina: 2.220446049250313e-16

