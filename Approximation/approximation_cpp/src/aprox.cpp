#include "Funkcje_pom.h"
//----------------------

int main() {
    int n = 5;          /// stopień wielomianu aproksymującego
    double a = -6.0;    /// początek generowania punktów
    double b = 3.0;     /// koniec generowania punktów
    int k = 10;         /// liczba wygenerowanych punktów

    vector<double> x;
    vector<double> y;

    for(double i = a;i<=b;i += (b-a)/k) {
        x.push_back(i);
        y.push_back(f(i));
    }

    vector<double> wsp = metoda_najmniejszych_kwadratow(x,y,n);

    print_values(f,wsp,n,x);
    return 0;
}








