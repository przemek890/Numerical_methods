import numpy as np
import matplotlib.pyplot as plt

nazwa1 = "plik1.txt"
nazwa2 = "plik2.txt"

a1 , b1 = -1 , 1

a2 , b2 = 0 , 1

def wykres(nazwa_pliku,a,b):
    # Wczytanie danych z pliku
    data = np.loadtxt(nazwa_pliku).T

    # Utworzenie funkcji rysującej wykres danego wielomianu
    def plot_polynomial(coeffs):
        x = np.linspace(-10, 10, 1000)  # Zmiana zakresu osi x
        y = np.zeros_like(x)          # Inicjalizacja tablicy wartości funkcji
        for i, c in enumerate(coeffs):
            y += c * x ** (len(coeffs) - i - 1)  # Wyznaczenie wartości funkcji
        plt.plot(x, y)


    # Rysowanie wykresów
    plt.axvline(x=0, color='black', lw=1)
    plt.axhline(y=0, color='black', lw=1)
    plt.arrow(-1, 0, 2, 0, length_includes_head=True, head_width=0.03)
    plt.arrow(0, -1, 0, 2, length_includes_head=True, head_width=0.03)

    for i in range(data.shape[0]):
        plot_polynomial(data[i])

    # Dodanie tytułu i etykiet osi
    plt.title('Wielomiany ortogonalne -> ({}:{})'.format(a,b))
    plt.xlabel('x')
    plt.ylabel('y')

    # Dodanie siatki kwadratowej z tyłu wykresu oraz zmiana zakresu osi x i y
    plt.grid(True, which='both', color='gray', alpha=0.3)
    plt.xticks(np.arange(-10, 11, 0.5))
    plt.yticks(np.arange(-10, 11, 0.1))
    plt.xlim(-1, 1)
    plt.ylim(-1, 1)

    # Wyświetlenie wykresów
    plt.show()

wykres(nazwa1,a1,b1)
wykres(nazwa2,a2,b2)