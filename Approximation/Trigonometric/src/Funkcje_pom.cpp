#include "Funkcje_pom.h"
double f(double x) {
    return pow(M_E,x) * sin(x) * cos(x);
}
void aprox_trigonometric(vector<double> x, vector<double> y, int k, int n) {
    vector<double> aa(k+1), bb(k+1);
    aa[0] = 0;
    for (int i = 0; i < n; i++)
        aa[0] += y[i];
    aa[0] /= n;

    for (int l = 1; l <= k; l++) {
        aa[l] = bb[l] = 0;
        for (int i = 0; i < n; i++) {
            aa[l] += y[i] * cos(l * x[i]);
            bb[l] += y[i] * sin(l * x[i]);
        }
        aa[l] *= 2.0 / n;
        bb[l] *= 2.0 / n;
    }

    cout << "Współczynniki: " << endl;
    cout << setw(2) << "k" << setw(15) << "a" << setw(15) << "b" << endl;
    for (int l = 0; l <= k; l++)
        cout << setw(2) << l << setw(15) << aa[l] << setw(15) << bb[l] << endl;

    cout << endl << endl;

    cout << "Wygenerowane punkty: " << endl;
    cout << setw(2) << "i" << setw(12) << "x" << setw(15) << "f(x)" << endl;
    for (int i = 0; i < n; i++) {
        cout << setw(2) << i << setw(12) << x[i] << setw(15) << y[i] << endl;
    }
}