#include "quadratures.h"
double horner(double x,vector<double>& a) {
    double result = a.front();
    for (int i = 1; i < a.size(); i++)
        result = result * x + a[i];
    return result;
}
double metoda_prostokatow(double(*f)(double), double a, double b, int n)
{
    double h = (b - a)/static_cast<double>(n); // szerokosc prostokata
    double suma = 0.0;
    double srodek;
    srodek = a + (h / 2.0);  // srodek pierwszego prostokata

    for(int i=0;i<n;i++)
    {
        suma += f(srodek) * h;
        srodek += h;
    }
    return suma;
}
double metoda_trapezow(double(*f)(double), double a, double b, int n) {
    double h = (b - a) / n; // szerokość każdego trapezu
    double suma = 0.5 * (f(a) + f(b)); // Podstawa f(a) i f(b) nie powtarzaja sie jedyne 2 razy

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        suma += f(x);                  // sumujemy podstawy zgodnie z wzorem z wykipedii :P
    }

    return h * suma; // wysokosc jest taka sama dla wszystkich trapezow (została wyciągnieta przed nawias z wzoru na pole trapezu)
}
double newton_cotes_trapez(double(*f)(double),double a, double b, int n) {
    /// h - odleglosc miedzypodstawami: (x2 - x1)
    // Metoda bliźniacza do tej wyżej (trapezów) lecz tu odrazu liczymy pola trapezów (pojedyńczo)
    double h = (b - a)/static_cast<double>(n); // szerokosc prostokata

    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double x1;
        double x2;
        x1 = a + i * h;          // a
        x2 = a + (i + 1) * h;    // b

        sum += (h / 2.0) * (f(x1) + f(x2));
    }
    return sum;
}
double newton_cotes_simpson(double(*f)(double),double a, double b, int n) {
    /// h - odleglosc miedzypodstawami: (x2 - x1)
    double h = (b - a)/static_cast<double>(n); // szerokosc prostokata
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double x1;
        double x2;
        double x3;
        x1 = a + i * h;          // a
        x2  = a + (i + 1) * h;    // (a+b) / 2
        x3 = a + (i + 0.5) * h;  // b

        sum += (h / 6.0) * (f(x1) + 4.0 * f(x3) + f(x2));
    }
    return sum;
}
double trapez_wielomian(vector<double>& wsp, double a, double b,int n) {
    /// h - odleglosc miedzypodstawami: (x2 - x1)
    double h =(b - a)/static_cast<double>(n); // szerokosc prostokata
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double x1 = a + i * h;          // a
        double x2 = a + (i + 1) * h;    // b
        sum += (h / 2.0) * (horner(x1,wsp) + horner(x2,wsp));
    }
    return sum;
}
double simpson_wielomian(vector<double>& wsp, double a, double b,int n) {
    /// h - odleglosc miedzypodstawami: (x2 - x1)
    double h = (b - a)/static_cast<double>(n); // szerokosc prostokata
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double x1 = a + i * h;          // a
        double x2 = a + (i + 1) * h;    // (a+b) / 2
        double x3 = a + (i + 0.5) * h;  // b
        sum += (h / 6.0) * (horner(x1,wsp)  + 4.0 * horner(x3,wsp)  + horner(x2,wsp) );
    }
    return sum;
}
double rectangle_wielomian(vector<double>& wsp, double a, double b, int n)
{
    double h = (b - a)/static_cast<double>(n); // szerokosc prostokata
    double suma = 0.0;
    double srodek = a + (h / 2.0);  // srodek pierwszego prostokata

    for(int i=0;i<n;i++)
    {
        suma += horner(srodek,wsp) * h;
        srodek += h;
    }
    return suma;
}
void rozdziel() {
    cout << "- - - - - - - - - - - - - - -" << endl;
}