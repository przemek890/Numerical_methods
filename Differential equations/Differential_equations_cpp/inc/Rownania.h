#ifndef DIFFERENTIAL_EQUATIONS_ROWNANIA_H
#define DIFFERENTIAL_EQUATIONS_ROWNANIA_H
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;
///-------------------

auto rownanie_1 = [](long double x, long double t) { return -pow(10,-12) * pow(x,4); };
auto rownanie_2 = [](long double x, long double t) { return -pow(10,-12) * pow(x,4); };
#endif //DIFFERENTIAL_EQUATIONS_ROWNANIA_H
