#ifndef ELIMINACJA_FUNKCJE_POM_H
#define ELIMINACJA_FUNKCJE_POM_H
//----------------------------
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ERROR 1e-9

///------------------ Funkcje_pomocnicze:
bool is_NaN_or_inf(const std::vector<std::vector<double>>& matrix);
vector<vector<double>> remove_zero_columns(vector<vector<double>>& matrix);
int rzad_macierzy(vector<std::vector<double>>& matrix);
vector<std::vector<double>> macierz_uzupelniona(vector<std::vector<double>> matrix,vector<double> wyr_wol);
void rozdziel();


//----------------------------

#endif //ELIMINACJA_FUNKCJE_POM_H
