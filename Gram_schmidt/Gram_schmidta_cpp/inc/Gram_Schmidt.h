#ifndef ELIMINACJA_GRAM_SCHMIDT_H
#define ELIMINACJA_GRAM_SCHMIDT_H
#include "Funkcje_pom.h"
//-------------------------------
vector<vector<double>> Gram_Schmidt_wiel(vector<vector<double>> baza,double a,double b, int n);
void normalizacja_wiel(vector<vector<double>>& wynik,double a,double b,int n);
vector<vector<double>> regula_trojczlonowa(vector<vector<double>>& baza,int m, double a, double b,int n);


#endif //ELIMINACJA_GRAM_SCHMIDT_H
