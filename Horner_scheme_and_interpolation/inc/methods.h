#ifndef HORNER_SCHEME_AND_INTERPOLATION_METHODS_H
#define HORNER_SCHEME_AND_INTERPOLATION_METHODS_H
#include <iostream>
#include <vector>
using namespace std;
///----------------------------------------------
double horner(vector<double>& a, double x);
double generalized_horner(vector<double>& a, vector<double>& b, double x);
vector<double> newton_to_standard(vector<double>& b, vector<double>& x);
double lagrange_interpolation(const vector<double>& x, const vector<double>& y, double z);
vector<vector<double>> ilorazyRoznicowe(const vector<double>& x, const vector<double>& y);


void rozdziel();

#endif //HORNER_SCHEME_AND_INTERPOLATION_METHODS_H
