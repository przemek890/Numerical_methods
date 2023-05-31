#ifndef DIFFERENTIAL_EQUATIONS_METODY_H
#define DIFFERENTIAL_EQUATIONS_METODY_H
#include "Rownania.h"
/// ------------------------------------
vector<long double> Euler(long double (*f)(long double, long double), long double x0, vector<long double> t);
vector<long double> Heun(long double (*f)(long double, long double), long double x0, vector<long double> t);
vector<long double> RungeKutta(long double (*f)(long double, long double), long double x0, vector<long double> t);
vector<long double> Midpoint(long double (*f)(long double, long double), long double x0, vector<long double> t);
vector<long double> ModifiedEuler(long double (*f)(long double, long double), long double x0, vector<long double> t);
#endif //DIFFERENTIAL_EQUATIONS_METODY_H
