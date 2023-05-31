#include "Gram_Schmidt.h"
//----------------------

/////////////////////////////////
// Jeżeli wektory bazowe są zależne od siebie w danej przestrzeni liniowej (z okreslonym iloczynem skalarnym)
// to przedstawiony algorytm nie bedzie dzial i wyrzuci blad
////////////////////////////////

int main() {
    int m = 5;              // wymiar przestrzeni
    int n = 3000;           // liczba przedzialow calkowania
    double a1 = -1, b1 = 1; // granice calkowania 1
    double a2 =  0, b2 = 1; // granice calkowania 2
    //---------------------

    /// ZAD_1 && ZAD_2 --> Gram-Schmidta - Wielomiany i Reguła Trójczłonowa:
    vector<vector<double>> baza_standardowa1 = generateBasisStandard(m);                                 /// a[0]x^n + a[1]n^(n-1) + ....
    vector<vector<double>> baza1 = Gram_Schmidt_wiel(baza_standardowa1,a1,b1,n);               /// ortogonalizacja
    vector<vector<double>> baza2 = Gram_Schmidt_wiel(baza_standardowa1,a2,b2,n);              /// ortogonalizacja

    vector<vector<double>> baza_standardowa3;                                   /// 2 pierwsze ortogonalne wektorki bazy wyzej
    vector<vector<double>> baza3 = regula_trojczlonowa(baza_standardowa3,m,a1,b1,n);

    vector<vector<double>> baza_standardowa4;                                     /// 2 pierwsze ortogonalne wektorki bazy wyzej
    vector<vector<double>> baza4 = regula_trojczlonowa(baza_standardowa4,m,a2,b2,n);

    ///-----------------------------------NORMALIZACJA-------------------------------------------
//    normalizacja_wiel(baza1 ,a1,b1,n);   /// ortonormalizacja bazy_1
//    normalizacja_wiel(baza2 ,a2,b2,n);   /// ortonormalizacja bazy_2
//    normalizacja_wiel(baza3 ,a1,b1,n);   /// ortonormalizacja bazy_3
//    normalizacja_wiel(baza4 ,a2,b2,n);   /// ortonormalizacja bazy_4
    ///--------------------------------------------------------------------------------------------

    cout << "Baza ortonormalna - Gram-Schmidta (-1:1): " << endl;
    print_matrix_transposed(baza1,6);
    cout << "Baza ortonormalna - Reguła-Trójczłonowa (-1:1): " << endl;
    print_matrix_transposed(baza3,6);
    rozdziel();
    cout << "Baza ortonormalna - Gram-Schmidta (0:1): " << endl;
    print_matrix_transposed(baza2,6);
    cout << "Baza ortonormalna - Reguła-Trójczłonowa (0:1): " << endl;
    print_matrix_transposed(baza4,6);
    rozdziel();

    /// ZAD_3 --> Wykresy_Iloczyny_Skalarne:
    vector<vector<double>> macierz_iloczynow1 =  create_scalar_product_matrix(baza1,a1,b1,n);
    vector<vector<double>> macierz_iloczynow2 =  create_scalar_product_matrix(baza2,a2,b2,n);

    /// Wektory nie sa jedynie prostopadle do samych siebie -> zera poza przekatna macierzy iloczynow skalarnych
    cout << "Macierz iloczynow skalarnych (1:1): " << endl;
    print_matrix_transposed(macierz_iloczynow1,6);
    cout << "Macierz iloczynow skalarnych (0:1): " << endl;
    print_matrix_transposed(macierz_iloczynow2,6);

    return 0;
}


