#ifndef ELIMINACJA_GAUSSA_CROUTA_H
#define ELIMINACJA_GAUSSA_CROUTA_H
#include "Funkcje_pom.h"

///------------------ Funkcje główne:
vector<double> gauss_elimination_2(vector<vector<double>>& A, vector<double>& B);
void rozwiaz_uklad_2(vector<vector<double>>& wsp, vector<double>& wyr_wol);

#endif //ELIMINACJA_GAUSSA_CROUTA_H
