#include "Hermitea.h"
//----------------------

int main() {
    int m = 7;              // wymiar przestrzeni

    vector<vector<double>> baza_standardowa5;
    vector<vector<double>> baza5 = wielomiany_hermitea(baza_standardowa5,m);

    rozdziel();

    cout << "Wielomiany Hermite'a: " << endl;
    print_matrix_transposed(baza5,6);


    return 0;
}


