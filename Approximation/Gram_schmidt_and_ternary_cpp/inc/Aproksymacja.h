#ifndef ELIMINACJA_APROKSYMACJA_H
#define ELIMINACJA_APROKSYMACJA_H
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <stdexcept>
using namespace std;
#define ERROR 1e-9
//------------------
/// ------------------------------- Reguła trójczłonowa && Gram Schmidt:
vector<vector<double>> Gram_Schmidt_wiel(vector<vector<double>> baza,double a,double b, int n);
vector<vector<double>> regula_trojczlonowa(vector<vector<double>>& baza,int m, double a, double b,int n);
/// ------------------------------- APROKSYMACJA: Reguła trójczłonowa && Gram Schmidt:
vector<double> metoda_najmniejszych_kwadratow(vector<vector<double>>& baza, double (*f)(double), double a, double b, int n);
///------------------ Funkcje_dodatkowe:
bool is_NaN_or_inf(vector<vector<double>>& matrix);
vector<double> multiply_by_x(vector<double> poly);
vector<double> scalar_multiply(vector<double> vec, double scalar);
vector<double> add_vectors(vector<double> v1, vector<double> v2);
void rozdziel();
///------------------ Funkcje_pomocnicze:
double horner(double x,vector<double> a);
double simpson_wielomian(vector<double> wsp1,vector<double> wsp2, double a, double b,int n);
double simpson_funkcja(vector<double> wsp1,double (*f)(double), double a, double b,int n);
///------------------ Funkcje_drukujące:
void print_matrix_normal(vector<vector<double>> mat,int precision);
void print_matrix_transposed(vector<vector<double>> mat, int precision);
void print_vector_transposed(vector<double> vec);
///---------------------------- wielomiany:
vector<std::vector<double>> generateBasisStandard(int n);
double iloczyn_skalarny_wiel(vector<double> p1, vector<double> p2, double a, double b, int n);
void normalizacja_wiel(vector<vector<double>>& wynik,double a,double b,int n);
double norma_wiel(vector<double> vec,double a, double b, int n);
#endif //ELIMINACJA_APROKSYMACJA_H
