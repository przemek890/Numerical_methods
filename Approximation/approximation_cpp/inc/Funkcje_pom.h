#ifndef ELIMINACJA_FUNKCJE_POM_H
#define ELIMINACJA_FUNKCJE_POM_H
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <stdexcept>
using namespace std;
#define ERROR 1e-9
///-----------------

double f(double x) {
    return sin(x);
}                               /// Funkcja aproksymowana
double horner(vector<double>& a, double x) {
    double result = a.back();
    for (int i = a.size() - 2; i >= 0; i--)
        result = result * x + a[i];
    return result;
}

vector<double> Gauss_elimination(vector<vector<double>>& A, vector<double>& B) {
    int n = B.size();   /// ilosc rownan w ukladzie

    /// Wybieramy index elementu w kolumnie o największej wartości bezwzględnej
    for (int k = 0; k < n; k++) {
        int max_row = k;
        for (int i = k + 1; i < n; i++) {
            if (abs(A[i][k]) > abs(A[max_row][k])) {
                max_row = i;
            }
        }
        /// zamiana wierszy
        swap(A[k], A[max_row]);
        swap(B[k], B[max_row]);
        //----------------------------

        /// Eliminacja Gaussa-Crouta
        for (int i = k + 1; i < n; i++) {
            double factor = A[i][k] / A[k][k];
            for (int j = k + 1; j < n; j++) {
                A[i][j] -= factor * A[k][j];
            }
            B[i] -= factor * B[k];
            A[i][k] = 0;
        }
    }


    /// Rozwiązanie układu równań -> Podstawienie w górę
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


///---------------------------------------------

/// Metoda najmniejszych kwadratów (średniokwadratowa)
vector<double> metoda_najmniejszych_kwadratow(vector<double>& x,vector<double>& y,int n) {

    /// M: A * wsp = B
    vector<double> wsp(n + 1);                                         /// Wektor do przechowywania wspolczynnikow wielomianu aproksymujacego
    vector<vector<double>> A(n + 1, vector<double>(n + 1)); /// Macierz A równania normalnego
    vector<double> B(n + 1);                                         /// Macierz B równania normalnego


    /// obliczenie macierzy A i wektora B
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < x.size(); k++) {
                A[i][j] += pow(x[k], i+j); /// A
            }
        }
        for (int k = 0; k < x.size(); k++) {
            B[i] += y[k] * pow(x[k], i);   /// B
        }
    }

    wsp = Gauss_elimination(A,B);

    return wsp;
}
void print_values(double (*f)(double),vector<double> wsp,int stopien,vector<double>& x) {
// wyświetlenie wyników
    cout << "Współczynniki wielomianu aproksymującego:\n";
    cout << "+----+-----------------+\n";
    cout << "  a  |     Wartość      \n";
    cout << "+----+-----------------+\n";
    for (int i = 0; i <= stopien; i++) {
        cout  << " " << setw(2) << i << "   " << setw(15) << scientific << wsp[i] << "\n";
    }
    cout << "+----+-----------------+\n\n";


    cout << setw(10) << "x"
         << setw(10) << "f(x)"
         << setw(10) << "p(x)" << endl;

    for (int i = 0; i < x.size(); i++) {
        cout << setw(10) << fixed << setprecision(5) << x[i]
             << setw(10) << fixed << setprecision(5) << f(x[i])
             << setw(10) << fixed << setprecision(5) << horner(wsp,x[i]) << endl;
    }
}


#endif //ELIMINACJA_FUNKCJE_POM_H
