import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
import numpy as np
from scipy.optimize import root
#-------------------------------
rownanie_1 = lambda x: x**3 + x**2 - 3*x - 3
rownanie_2 = lambda x: x**2 - 2
rownanie_3 = lambda x: np.sin(x**2) - x**2
rownanie_4 = lambda x: np.sin(x**2) - x**2 + 0.5

x0_1 = root(rownanie_1, x0=2)
x0_2 = root(rownanie_2, x0=2)
x0_3 = root(rownanie_3, x0=2)
x0_4 = root(rownanie_4, x0=2)

sciezka1 = "./exel/1.xlsx"
sciezka2 = "./exel/2.xlsx"
sciezka3 = "./exel/3.xlsx"
sciezka4 = "./exel/4.xlsx"
sciezka5 = "./exel/5.xlsx"

metoda1 = "Metoda stycznych - Newtona (analitycznie)"
metoda2 = "Metoda stycznych - Newtona (numerycznie)"
metoda3 = "Metoda siecznych"
metoda4 = "Regula falsi"
metoda5 = "Metoda bisekcji"
#-------------------------------

def wykres(df,metoda):
    sns.set_style('dark')

    fig, axes = plt.subplots(4, 1, figsize=(10, 20))

    # Wykres 1
    sns.scatterplot(data=df, x='l.p', y=abs(df['equation_1'] - x0_1.x[0]), color='red', marker='x', ax=axes[0],s=100)
    axes[0].set_xlabel('L.p')
    axes[0].set_ylabel('Różnica bezwzględna')
    axes[0].set_title('{} - równanie_1'.format(metoda))
    axes[0].axhline(y=0, color='black', linewidth=0.5)
    axes[0].axvline(x=0, color='black', linewidth=0.5)

    # Wykres 2
    sns.scatterplot(data=df, x='l.p', y=abs(df['equation_2'] - x0_2.x[0]), color='red', marker='x', ax=axes[1],s=100)
    axes[1].set_xlabel('L.p')
    axes[1].set_ylabel('Różnica bezwzględna')
    axes[1].set_title('{} - równanie_2'.format(metoda))

    # Wykres 3
    sns.scatterplot(data=df, x='l.p', y=abs(df['equation_3'] - x0_3.x[0]), color='red', marker='x', ax=axes[2],s=100)
    axes[2].set_xlabel('L.p')
    axes[2].set_ylabel('Różnica bezwzględna')
    axes[2].set_title('{} - równanie_3'.format(metoda))

    # Wykres 4
    sns.scatterplot(data=df, x='l.p', y=abs(df['equation_4'] - x0_4.x[0]), color='red', marker='x', ax=axes[3],s=100)
    axes[3].set_xlabel('L.p')
    axes[3].set_ylabel('Różnica bezwzględna')
    axes[3].set_title('{} - równanie_4'.format(metoda))

    plt.tight_layout()
    plt.show()
def tabela(sciezka,metoda):
    print("{}".format(metoda))
    df = pd.read_excel(sciezka)
    print(df.fillna("-").to_string(index=False))
    return df
df1 = tabela(sciezka1,metoda1)
df2 = tabela(sciezka2,metoda2)
df3 = tabela(sciezka3,metoda3)
df4 = tabela(sciezka4,metoda4)
df5 = tabela(sciezka5,metoda5)

wykres(df1,metoda1)
wykres(df2,metoda2)
wykres(df3,metoda3)
wykres(df4,metoda4)
wykres(df5,metoda5)

