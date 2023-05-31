#include "equations.h"
double drgania_tlumione(double x) {
    double a = 0.5;
    double b = -0.33;
    return a*exp(b*x);
};
double funkcja_1(double x) {
    return pow(x,2) * pow(sin(x),3);
}
double funkcja_2(double x) {
    return exp(pow(x,2)) * (x-1);
}
double funkcja_3(double x){
    return sin(x)/x;
}
double funkcja_4(double x) {
    double pom = 1.0/(1.0-x);
    return sin(pom);
}
double funkcja_5(double x) {
    return pow(x,x);
}