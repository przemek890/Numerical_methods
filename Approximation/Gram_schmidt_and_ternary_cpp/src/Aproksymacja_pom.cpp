#include "Aproksymacja.h"
/// ------------------------------- Reguła trójczłonowa && Gram Schmidt:
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
/// ------------------------------- APROKSYMACJA: Reguła trójczłonowa && Gram Schmidt:
vector<double> metoda_najmniejszych_kwadratow(vector<vector<double>>& baza, double (*f)(double), double a, double b, int n)
{
    int m = baza.size();
    vector<double> wsp(m, 0.0);

    for(int i = 0; i < m; i++)
    {
        double pom = simpson_funkcja(baza[i],f,a,b,n);
        vector<double> vec  = scalar_multiply(baza[i],pom);

        for(int j=0;j<m;j++) {
            wsp[j] += vec[j];
        }
    }


    return wsp;
}
///------------------ Funkcje_dodatkowe:
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
vector<double> add_vectors(const std::vector<double> v1, const std::vector<double> v2) {
    std::vector<double> result(v1.size());

    for (int i = 0; i < v1.size(); i++) {
        result[i] = v1[i] + v2[i];
    }

    return result;
}
void rozdziel() {
    cout << endl << endl;
}
///------------------ Funkcje_pomocnicze:
double horner(double x,vector<double> a) {
    double result = a.front();
    for (int i = 1; i < a.size(); i++)
        result = result * x + a[i];
    return result;
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
        double pom3 = (1 / 6.0) *  (x1 + 4.0 * x3 + x2);
        sum += pom1 * pom2 * pom3 * h;
    }
    return sum;
}
double simpson_funkcja(vector<double> wsp1,double (*f)(double), double a, double b,int n) {
    /// h - odleglosc miedzypodstawami: (x2 - x1)
    double h = (b - a)/static_cast<double>(n); // szerokosc prostokata
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double x1 = a + i * h;          // a
        double x2 = a + (i + 1) * h;    // (a+b) / 2
        double x3 = a + (i + 0.5) * h;  // b
        double pom1 = (1 / 6.0) * (f(x1)  + 4.0 * f(x3)  + f(x2));
        double pom2 = (1 / 6.0) * (horner(x1,wsp1)  + 4.0 * horner(x3,wsp1)  + horner(x2,wsp1));
        double pom3 = (1 / 6.0) *  (x1 + 4.0 * x3 + x2);
        sum += pom1 * pom2 * pom3 * h;
    }
    return sum;
}
///------------------ Funkcje_drukujące:
void print_matrix_normal(vector<vector<double>> mat,int precision) {
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
void print_matrix_transposed(vector<vector<double>> mat, int precision) {
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
void print_vector_transposed(vector<double> vec) {
    int n = vec.size();
    cout << "+------+";
    for (int j = 0; j < 1; j++) {
        cout << setw(8) << setfill('-') << "+";
    }
    cout << endl;
    for (int i = n - 1; i >= 0; i--) { //zmiana: iteracja od n-1 do 0
        double val = vec[i];
        if (abs(val) < 1e-9) {
            val = 0.0;
        }
        cout << " " << n-i-1 << "  " << setw(12) << setfill(' ') << scientific << val << endl;
    }

    cout << "+------+";
    for (int j = 0; j < 1; j++) {
        cout << setw(8) << setfill('-') << "+";
    }
    cout << endl;
}
///---------------------------- wielomiany:
vector<vector<double>> generateBasisStandard(int n) {
    std::vector<std::vector<double>> basis(n, std::vector<double>(n, 0));
    for (int i = 0; i < n; i++) {
        basis[i][n-i-1] = 1;
    }
    return basis;
}
double iloczyn_skalarny_wiel(vector<double> p1, vector<double> p2, double a, double b, int n) {
    return simpson_wielomian(p1,p2,a,b,n);
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
double norma_wiel(vector<double> vec,double a, double b, int n) {

    double iloczyn = iloczyn_skalarny_wiel(vec,vec,a,b,n);

    return sqrt(iloczyn);
}