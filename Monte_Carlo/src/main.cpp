#include "methods.h"
int main() {
    double a = 0.0;
    double b = 1.0;
    int n = 1000000;

    double result = monte_carlo_integration(f_1,a, b, n);
    cout << "Wynik: " << result << endl;

    return 0;
}
