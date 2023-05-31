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
vector<vector<double>> remove_zero_columns(vector<vector<double>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> columns_to_remove;
    for (int j = 0; j < m; j++) {
        bool is_zero_column = true;
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] != 0) {
                is_zero_column = false;
                break;
            }
        }
        if (is_zero_column) {
            columns_to_remove.push_back(j);
        }
    }
    int num_columns_to_remove = columns_to_remove.size();
    int num_columns_to_keep = m - num_columns_to_remove;
    vector<vector<double>> new_matrix(n, vector<double>(num_columns_to_keep));
    int column_index = 0;
    for (int j = 0; j < m; j++) {
        if (find(columns_to_remove.begin(), columns_to_remove.end(), j) == columns_to_remove.end()) {
            for (int i = 0; i < n; i++) {
                new_matrix[i][column_index] = matrix[i][j];
            }
            column_index++;
        }
    }
    return new_matrix;
}
int rzad_macierzy(vector<std::vector<double>>& matrix) { /// macierz zadana, musi byc macierza schodkowa Gaussa
    if(is_NaN_or_inf(matrix)) return -1; // Błąd obliczeń

    int m = matrix.size();
    int n = matrix[0].size();
    int rank = 0;
    for (int j = 0; j < n; j++) {
        bool non_zero = false;
        for (int i = rank; i < m; i++) {
            if (abs(matrix[i][j]) > ERROR) {
                non_zero = true;
                break;
            }
        }
        if (non_zero) {
            rank++;
        }
    }
    return rank;
}
vector<std::vector<double>> macierz_uzupelniona(vector<std::vector<double>> matrix,vector<double> wyr_wol) {
    vector<std::vector<double>> mat = matrix;
    for(int i=0;i<mat.size();i++) {
        mat[i].push_back(wyr_wol[i]);
    }
    return mat;
}
void rozdziel() {
    cout << "- - - - - - - - - -" << endl;
    cout << "- - - - - - - - - -" << endl;
    cout << "- - - - - - - - - -" << endl;
}
//----------------------
vector<vector<double>> usunWierszKolumne(vector<vector<double>> macierz, int wiersz, int kolumna) {
    macierz.erase(macierz.begin() + wiersz); // usuń wiersz
    for (int i = 0; i < macierz.size(); i++) {
        macierz[i].erase(macierz[i].begin() + kolumna); // usuń kolumnę
    }
    return macierz;
}
double wyznacznik(vector<vector<double>> macierz) {
    int rozmiar = macierz.size();
    float det = 0;
    if (rozmiar == 1) {
        det = macierz[0][0];
    } else if (rozmiar == 2) {
        det = macierz[0][0] * macierz[1][1] - macierz[0][1] * macierz[1][0];
    } else {
        for (int i = 0; i < rozmiar; i++) {
            vector<vector<double>> mniejszaMacierz = usunWierszKolumne(macierz, 0, i);
            det += pow(-1, i) * macierz[0][i] * wyznacznik(mniejszaMacierz);
        }
    }
    return det;
}
void print_matrix(vector<vector<double>>& A) {
    int n = A.size();

    cout << "+";
    for (int j = 0; j < n; j++) {
        cout << setw(13) << setfill('-') << "+";
    }
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << "|";
        for (int j = 0; j < n; j++) {
            cout << setw(12) << setfill(' ') << fixed << setprecision(4) << A[i][j] << " ";
        }
        cout << "|" << endl;
    }

    cout << "+";
    for (int j = 0; j < n; j++) {
        cout << setw(13) << setfill('-') << "+";
    }
    cout << endl;
}
bool isLowerTriangular(const vector<vector<double>>& matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}
bool isUpperTriangular(const vector<vector<double>>& matrix)
{
    int n = matrix.size();
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (matrix[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}