#include "methods.h"
///-----------------
double horner(vector<double>& a, double x) {
    double result = a.front();
    for (int i = 1; i < a.size(); i++)
        result = result * x + a[i];
    return result;
}
double generalized_horner(vector<double>& a, vector<double>& b, double x) {
    double result = a.front();
    for (int i = 1 ; i < a.size() ; i++) {
        double pom = a[i];
        for(int j = 0; j < i;j++) {
            pom *= (x-b[j]);
        }
        result += pom;
    }
    return result;
}
vector<double> newton_to_standard(vector<double>& b, vector<double>& x) {
    int n = b.size() - 1;
    vector<double> a(n + 1);

    for (int i = 0; i <= n; i++) {
        a[i] = b[n];
    }

    for (int i = n - 1; i >= 0; i--) {
        double xi = x[i];
        a[i] = b[i];
        for (int k = i; k < n; k++) {
            a[k] -= xi * a[k + 1];
        }
    }

    return a;
}
double lagrange_interpolation(const vector<double>& x, const vector<double>& y, double z) {
    double result = 0.0;
    for (int i = 0; i < x.size(); i++) {
        double term = y[i];
        for (int j = 0; j < x.size(); j++) {
            if (i != j) {
                term *= (z - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    return result;
}
vector<vector<double>> ilorazyRoznicowe(const vector<double>& x, const vector<double>& y) {
    int n = x.size();

    vector<vector<double>> ilorazy(n, vector<double>(n));

    for (int i = 0; i < n; i++) { ilorazy[i][0] = y[i];}    // przepisane x z wektora

    for (int j = 1; j < n; j++) {
        for (int i = j; i < n; i++){
            ilorazy[i][j] = (ilorazy[i][j - 1] - ilorazy[i - 1][j - 1]) / (x[i] - x[i - j]);
        }
    }
    return ilorazy;
}

void rozdziel() {
    cout << "- - - - - - - - - - - - - - -" << endl;
}