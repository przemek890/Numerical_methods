#include "Gram_Schmidt.h"
vector<vector<double>> Gram_Schmidt_wiel(vector<vector<double>> baza,double a,double b, int n) {
    vector<vector<double>> wynik;
    for (int i = 0; i < baza.size(); i++) {
        vector<double> w;
        for (int j = 0; j < baza[i].size(); j++) {
            double pom = baza[i][j];
            for (int k = 0; k < i; k++) {
                double skalar = iloczyn_skalarny_wiel(baza[i],wynik[k],a,b,n);
                double mianownik = iloczyn_skalarny_wiel(wynik[k], wynik[k],a,b,n);
                if (mianownik != 0) {
                    pom -= skalar / mianownik * wynik[k][j];
                }
                else throw runtime_error("Dzielenie przez 0");
            }
            w.push_back(pom);
        }
        wynik.push_back(w);
    }
    if(is_NaN_or_inf(wynik)) throw runtime_error("Nan or inf error");
    return wynik;
}
void normalizacja_wiel(vector<vector<double>>& wynik,double a,double b,int n) {
    for (int i = 0; i < wynik.size(); i++) {
        double norma = sqrt(iloczyn_skalarny_wiel(wynik[i],wynik[i],a,b,n));
        if (norma != 0) {
            for (int j = 0; j < wynik.size(); j++) {
                wynik[i][j] /= norma;
            }
        }
        else throw runtime_error("Dzielenie przez 0");
    }
    if(is_NaN_or_inf(wynik)) throw runtime_error("Nan or inf error");
}
//-------------------------------
vector<vector<double>> regula_trojczlonowa(vector<vector<double>>& baza,int m, double a, double b,int n) {
    /// baza powinna zawierac 2 pierwsze wektory ortogonalne na start


    vector<double> pom1(m,0.0);     /// pierwszy wektor do generowania
    vector<double> pom2(m-1,0.0);   /// drugi wektor do generowania
    pom2.push_back(1.0);
    baza.push_back(pom2);

    vector<double> pom3 = multiply_by_x(baza[0]);
    double beta =  - iloczyn_skalarny_wiel(pom3,baza[0],a,b,n) / iloczyn_skalarny_wiel(baza[0],baza[0],a,b,n);

    vector<double> pom4 = scalar_multiply(baza[0],beta);
    vector<double> pom5 = add_vectors(pom3,pom4);
    baza.push_back(pom5);

    for (int i = 2; i < m; i++) {
        vector<double> pom = multiply_by_x(baza[i-1]);

        double beta =  - iloczyn_skalarny_wiel(pom,baza[i-1],a,b,n) / iloczyn_skalarny_wiel(baza[i-1],baza[i-1],a,b,n);
        double gamma =  - iloczyn_skalarny_wiel(baza[i-1],baza[i-1],a,b,n) / iloczyn_skalarny_wiel(baza[i-2],baza[i-2],a,b,n);

        vector<double> vec_1 = scalar_multiply(baza[i-1],beta);
        vector<double> vec_2 = scalar_multiply(baza[i-2],gamma);

        vector<double> vec_3 = add_vectors(pom,vec_1);
        vector<double> vec_4 = add_vectors(vec_3,vec_2);

        baza.push_back(vec_4);
    }
    return baza;
}