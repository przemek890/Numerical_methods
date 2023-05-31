import matplotlib.pyplot as plt

def stworz_wykres_z_pliku(nazwa_pliku, nazwa_metody):
    with open(nazwa_pliku, 'r') as file:
        data = file.readlines()
    x = []
    t = []
    for line in data:
        row = line.split()
        x.append(float(row[0]))
        t.append(float(row[1]))

    plt.plot(t, x, label="{}".format(nazwa_metody))

def inicjacja(x_p, x_k, y_p, y_k):
    plt.title("Numeryczne rozwiazywanie rownan rozniczkowych")
    plt.axvline(x=0, color='black', lw=1)
    plt.axhline(y=0, color='black', lw=1)
    plt.xlabel('t')
    plt.ylabel('x(t)')
    plt.xlim(x_p, x_k)
    plt.ylim(y_p, y_k)
    plt.grid()

def finalizacja():
    plt.legend(loc='best')
    plt.show()


inicjacja(1., 2.0, 0.8, 1.0)
stworz_wykres_z_pliku("punkty1.txt", "Metoda Eulera")
stworz_wykres_z_pliku("punkty2.txt", "Metoda Runge Kutte")
stworz_wykres_z_pliku("punkty3.txt", "Metoda Midpoint")
stworz_wykres_z_pliku("punkty4.txt", "ModifiedEuler")
stworz_wykres_z_pliku("punkty5.txt", "Heun")

finalizacja()

