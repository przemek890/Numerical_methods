#ifndef DIFFERENTIAL_EQUATIONS_ROWNANIA_H
#define DIFFERENTIAL_EQUATIONS_ROWNANIA_H
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
using namespace std;
///-------------------

auto rownanie_1 = [](double x) { return pow(x,3) + pow(x,2) - 3*x -3;};
auto rownanie_2 = [](double x) { return pow(x,2)-2;};
auto rownanie_3 = [](double x) { return sin(pow(x,2)) - pow(x,2);};
auto rownanie_4 = [](double x) { return sin(pow(x,2)) - pow(x,2) + 0.5;};

auto poch_1 = [](double x) { return 3 * pow(x,2) + 2*x - 3;};
auto poch_2 = [](double x) { return 2*x;};
auto poch_3 = [](double x) { return 2*x*cos(pow(x,2)) -2*x;};
auto poch_4 = [](double x) { return 2*x*cos(pow(x,2)) -2*x;};
#endif //DIFFERENTIAL_EQUATIONS_ROWNANIA_H
