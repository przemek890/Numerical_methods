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
//-----------------
bool is_NaN_or_inf(vector<vector<double>>& matrix);
void print_matrix_normal(vector<vector<double>>& mat,int precision);
double horner(double x,vector<double> a);
void print_matrix_transposed(vector<vector<double>>& mat, int precision);
double simpson_wielomian(vector<double> wsp1,vector<double> wsp2, double a, double b,int n);
vector<double> multiply_by_x(vector<double> poly);
vector<double> scalar_multiply(vector<double> vec, double scalar);
std::vector<double> add_vectors(const std::vector<double> v1, const std::vector<double> v2);
void rozdziel();
std::vector<std::vector<double>> generateBasisStandard(int n);
double iloczyn_skalarny_wiel(vector<double> p1, vector<double> p2, double a, double b, int n);
double norma_wiel(vector<double> vec,double a, double b, int n);
vector<vector<double>> create_scalar_product_matrix(vector<vector<double>> baza,double a, double b, int n);



#endif //ELIMINACJA_FUNKCJE_POM_H
