import numpy as np
"""METODA EULERA:"""
def Mod_Euler(f, x0, t):
    n = len(t)
    x = np.zeros((n, len(x0)))
    x[0] = x0
    for i in range(n - 1):
        h = t[i + 1] - t[i]
        x[i+1] = x[i] + h * f(x[i] + 0.5 * h * f(x[i], t[i]), t[i] + 0.5 * h)
    return x
