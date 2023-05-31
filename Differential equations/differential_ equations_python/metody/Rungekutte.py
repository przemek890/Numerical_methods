import numpy as np
"""METODA RUNGEKUTTA:"""
def Rungekutta(f, x0, t, ):
    n = len(t)
    x = np.zeros((n, len(x0)))
    x[0] = x0
    for i in range(n - 1):
        h = t[i+1] - t[i]
        k1 = f(x[i], t[i])
        k2 = f(x[i] + k1 * h / 2., t[i] + h / 2.)
        k3 = f(x[i] + k2 * h / 2., t[i] + h / 2.)
        k4 = f(x[i] + k3 * h, t[i] + h)
        x[i+1] = x[i] + (h / 6.) * (k1 + 2*k2 + 2*k3 + k4)
    return x