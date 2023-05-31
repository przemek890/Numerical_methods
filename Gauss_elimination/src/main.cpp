#include "Gauss_Crouta.h"
#include "Gauss.h"


int main() {
    ///////
    // F1: wsp[0][0]x + wsp[0][1]y + ... == wyr_wol[0]
    // F2: wsp[1][0]x + wsp[1][1]y + ... == wyr_wol[1]
    // F3: wsp[2][0]x + wsp[2][1]y + ... == wyr_wol[2]
    ///////
    // Uklad nieoznaczony:
                                                                       /// Macierz wspolczynnikow
    vector<vector<double>> wsp1 = { { 0, -3.0, 4.0, 6.8,  9.0},
                                    {-3.0, 2.0, 4.6, 6.3, -10.0},
                                    { 2.0,-1.0, 2.8,-8.4, -5.0 },
                                    {-6.0, 2.0, 7.0,-0.5, -0.9 },
                                    { 5.0,-2.0,-0.5, 12.0,-4.0}};
    vector<double> wyr_wol1 = {74.64,-40.26,-2.32,12.6,-8.9};         /// Macierz wyrazow wolnych
    rozwiaz_uklad_1(wsp1,wyr_wol1);
    rozdziel();

    vector<vector<double>> wsp2 = { { 0, -3.0, 4.0, 6.8,  9.0},
                                    {-3.0, 2.0, 4.6, 6.3, -10.0},
                                    { 2.0,-1.0, 2.8,-8.4, -5.0 },
                                    {-6.0, 2.0, 7.0,-0.5, -0.9 },
                                    { 5.0,-2.0,-0.5, 12.0,-4.0}};
    vector<double> wyr_wol2 = {74.64,-40.26,-2.32,12.6,-8.9};
    rozwiaz_uklad_2(wsp2,wyr_wol2);



    return 0;
}


