#include "Metody_rozw.h"
// Metoda Eulera:
vector<long double> Euler(long double (*f)(long double, long double), long double x0, vector<long double> t) {
    int n = t.size();
    vector<long double> x(n);
    x[0] = x0;
    for (int i = 0; i < n - 1; i++) {
        long double h = t[i + 1] - t[i];
        x[i + 1] = x[i] + h * f(x[i],t[i]);
    }
    return x;
}
// Metoda Heuna:
vector<long double> Heun(long double (*f)(long double, long double), long double x0, vector<long double> t) {
    int n = t.size();
    vector<long double> x(n);
    x[0] = x0;
    for (int i = 0; i < n - 1; i++) {
        long double h = t[i + 1] - t[i];
        x[i + 1] = x[i] + 0.5 * h * (f(x[i], t[i]) + f(x[i] + h * f(x[i], t[i]), t[i] + h));
    }
    return x;
}
// Metoda Rungego-Kutty
vector<long double> RungeKutta(long double (*f)(long double, long double), long double x0, vector<long double> t) {
    int n = t.size();
    vector<long double> x(n);
    x[0] = x0;
    for (int i = 0; i < n - 1; i++) {
        long double h = t[i + 1] - t[i];
        long double k1 = f(x[i], t[i]);
        long double k2 = f(x[i] + k1 * h / 2.0, t[i] + h / 2.0);
        long double k3 = f(x[i] + k2 * h / 2.0, t[i] + h / 2.0);
        long double k4 = f(x[i] + k3 * h, t[i] + h);
        x[i + 1] = x[i] + (h / 6.0) * (k1 + 2.0 * k2 + 2.0 * k3 + k4);
    }
    return x;
}
// Metoda Midpoint
vector<long double> Midpoint(long double (*f)(long double, long double), long double x0, vector<long double> t) {
    int n = t.size();
    vector<long double> x(n);
    x[0] = x0;
    for (int i = 0; i < n - 1; i++) {
        long double h = t[i + 1] - t[i];
        long double k1 = f(x[i], t[i]);
        long double k2 = f(x[i] + k1 * h / 2.0, t[i] + h / 2.0);
        x[i + 1] = x[i] + k2 * h;
    }
    return x;
}
// Metoda ModEuler:
vector<long double> ModifiedEuler(long double (*f)(long double, long double), long double x0, vector<long double> t) {
    int n = t.size();
    vector<long double> x(n);
    x[0] = x0;
    for (int i = 0; i < n - 1; i++) {
        long double h = t[i + 1] - t[i];
        x[i + 1] = x[i] + h * f(x[i] + 0.5 * h * f(x[i], t[i]), t[i] + 0.5 * h);
    }
    return x;
}