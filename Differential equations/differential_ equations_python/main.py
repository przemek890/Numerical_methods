import matplotlib.pyplot as plt
import pandas as pd
from scipy.integrate import odeint
import numpy as np

import metody.Euler as eu
import metody.Taylor as tl
import metody.Midpoint as mid
import metody.Rungekutte as rk
import metody.Heun as hn
import metody.Modify_euler as modeu
"""-----------------------------------------------------"""
"""RÓWNANIE - x' = f(x(t),t) ORAZ WARUNKI POCZATKOWE"""
equation = lambda x,t:  -10**(-12) * x**4                                                               # Zdefiniowanie równania (postać obliczeniowa)
equation_s = lambda x,t:  -10**(-12) * x**4                                                             # Zdefiniowanie równania (postać symboliczna - sympy)
a,b = 0,300                                                                                             # Przedział: [a,b]
n = 1000                                                                                                 # Liczba równoodleglych probek
x0 = 1200                                                                                               # x(t) = x0
t1 = np.linspace(a, b, n)                                                                               # t
print("Numeryczne rozwiązanie równania: x' = f(x(t),t), x(t)={} na przedziale [{},{}]".format(x0,a,b))
"""-----------------------------------------------------"""


"""ROZWIAZANIE:"""
sol_0 = odeint(equation, [x0], t1)                                                                      # Rozwiązanie dokładne równania w punktach --> podziału t1
sol_1 = eu.Euler(equation, [x0], t1)                                                                    # Rozwiązanie metodą Eulera w punktach --> podziału t1
sol_2 = mid.Midpoint(equation, [x0], t1)                                                                # Rozwiązanie metoda Midpoint w punktach --> podziału t1
sol_3 = rk.Rungekutta(equation, [x0], t1)                                                               # Rozwiązanie metoda rungekutta4 w --> punktach podziału t1
sol_4 = tl.Taylor(equation,tl.k_deriv(equation_s,1),tl.k_deriv(equation_s,2),[x0],t1)                   # Rozwiązanie metoda Taylor w --> punktach podziału t1
sol_5 = hn.Heun(equation, [x0], t1)
sol_6 = modeu.Mod_Euler(equation, [x0], t1)
print("WYNIK_0: ",sol_0[n-1])
print("WYNIK_1: ",sol_1[n-1])
print("WYNIK_2: ",sol_2[n-1])
print("WYNIK_3: ",sol_3[n-1])
print("WYNIK_4: ",sol_4[n-1])
print("WYNIK_5: ",sol_5[n-1])
print("WYNIK_6: ",sol_6[n-1])

"""WYKRES:"""
def wykres():
    plt.plot(t1, sol_0[:, 0], 'blue',  label=r'$Exact$')
    plt.plot(t1, sol_1[:, 0], 'red',   label=r'$Eulera$')
    plt.plot(t1, sol_2[:, 0], 'green', label=r'$Midpoint$')
    plt.plot(t1, sol_3[:, 0], 'yellow',label=r'$Rungekutta$')
    plt.plot(t1, sol_4[:, 0], 'violet', label=r'$Taylor$')
    plt.plot(t1, sol_5[:, 0], 'black', label=r'$Heun$')
    plt.plot(t1, sol_6[:, 0], 'gray', label=r'$ModifyEuler$')
    plt.legend(loc='best')
    plt.title("Numerical Solution: x' = f(x(t),t)")
    plt.xlabel('t')
    plt.ylabel('x')

    plt.grid()
    plt.show()
wykres()

"""ANALIZA WYNIKÓW:"""
dane = {'t': t1, 'Exact': sol_0[:, 0], 'Euler': sol_1[:, 0], 'Midpoint': sol_2[:, 0], 'Rungekutta': sol_3[:, 0],
        'Taylor': sol_4[:, 0],'Heun': sol_5[:, 0],'ModifyEuler': sol_6[:, 0]}
Data_Frame = pd.DataFrame(dane)
print("DANE:\n",Data_Frame) # .to_string()

"""ANALIZA BŁĘDÓW:"""
b_0=max(abs(sol_0[:, 0] - sol_0[:, 0]))
b_1=max(abs(sol_0[:, 0] - sol_1[:, 0]))
b_2=max(abs(sol_0[:, 0] - sol_2[:, 0]))
b_3=max(abs(sol_0[:, 0] - sol_3[:, 0]))
b_4=max(abs(sol_0[:, 0] - sol_4[:, 0]))
b_5=max(abs(sol_0[:, 0] - sol_5[:, 0]))
b_6=max(abs(sol_0[:, 0] - sol_6[:, 0]))
Blad = {'Metoda':['Exact','Eulera','Midpoint','Rungekutta4','Taylor','Heun','ModifyEuler'], 'Błąd globalny': [b_0,b_1,b_2,b_3,b_4,b_5,b_6]}
print ("BŁĄD GLOBALNY:\n",pd.DataFrame(Blad))

"""Wynik:"""


