#include "Aproksymacja.h"
//----------------------

/// Funkcja aproksymowana
double f(double x) {
    return sin(-x) + exp(-x) - pow(x,3);
}

int main() {
    int m = 5;              // wymiar przestrzeni
    int n = 3000;           // liczba przedzialow calkowania
    double a1 =  0, b1 = 1; // granice calkowania 2
    //---------------------

    /// Gram-Schmidta:
    vector<vector<double>> baza_standardowa1 = generateBasisStandard(m);                          /// a[0]x^n + a[1]n^(n-1) + ....
    vector<vector<double>> baza1 = Gram_Schmidt_wiel(baza_standardowa1,a1,b1,n);        /// ortogonalizacja

    /// Reguła Trójczłonowa:
    vector<vector<double>> baza_standardowa2;
    vector<vector<double>> baza2 = regula_trojczlonowa(baza_standardowa2,m,a1,b1,n);

    ///-----------------------------------NORMALIZACJA-------------------------------------------
    normalizacja_wiel(baza1 ,a1,b1,n);   /// ortonormalizacja bazy_1
    normalizacja_wiel(baza2 ,a1,b1,n);   /// ortonormalizacja bazy_2
    ///--------------------------------------------------------------------------------------------

    cout << "Baza ortonormalna - Gram-Schmidta (0:1): " << endl;
    print_matrix_transposed(baza1,6);
    rozdziel();
    cout << "Baza ortonormalna - Reguła-Trójczłonowa (0:1): " << endl;
    print_matrix_transposed(baza2,6);
    rozdziel();
    cout << "Metoda najmniejszych kwadratow - Gram-Schmidt\n" << endl;
    print_vector_transposed(metoda_najmniejszych_kwadratow(baza1,f,a1,b1,n));
    cout << "Metoda najmniejszych kwadratow - Trójczłonowa\n" << endl;
    print_vector_transposed(metoda_najmniejszych_kwadratow(baza2,f,a1,b1,n));


    return 0;
}


