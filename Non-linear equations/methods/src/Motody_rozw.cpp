#include "Metody_rozw.h"
///---------------------
double derivative(double (*f)(double), double x) {
    double h = 0.0001;
    return (f(x + h) - f(x)) / h;
}
double MetodaStycznychNewtona1(double (*deriv)(double),double (*f)(double), double x0, double epsilon, int maxIteracji,int pom,Solutions& rozwiazania) {
    double x = x0;
    rozwiazania.MetodaStycznychNewtona1[pom].push_back(x);

    for (int i = 0; i < maxIteracji; i++) {
        double fx = f(x);
        double dfx = deriv(x);

        double deltaX = fx / dfx;                      /// Obliczanie nowego przybliżenia
        x = x - deltaX;
        rozwiazania.MetodaStycznychNewtona1[pom].push_back(x);

        if (std::abs(deltaX) < epsilon) {      /// Sprawdzenie warunku zakończenia iteracji
            break;
        }
    }
    return x;
}
double MetodaStycznychNewtona2(double (*f)(double), double x0, double epsilon, int maxIteracji,int pom,Solutions& rozwiazania) {
    double x = x0;
    rozwiazania.MetodaStycznychNewtona2[pom].push_back(x);

    for (int i = 0; i < maxIteracji; i++) {
        double fx = f(x);
        double dfx = derivative(f, x);

        double deltaX = fx / dfx;                      /// Obliczanie nowego przybliżenia
        x = x - deltaX;
        rozwiazania.MetodaStycznychNewtona2[pom].push_back(x);

        if (std::abs(deltaX) < epsilon) {      /// Sprawdzenie warunku zakończenia iteracji
            break;
        }
    }

    return x;
}
double MetodaSiecznych(double (*f)(double),double x0, double x1, double epsilon, int maxIteracji,int pom,Solutions& rozwiazania) {
    double x_prev = x0;
    double x = x1;
    rozwiazania.MetodaSiecznych[pom].push_back(x);

    for (int i = 0; i < maxIteracji; i++) {
        double fx_prev = f(x_prev);
        double fx = f(x);

        double deltaX = (fx * (x_prev - x)) / (fx_prev - fx);   /// Obliczanie nowego przybliżenia
        x_prev = x;
        x = x - deltaX;
        rozwiazania.MetodaSiecznych[pom].push_back(x);

        if (std::abs(deltaX) < epsilon) {               /// Sprawdzenie warunku zakończenia iteracji
            break;
        }
    }

    return x;
}
double RegulaFalsi(double (*f)(double),double a, double b, double epsilon, int maxIteracji,int pom,Solutions& rozwiazania) {
    double fa = f(a);
    double fb = f(b);

    if (fa * fb >= 0) {
        cout << "Nie można znaleźć pierwiastka w przedziale [a,b]" << endl;
        return NAN; // Zwracamy NaN w przypadku błędu
    }

    for (int i = 0; i < maxIteracji; i++) {
        double c = (a * fb - b * fa) / (fb - fa);
        rozwiazania.RegulaFalsi[pom].push_back(c);
        double fc = f(c);

        if (std::abs(fc) < epsilon) {               /// Znaleziono rozwiązanie z zadaną dokładnością
            return c;
        }

        if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }

    std::cout << "Nie osiągnięto zadanego poziomu dokładności." << std::endl;
    return NAN; /// Nie osiągnięto zadanego poziomu dokładności
}
double Bisekcja(double (*f)(double), double a, double b, double epsilon,int pom,Solutions& rozwiazania) {
    if (f(a) * f(b) >= 0) {
        cout << "Nie można znaleźć pierwiastka w przedziale [a,b]" << endl;
        return NAN;
    }


    double c = a;
    rozwiazania.Bisekcja[pom].push_back(c);
    while ((b - a) >= epsilon) {
        c = (a + b) / 2;                          /// Oblicz środek przedziału
        rozwiazania.Bisekcja[pom].push_back(c);
        if (f(c) == 0.0) break;                  /// Znaleziono dokładny pierwiastek
        else if (f(c) * f(a) < 0) b = c;        /// Przesuń prawą granicę przedziału
        else a = c;                            /// Przesuń lewą granicę przedziału
    }

    return c;
}