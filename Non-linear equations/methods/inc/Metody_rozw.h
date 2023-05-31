#ifndef DIFFERENTIAL_EQUATIONS_METODY_H
#define DIFFERENTIAL_EQUATIONS_METODY_H
#include <vector>
#include <iostream>
using namespace std;
/// -----------------------------------
struct Solutions{
    vector<double> MetodaStycznychNewtona1[4];
    vector<double> MetodaStycznychNewtona2[4];
    vector<double> MetodaSiecznych[4];
    vector<double> RegulaFalsi[4];
    vector<double> Bisekcja[4];
};
// ----------
double derivative(double (*f)(double), double x);
double MetodaStycznychNewtona1(double (*deriv)(double),double (*f)(double), double x0, double epsilon, int maxIteracji,int pom,Solutions& rozwiazania);
double MetodaStycznychNewtona2(double (*f)(double), double x0, double epsilon, int maxIteracji,int pom,Solutions& rozwiazania);
double MetodaSiecznych(double (*f)(double),double x0, double x1, double epsilon, int maxIteracji,int pom,Solutions& rozwiazania);
double RegulaFalsi(double (*f)(double),double a, double b, double epsilon, int maxIteracji,int pom,Solutions& rozwiazania);
double Bisekcja(double (*f)(double), double a, double b, double epsilon,int pom,Solutions& rozwiazania);
#endif //DIFFERENTIAL_EQUATIONS_METODY_H
