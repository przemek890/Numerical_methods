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
void print_matrix_transposed(vector<vector<double>>& mat, int precision);
vector<double> multiply_by_x(vector<double> poly);
vector<double> scalar_multiply(vector<double> vec, double scalar);
std::vector<double> add_vectors(vector<double> v1, vector<double> v2);
std::vector<double> substract_vectors(vector<double> v1, vector<double> v2);
void rozdziel();

#endif //ELIMINACJA_FUNKCJE_POM_H
