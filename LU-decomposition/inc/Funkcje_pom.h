#ifndef ELIMINACJA_FUNKCJE_POM_H
#define ELIMINACJA_FUNKCJE_POM_H
//----------------------------
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <stdexcept>
using namespace std;
#define ERROR 1e-9

///------------------ Funkcje_pomocnicze:
bool is_NaN_or_inf(vector<vector<double>>& matrix);
vector<vector<double>> remove_zero_columns(vector<vector<double>>& matrix);
int rzad_macierzy(vector<std::vector<double>>& matrix);
vector<std::vector<double>> macierz_uzupelniona(vector<std::vector<double>> matrix,vector<double> wyr_wol);
void rozdziel();
vector<vector<double>> usunWierszKolumne(vector<vector<double>> macierz, int wiersz, int kolumna);
double wyznacznik(vector<vector<double>> macierz);
void print_matrix(vector<vector<double>>& A);
bool isLowerTriangular(const vector<vector<double>>& matrix);
bool isUpperTriangular(const vector<vector<double>>& matrix);
//----------------------------

#endif //ELIMINACJA_FUNKCJE_POM_H
