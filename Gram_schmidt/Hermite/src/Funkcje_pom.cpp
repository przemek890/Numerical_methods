#include "Funkcje_pom.h"
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
std::vector<double> add_vectors(vector<double> v1, vector<double> v2) {
    std::vector<double> result(v1.size());

    for (int i = 0; i < v1.size(); i++) {
        result[i] = v1[i] + v2[i];
    }

    return result;
}
std::vector<double> substract_vectors(vector<double> v1, vector<double> v2) {
    std::vector<double> result(v1.size());

    for (int i = 0; i < v1.size(); i++) {
        result[i] = v1[i] - v2[i];
    }

    return result;
}

vector<vector<double>> wielomiany_hermitea(vector<vector<double>>& baza,int m) {



    vector<double> vec1(m-1,0.0);     /// pierwszy wektor do generowania
    vec1.push_back(1.0);

    vector<double> vec2(m-2,0.0);   /// drugi wektor do generowania
    vec2.push_back(2.0);
    vec2.push_back(0.0);


    baza.push_back(vec1);
    baza.push_back(vec2);




    for (int i = 2; i < m; i++) {
        vector<double> pom1 =  multiply_by_x(baza[i-1]);
        vector<double> pom2 = scalar_multiply(pom1,2);


        vector<double> pom3 = scalar_multiply(baza[i-2],2*(i-1));

        vector<double> pom4 = substract_vectors(pom2,pom3);

        baza.push_back(pom4);

    }
    return baza;
}

void rozdziel() {
    cout << endl << endl;
}