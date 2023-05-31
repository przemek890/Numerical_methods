#ifndef GAUSS_LEGENDRE_QUADRATURE_QUADRATURES_H
#define GAUSS_LEGENDRE_QUADRATURE_QUADRATURES_H
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
///-----------------------------
double horner(double x,vector<double>& a);
double metoda_prostokatow(double(*f)(double), double a, double b, int n);
double metoda_trapezow(double(*f)(double), double a, double b, int n);
double newton_cotes_trapez(double(*f)(double),double a, double b, int n);
double newton_cotes_simpson(double(*f)(double),double a, double b, int n);
double trapez_wielomian(vector<double>& wsp, double a, double b,int n);
double simpson_wielomian(vector<double>& wsp, double a, double b,int n);
double rectangle_wielomian(vector<double>& wsp, double a, double b, int n);

void rozdziel();

#endif //GAUSS_LEGENDRE_QUADRATURE_QUADRATURES_H
