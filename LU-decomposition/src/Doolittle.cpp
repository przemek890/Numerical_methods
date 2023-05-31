#include "Doolittle.h"
void doolittle(vector<vector<double>>& A, vector<vector<double>>& L, vector<vector<double>>& U) {

    if(abs(wyznacznik(A)) < ERROR) {
        cout <<  "Macierz osobliwa - nie można rozłożyć na macierze LU" << endl;
        return;
    }

    int n = A.size();

    for (int i = 0; i < n; i++) {
        // U matrix
        for (int k = i; k < n; k++) {
            double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += (L[i][j] * U[j][k]);
            }
            U[i][k] = A[i][k] - sum;
        }

        // L matrix
        for (int k = i; k < n; k++) {
            if (i == k) {
                L[i][i] = 1;
            }
            else {
                double sum = 0;
                for (int j = 0; j < i; j++) {
                    sum += (L[k][j] * U[j][i]);
                }
                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }
    if(is_NaN_or_inf(L) || is_NaN_or_inf(U)) throw std::runtime_error("Doolittle: Nieprawidlowe dane wejsciowe w jednej z macierzy");

}
