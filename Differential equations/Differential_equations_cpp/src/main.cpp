#include "Metody_rozw.h"
#include "FunkcjePomocnicze.h"
///------------------

int main() {
    /// VARIABLES
    long double a = 0.0;
    long double b = 300;
    int n = 100;
    long double x0 = 1200;
    vector<long double> linspace(n);
    for (int i = 0; i < n; i++)
        linspace[i] = a + i * (b - a) / (n - 1);

    /// EULER:
    vector<long double> result1 = Euler(rownanie_2, x0, linspace);
    wypisz(linspace,result1,x0,a,b);
    rozdziel();
    /// RUNGE_KUTTY:
    vector<long double> result2 = RungeKutta(rownanie_2, x0, linspace);
    wypisz(linspace,result2,x0,a,b);
    rozdziel();
    /// MID_POINT:
    vector<long double> result3 = Midpoint(rownanie_2, x0, linspace);
    wypisz(linspace,result3,x0,a,b);
    /// MODIFIED_EULER:
    vector<long double> result4 = ModifiedEuler(rownanie_2, x0, linspace);
    wypisz(linspace,result4,x0,a,b);
    /// HEUN:
    vector<long double> result5 = Heun(rownanie_2, x0, linspace);
    wypisz(linspace,result5,x0,a,b);

    return 0;
}
