#include "Funkcje_pom.h"
///------------------ Funkcje_pomocnicze:
bool is_NaN_or_inf(vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& value : row) {
            if (std::isnan(value)) {
                return true;
            }
            if (std::isinf(value) || std::isinf(-value)) {
                return true;
            }
        }
    }
    return false;
}
void print_matrix_normal(vector<vector<double>>& mat,int precision) {
    int n = mat.size();

    cout << "+---+";
    for (int j = 0; j < n; j++) {
        cout << setw(13) << setfill('-') << "+";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
//        cout << fixed << setprecision(1) << " " << (float)(i + 1);
        for (int j = 0; j < n; j++) {
            cout << setw(12) << setfill(' ') << fixed << setprecision(precision) << abs(mat[i][j]) << " ";
        }
        cout << endl;
    }

    cout << "+---+";
    for (int j = 0; j < n; j++) {
        cout << setw(13) << setfill('-') << "+";
    }
    cout << endl;
}

double horner(double x,vector<double> a) {
    double result = a.front();
    for (int i = 1; i < a.size(); i++)
        result = result * x + a[i];
    return result;
}
void print_matrix_transposed(vector<vector<double>>& mat, int precision) {
    int n = mat.size();
    cout << "+---+";
    for (int j = 0; j < n; j++) {
        cout << setw(13) << setfill('-') << "+";
    }
    cout << endl;

    for (int j = 0; j < n; j++) {
//        cout << fixed << setprecision(1) << " " << (float)(j + 1);
        for (int i = 0; i < n; i++) {
            double val = mat[i][j];
            if (abs(val) < 1e-9) {
                val = 0.0;
            }
            cout << setw(12) << setfill(' ') << fixed << setprecision(precision) << val << " ";
        }
        cout << endl;
    }

    cout << "+---+";
    for (int j = 0; j < n; j++) {
        cout << setw(13) << setfill('-') << "+";
    }
    cout << endl;
}
double simpson_wielomian(vector<double> wsp1,vector<double> wsp2, double a, double b,int n) {
    /// h - odleglosc miedzypodstawami: (x2 - x1)
    double h = (b - a)/static_cast<double>(n); // szerokosc prostokata
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double x1 = a + i * h;          // a
        double x2 = a + (i + 1) * h;    // (a+b) / 2
        double x3 = a + (i + 0.5) * h;  // b
        double pom1 = (1 / 6.0) * (horner(x1,wsp1)  + 4.0 * horner(x3,wsp1)  + horner(x2,wsp1));
        double pom2 = (1 / 6.0) * (horner(x1,wsp2)  + 4.0 * horner(x3,wsp2)  + horner(x2,wsp2));
        sum += pom1 * pom2 * h;
    }
    return sum;
}


vector<double> multiply_by_x(vector<double> poly) {
    int n = poly.size();
    vector<double> res(n, 0.0);

    for (int i = 0; i < n-1; i++)
        res[i] = poly[i+1];

    res[n-1] = 0;
    return res;
}
vector<double> scalar_multiply(vector<double> vec, double scalar) {
    int n = vec.size();

    for (int i = 0; i < n; i++) {
        vec[i] *= scalar;
    }
    return vec;
}
std::vector<double> add_vectors(const std::vector<double> v1, const std::vector<double> v2) {
    std::vector<double> result(v1.size());

    for (int i = 0; i < v1.size(); i++) {
        result[i] = v1[i] + v2[i];
    }

    return result;
}
void rozdziel() {
    cout << endl << endl;
}

///---------------------------- WIELOMIANY
std::vector<std::vector<double>> generateBasisStandard(int n) {
    std::vector<std::vector<double>> basis(n, std::vector<double>(n, 0));
    for (int i = 0; i < n; i++) {
        basis[i][n-i-1] = 1;
    }
    return basis;
}
double iloczyn_skalarny_wiel(vector<double> p1, vector<double> p2, double a, double b, int n) {
    return simpson_wielomian(p1,p2,a,b,n);
}
double norma_wiel(vector<double> vec,double a, double b, int n) {

    double iloczyn = iloczyn_skalarny_wiel(vec,vec,a,b,n);

    return sqrt(iloczyn);
}

///----------------------------- WYKRES
vector<vector<double>> create_scalar_product_matrix(vector<vector<double>> baza,double a, double b, int n) {
    int size = baza.size();
    vector<vector<double>> M(size, vector<double>(size, 0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            M[i][j] = iloczyn_skalarny_wiel(baza[i], baza[j], a, b, n); // funkcja iloczyn_skalarny_wiel oblicza iloczyn skalarny wektorów
        }
    }
    return M;
}