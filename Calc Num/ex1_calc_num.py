from math import exp, cos

# Define as funções
f1 = lambda x: exp(-x**2) - cos(x)
f2 = lambda x: x**3 - x - 1

phi2 = lambda x: (x + 1)**(1/3)
df2 = lambda x: 3*x**2 - 1

def bisseccao(f, a, b, epsilon):
    if f(a) * f(b) >= 0:
        raise ValueError("A função deve ter sinais opostos em a e b.")
    iteracoes = 0
    while (b - a) / 2 >= epsilon:
        x = (a + b) / 2
        iteracoes += 1
        if f(a) * f(x) > 0:
            a = x
        else:
            b = x
    raiz = (a + b) / 2
    return raiz, f(raiz), abs(b - a) / 2, iteracoes

def posicao_falsa(f, a, b, epsilon1, epsilon2):
    if f(a) * f(b) >= 0:
        raise ValueError("A função deve ter sinais opostos em a e b.")
    iteracoes = 0
    while abs(b - a) >= epsilon1:
        x = (a * f(b) - b * f(a)) / (f(b) - f(a))
        iteracoes += 1
        if abs(f(x)) < epsilon2:
            return x, f(x), abs(b - a), iteracoes
        if f(a) * f(x) > 0:
            a = x
        else:
            b = x
    x = (a + b) / 2
    return x, f(x), abs(b - a), iteracoes

def ponto_fixo(f, phi, x0, epsilon1, epsilon2):
    iteracoes = 0
    while True:
        x1 = phi(x0)
        iteracoes += 1
        if abs(f(x1)) < epsilon1 or abs(x1 - x0) < epsilon2:
            return x1, f(x1), abs(x1 - x0), iteracoes
        x0 = x1

def newton(f, df, x0, tol=1e-6, max_iter=1000):
    iteracoes = 0
    while iteracoes < max_iter:
        x1 = x0 - f(x0) / df(x0)
        erro = abs(x1 - x0)
        iteracoes += 1
        if abs(f(x1)) < tol or erro < tol:
            return x1, f(x1), erro, iteracoes
        x0 = x1
    return x1, f(x1), erro, iteracoes

def secante(f, x0, x1, tol=1e-6, max_iter=1000):
    iteracoes = 0
    while iteracoes < max_iter:
        fx0 = f(x0)
        fx1 = f(x1)
        if fx1 - fx0 == 0:
            raise ZeroDivisionError("f(x1) - f(x0) == 0. A função diverge!")
        x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0)
        erro = abs(x2 - x1)
        iteracoes += 1
        if abs(f(x2)) < tol or erro < tol:
            return x2, f(x2), erro, iteracoes
        x0, x1 = x1, x2
    return x2, f(x2), erro, iteracoes

# Execução

print("=== Função 1: f(x) = e^(-x²) - cos(x) ===")
print("Bissecção:", bisseccao(f1, 1, 2, 1e-4))
print("Posição Falsa:", posicao_falsa(f1, 1, 2, 1e-4, 1e-4))

print("\n=== Função 2: f(x) = x³ - x - 1 ===")
print("Bissecção:", bisseccao(f2, 1, 2, 1e-6))
print("Posição Falsa:", posicao_falsa(f2, 1, 2, 1e-6, 1e-6))
print("Ponto Fixo:", ponto_fixo(f2, phi2, 1.2, 1e-6, 1e-6))
print("Newton:", newton(f2, df2, 0.5))
print("Secante:", secante(f2, 0, 0.5))
