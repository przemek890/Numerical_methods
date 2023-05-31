#include "Funkcje_pom.h"
//----------------------

int main() {
    int k = 5;          // stopień wielomianu aproksymującego: ..., sin(kx) , cos(kx)
    double a = -M_PI;   // początek generowania punktów
    double b = M_PI;    // koniec generowania punktów
    int n = 10;       // liczba wygenerowanych punktów

    vector<double> x(n);
    vector<double> y(n);

    for(int i = 0; i < n; i++) {
        x[i] = a + (b-a) * i / (n-1);
        y[i] = f(x[i]);
    }

    aprox_trigonometric(x,y,k,n);

    return 0;
}






