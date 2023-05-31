import numpy as np
"""METODA MIDPOINT:"""
def Midpoint(f, x0, t):
    n = len(t)
    x = np.zeros((n, len(x0)))
    x[0] = x0
    for i in range(n - 1):
        h = t[i + 1] - t[i]
        k1 = f(x[i], t[i])
        k2 = f(x[i] + k1 * h / 2., t[i] + h / 2.)
        x[i + 1] = x[i] + k2 * h
    return x