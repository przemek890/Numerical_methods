#ifndef HORNER_SCHEME_AND_INTERPOLATION_METHODS_H
#define HORNER_SCHEME_AND_INTERPOLATION_METHODS_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>
using namespace std;
///----------------------------------------------
double monte_carlo_integration( double (*func)(double), double a, double b, int n);
double f_1(double x);

void rozdziel();

#endif //HORNER_SCHEME_AND_INTERPOLATION_METHODS_H
