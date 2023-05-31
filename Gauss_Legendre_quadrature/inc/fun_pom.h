#ifndef GAUSS_3_FUN_POM_H
#define GAUSS_3_FUN_POM_H
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
///----------------------
vector<double> nth_derivative(vector<double> a, int n);
vector<double> trojkat_pascala(int n);
void zmien_znak(vector<double>& wsp);
std::vector<double> dodawanie_zer(std::vector<double>& wsp);
int silnia(int n);
void rozdziel();

double Gausse_lagendre(double (*f)(double),double a, double b, int n);
double Wielomian_Lagrange(int n);
#endif //GAUSS_3_FUN_POM_H
