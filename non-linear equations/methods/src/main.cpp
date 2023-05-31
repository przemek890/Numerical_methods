#include "Metody_rozw.h"
#include "FunkcjePomocnicze.h"
#include "Rownania.h"

Solutions rozwiazania;
///------------------
int main() {
    ///-----------------------------------------------------------------------------------------------
    // Metoda stycznych Newtona - pochodna analitycznie:
    cout << "---> Metoda stycznych - Newtona (analitycznie):" << endl;
    double x0_1 = 2.0;            // Punkt początkowy
    double epsilon1 = 1e-9; // Dokładność
    int maxIteracji1 = 100;    // Maksymalna liczba iteracji
    cout << "1) równanie: " << MetodaStycznychNewtona1(poch_1,rownanie_1,x0_1,epsilon1,maxIteracji1,0,rozwiazania) << endl;
    cout << "2) równanie: " << MetodaStycznychNewtona1(poch_2,rownanie_2,x0_1,epsilon1,maxIteracji1,1,rozwiazania) << endl;
    cout << "3) równanie: " << MetodaStycznychNewtona1(poch_3,rownanie_3,x0_1,epsilon1,maxIteracji1,2,rozwiazania) << endl;
    cout << "4) równanie: " << MetodaStycznychNewtona1(poch_4,rownanie_4,x0_1,epsilon1,maxIteracji1,3,rozwiazania) << endl;
    rozdziel();
    ///-----------------------------------------------------------------------------------------------
    // Metoda stycznych Newtona  - pochodna numerycznie:
    cout << "---> Metoda stycznych - Newtona (numerycznie):" << endl;
    double x0_2 = 2.0;          // Punkt początkowy
    double epsilon2 = 1e-9;  // Dokładność
    int maxIteracji2 = 100;   // Maksymalna liczba iteracji
    cout << "1) równanie: " << MetodaStycznychNewtona2(rownanie_1,x0_2,epsilon2,maxIteracji2,0,rozwiazania) << endl;
    cout << "2) równanie: " << MetodaStycznychNewtona2(rownanie_2,x0_2,epsilon2,maxIteracji2,1,rozwiazania) << endl;
    cout << "3) równanie: " << MetodaStycznychNewtona2(rownanie_3,x0_2,epsilon2,maxIteracji2,2,rozwiazania) << endl;
    cout << "4) równanie: " << MetodaStycznychNewtona2(rownanie_4,x0_2,epsilon2,maxIteracji2,3,rozwiazania) << endl;
    rozdziel();
    ///-----------------------------------------------------------------------------------------------
    // Metoda siecznych:
    cout << "---> Metoda siecznych:" << endl;
    double x0_3 = 0.0;                // Punkt początkowy x0
    double x1_3 = 2.0;               // Punkt początkowy x1
    double epsilon3 = 1e-9;    // Dokładność
    int maxIteracji3 = 100;      // Maksymalna liczba iteracji
    cout << "1) równanie: " << MetodaSiecznych(rownanie_1,x0_3,x1_3,epsilon3,maxIteracji3,0,rozwiazania) << endl;
    cout << "2) równanie: "<< MetodaSiecznych(rownanie_2,x0_3,x1_3,epsilon3,maxIteracji3,1,rozwiazania) << endl;
    cout << "3) równanie: " << MetodaSiecznych(rownanie_3,x0_3,x1_3,epsilon3,maxIteracji3,2,rozwiazania) << endl;
    cout << "4) równanie: " << MetodaSiecznych(rownanie_4,x0_3,x1_3,epsilon3,maxIteracji3,3,rozwiazania) << endl;
    rozdziel();
    ///-----------------------------------------------------------------------------------------------
    // Regula falsi:
    cout << "---> Regula falsi:" << endl;
    double a4 = 0.0;                   // Lewy koniec przedziału
    double b4 = 2.0;                  // Prawy koniec przedziału
    double epsilon4 = 1e-9;        // Dokładność
    int maxIteracji4 = 100;         // Maksymalna liczba iteracji
    cout << "1) równanie: " << RegulaFalsi(rownanie_1,a4, b4, epsilon4, maxIteracji4,0,rozwiazania) << endl;
    cout << "2) równanie: " << RegulaFalsi(rownanie_2,a4, b4, epsilon4, maxIteracji4,1,rozwiazania) << endl;
    cout << "3) równanie: "<< RegulaFalsi(rownanie_3,a4, b4, epsilon4, maxIteracji4,2,rozwiazania) << endl;
    cout << "4) równanie: " << RegulaFalsi(rownanie_4,a4, b4, epsilon4, maxIteracji4,3,rozwiazania) << endl;
    rozdziel();
    ///-----------------------------------------------------------------------------------------------
    // Bisekcja:
    cout << "---> Metoda bisekcji:" << endl;
    double a5 = 0.0;             // Lewa granica przedziału
    double b5 = 2.0;            // Prawa granica przedziału
    double epsilon5 = 1e-9;  // Dokładność
    cout << "1) równanie: " << Bisekcja(rownanie_1,a5,b5,epsilon5,0,rozwiazania) << endl;
    cout << "2) równanie: " << Bisekcja(rownanie_2,a5,b5,epsilon5,1,rozwiazania) << endl;
    cout << "3) równanie: " << Bisekcja(rownanie_3,a5,b5,epsilon5,2,rozwiazania) << endl;
    cout << "4) równanie: " << Bisekcja(rownanie_4,a5,b5,epsilon5,3,rozwiazania) << endl;
    rozdziel();
    ///-----------------------------------------------------------------------------------------------
    wypisz(rozwiazania.MetodaStycznychNewtona1,"MetodaStycznychNewtona1");
    wypisz(rozwiazania.MetodaStycznychNewtona2,"MetodaStycznychNewtona2");
    wypisz(rozwiazania.MetodaSiecznych,"MetodaSiecznych");
    wypisz(rozwiazania.RegulaFalsi,"RegulaFalsi");
    wypisz(rozwiazania.Bisekcja,"Bisekcja");

    return 0;
}
