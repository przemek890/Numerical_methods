#include "Front_back.h"
vector<double> podstawianiePrzod(vector<vector<double>>& A, vector<double>& B) {

    if(!isLowerTriangular(A)) throw std::runtime_error("PodstawieniePrzod: Nieprawidlowe dane wejsciowe w jednej z macierzy trojkatnych");

    int n = A.size();
    vector<double> x(n, 0); // wektor wynikowy
    for (int i = 0; i < n; i++) {
        float sum = 0;
        for (int j = 0; j < i; j++) {
            sum += A[i][j] * x[j];
        }
        x[i] = (B[i] - sum) / A[i][i];
    }
    for(auto i: x)
        if(isnan(i) || isinf(i) || isinf(-i)) throw std::runtime_error("PodstawieniePrzod: Nieprawidlowe dane wejsciowe w jednej z macierzy trojkatnych");

    return x;
}
vector<double> podstawianieWstecz(vector<vector<double>>& A, vector<double>& B) {

    if(!isUpperTriangular(A)) throw std::runtime_error("PodstawieniePrzod: Nieprawidlowe dane wejsciowe w jednej z macierzy trojkatnych");

    int n = A.size();
    vector<double> x(n, 0); // wektor wynikowy
    for (int i = n - 1; i >= 0; i--) {
        float sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += A[i][j] * x[j];
        }
        x[i] = (B[i] - sum) / A[i][i];
    }
    for(auto i: x)
        if(isnan(i) || isinf(i) || isinf(-i)) throw std::runtime_error("PodstawienieTył: Nieprawidlowe dane wejsciowe w jednej z macierzy trojkatnych");

    return x;
}