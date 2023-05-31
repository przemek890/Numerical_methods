#include "Gauss.h"
vector<double> gauss_elimination_1(vector<vector<double>>& A, vector<double>& B) {
    int n = B.size();                                                                 /// ilosc rownan w ukladzie

    // Eliminacja Gaussa-Crouta
    for (int k = 0; k < n; k++) {

        for (int i = k + 1; i < n; i++) {
            double factor = A[i][k] / A[k][k];
            for (int j = k + 1; j < n; j++) {
                A[i][j] -= factor * A[k][j];
            }
            B[i] -= factor * B[k];
            A[i][k] = 0;
        }
    }

    // Rozwiązanie układu równań (iteracyjnie od samego dołu)
    vector<double> x(n);
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += A[i][j] * x[j];
        }
        x[i] = (B[i] - sum) / A[i][i];
    }

    return x;
}
void rozwiaz_uklad_1(vector<vector<double>>& wsp, vector<double>& wyr_wol) {
    wsp = remove_zero_columns(wsp);                                                        /// Usuwanie kolumn zerowych (nic nie wnoszą do wyniku)
    vector<double> x = gauss_elimination_1(wsp,wyr_wol);                               ///  Sprowadzenie do macierzy schodkowej
    vector<vector<double>> mat_uzu = macierz_uzupelniona(wsp,wyr_wol);                /// Macierz uzupelniona
    int rzad_normalnej = rzad_macierzy(wsp);                                             /// Rząd macierzy A
    int rzad_uzupelnionej = rzad_macierzy(mat_uzu);                                     /// Rząd macierzy uzupelnionej


    //----------------------------------------------------
    // / Określenie rozwiązań -> Twierdzenie Kroneckera-Capelliego

    /// rzad_normalnej == -1 -> Nan error
    int n = wsp[0].size();

    if(rzad_normalnej == n && n  == rzad_uzupelnionej && rzad_normalnej != -1)  {
        cout << "Gauss: Rozwiązanie układu równań:\n";
        for (int i = 0; i < x.size(); i++) {
            cout << "x[" << i << "] = " << x[i] << "\n";
        }
    }
    else if (rzad_normalnej != rzad_uzupelnionej && rzad_normalnej != -1 ) {
        cout << "Gauss: Układ sprzeczny." << endl;
    }
    else if (rzad_normalnej == rzad_uzupelnionej && rzad_uzupelnionej < n && rzad_normalnej != -1) {
        cout << "Gauss: Układ nieoznaczony, zalezny od: " << n -  rzad_normalnej << " parametrów." << endl;
    }
    else {
        cout << "Gauss: NaN error" << endl;
    }
}