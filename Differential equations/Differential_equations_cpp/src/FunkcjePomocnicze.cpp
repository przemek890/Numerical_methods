#include "FunkcjePomocnicze.h"
void wypisz(const vector<long double>& linspace, const vector<long double>& result, long double x0, long double a, long double b) {
    cout << "Numeryczne rozwiązanie równania: x' = f(x(t),t), x(t)=" << x0 << " na przedziale [" << a << "," << b << "]" << endl;
    cout << setw(12) << "x(t)" << setw(12) << "t" << endl;
    for (int i = 0; i < linspace.size(); i++) {
        cout << setw(12) << result[i] << setw(12) << linspace[i] << endl;
    }
}
void rozdziel(){
    cout << " - - - - - - - - - - - - " << endl;
}
