def bisseccao(f, a, b, epsilon):
    if f(a) * f(b) >= 0:
        raise ValueError("A função deve ter sinais opostos em a e b.")

    while (b - a) >= epsilon:
        x = (a + b) / 2
        a, b = (x, b) if f(a) * f(x) > 0 else (a, x)

    return (a + b) / 2  # Aproximação da raiz


def posicao_falsa(f, a, b, epsilon1, epsilon2):
    if f(a) * f(b) >= 0:
        raise ValueError("A função deve ter sinais opostos em a e b.")

    while (b - a) >= epsilon1:
        x = (a * f(b) - b * f(a)) / (f(b) - f(a))

        if abs(f(x)) < epsilon2: return x  # Aproximação da raiz

        a, b = (x, b) if f(a) * f(x) > 0 else (a, x)

    return (a + b) / 2


def ponto_fixo(f, phi, x0, epsilon1, epsilon2):
    while True:
        x1 = phi(x0)
        if abs(f(x1)) < epsilon1 or abs(x1 - x0) < epsilon2: return x1  # Aproximação da raiz
        x0 = x1

newton = lambda f, df, x0, tol=1e-6, max_iter=1000: next(
    (x0 for _ in range(max_iter)
     if abs(f(x0 := x0 - f(x0)/df(x0))) < tol),
    x0)

_raise = lambda e: (_ for _ in ()).throw(e) # Define o erro a ser lançado quando a função diverge

secante = lambda f, x0, x1, tol=1e-6, max_iter=1000: next(
    (
        x1 if abs(fx := f(x1)) < tol else
        _raise(ZeroDivisionError("f(x1) - f(x0) == 0. A função diverge!"))
        if (fx - f(x0)) == 0 else
        (x0 := x1, x1 := x1 - fx * (x1 - x0) / (fx - f(x0)))[0]
        for _ in range(max_iter)
    ),
    None
)

f = lambda x: x**3 - x - 2
phi = lambda x: (x + 2) ** (1/3)
df = lambda x: 3*x**2 - 1

raiz_bisseccao = bisseccao(f, 1, 2, 1e-6)
raiz_posicao_falsa = posicao_falsa(f, 1, 2, 1e-6, 1e-6)
raiz_ponto_fixo = ponto_fixo(f, phi, 1.5, 1e-6, 1e-6)

print(f"Bissecção: {raiz_bisseccao}")
print(f"Posição Falsa: {raiz_posicao_falsa}")
print(f"Ponto Fixo: {raiz_ponto_fixo}")
print("Newton:", newton(f, df, x0=1.5))
print("Secante:", secante(f, 1, 2))