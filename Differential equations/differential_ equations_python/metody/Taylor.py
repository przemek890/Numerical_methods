import numpy as np
from sympy import symbols, diff, lambdify
from typing import Callable

"""-----------------------------------------------------"""
"""K-TE POCHODNE"""
def k_deriv(f: Callable, k: int) -> Callable:
    x, t = symbols('x t')
    f_expr = f(x, t)
    d_expr = f_expr
    for i in range(k):
        d_expr = diff(d_expr, t)
    return lambdify((x, t), d_expr)
# k = 2                                                               # stopien pochodnej x' = f(x(t),t) wzgledem zmiennej t
# deriv_k = kth_derivative(equation, k)
# print(deriv_k(1, 4))                                              # wartość k-tej pochodnej dla zagadnienia początkowego: t = 4; x(4) = 1

"""METODA TAYLORA:"""
def Taylor(f1,f2,f3,x0,t):
    n = len(t)
    x = np.zeros((n, len(x0)))
    x[0] = x0
    for i in range(n - 1):
        h = t[i + 1] - t[i]
        k1 = f1(x[i], t[i])
        k2 = f2(x[i], t[i])
        k3 = f3(x[i], t[i])
        x[i + 1] = x[i] + h*k1 + (h**2/2)*k2 + (h**3/6)*k3
    return x