#ifndef GAUSS_3_FUNCTIONS_H
#define GAUSS_3_FUNCTIONS_H
#include <cmath>
/// --------------------- Funkcje:
auto f_1 = [](double x) { return pow(x,2) * pow(sin(x),3); };
auto f_2 = [](double x) { return exp(pow(x,2)) * (x-1); };
auto f_3 = [](double x) { return 55-2*x-6*pow(x,2)+5*pow(x,3) +0.4*pow(x,4);};
auto f_4 = [](double x) { return 1-2*exp(x)-6*cos(x);};
auto f_5 = [](double x) { return sin(1-x)/(1-x); };
auto f_6 = [](double x) { return sin(1/(1-x));};
auto f_7 = [](double x) { return sin(x)/x; };
#endif //GAUSS_3_FUNCTIONS_H
