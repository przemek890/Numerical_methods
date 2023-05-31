#include "methods.h"
///-----------------
double monte_carlo_integration( double (*func)(double), double a, double b, int n) {
    double sum = 0.0;

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        double x = a + (double) rand() / RAND_MAX * (b - a);
        sum += func(x);
    }

    double avg = sum / n;
    double integral = avg * (b - a);

    return integral;
}
double f_1(double x) {
    return sin(x);
}
void rozdziel() {
    cout << "- - - - - - - - - - - - - - -" << endl;
}