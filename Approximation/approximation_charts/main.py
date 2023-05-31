import matplotlib.pyplot as plt
import numpy as np

def f(x):
    return np.sin(x)

def stworz_wykres_z_pliku(nazwa_pliku):
    with open(nazwa_pliku, 'r') as file:
        data = file.readlines()
    x = []
    y = []
    for line in data:
        row = line.split()
        x.append(float(row[0]))
        y.append(float(row[1]))

    poly = np.poly1d(y[::-1])
    x_axis = np.linspace(-10, 10, 1000)
    plt.plot(x_axis, poly(x_axis), label='Funkcja aproksymujaca')

def stworz_wykres_funkcji(f):
    x = np.linspace(-4 * np.pi, 4 * np.pi, 1000)
    y = f(x)
    plt.plot(x, y, label='Funkcja aproksymowana')

def dodaj_punkty_do_wykresu(nazwa_pliku):
    with open(nazwa_pliku, 'r') as file:
        data = file.readlines()

    # Przetworzenie punktów
    p_x = []
    p_y = []
    for line in data:
        row = line.split()
        p_x.append(float(row[0]))
        p_y.append(float(row[1]))
    plt.scatter(p_x, p_y, marker='x', color='black', label='Punkty', zorder=3)

def inicjacja(x_p,x_k,y_p,y_k):
    plt.title("Aproksymacja średniokwadratowa")
    plt.axvline(x=0, color='black', lw=1)
    plt.axhline(y=0, color='black', lw=1)
    plt.xlabel('x')
    plt.ylabel('y')
    plt.xlim(x_p,x_k)
    plt.ylim(y_p, y_k)
    plt.grid()

    plt.arrow(0, 0, x_k - (abs(x_k - x_p) / 60), 0, head_width=0.1, head_length=0.3, fc='k', ec='k')
    plt.arrow(0, 0, 0,   y_k - (abs(y_k - y_p) / 40), head_width=0.3, head_length=0.1, fc='k', ec='k')

def finalizacja():
    plt.legend(loc='upper right')
    plt.show()


inicjacja(-10,10,-2,2)
stworz_wykres_funkcji(f)
stworz_wykres_z_pliku("wspolczynniki.txt")
dodaj_punkty_do_wykresu("punkty.txt")
finalizacja()


