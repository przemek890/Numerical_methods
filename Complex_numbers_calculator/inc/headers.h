#ifndef DETERMINANT_HEADERS_H
#define DETERMINANT_HEADERS_H
#include <cmath>
#include <iostream>
#include <cstdlib>
using namespace std;
//-----
void create_matrix(int n,double** mat_m);
void delete_matrix(double** mat_m,int n);
void print_matrix(double** mat_m,int n);
long double determinant(double** mat_m,int n);
//-----
long int number_of_permutations(int n);
int* give_value(int n);
void permute(int *nums, int start, int end, int** result, int &index);
string** change_to_string(int** result,int ilosc,int n);
int inversions(string* tablica_str, int n);
//-----
void center_word(string max,int n);
void rozdziel();
void change(int& a, int& b);
double signi_digit(double number);

#endif //DETERMINANT_HEADERS_H
