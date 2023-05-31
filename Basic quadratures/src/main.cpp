#include "equations.h"
#include "quadratures.h"
int main() {
    /// Zad_0 [Metoda prostokatow]
    cout << "zad_0" << endl;
    double a0 = 0;
    double a00 = 1.0;
    int n0 = 1000;
    double calka0 = metoda_prostokatow(drgania_tlumione, a0, a00, n0);
    std::cout << "Prostokat: Calka z zadanej funkcji na przedziale [" << a0 << ", " << a00 << "] wynosi " << calka0 << std::endl;
    rozdziel();
    //---------
    /// Zad_1 [Metoda trapezów]
    cout << "zad_1" << endl;
    double a1 = 0;
    double a11 = 1.0;
    int n1 = 1000;
    double calka1 = metoda_trapezow(drgania_tlumione, a1, a11, n1);
    std::cout << "Trapez: Calka z zadanej funkcji na przedziale [" << a1 << ", " << a11 << "] wynosi " << calka1 << std::endl;
    rozdziel();
    //---------
    /// Zad_2.1
    cout << "zad_2.1" << endl;
    double a2 = 0.0, b2 = 1.0, n2 = 1000;
    double result2 = newton_cotes_trapez(drgania_tlumione,a2, b2, n2);
    cout << "Wynik -> trapez: " << result2 << endl;
    rozdziel();
    //---------
    /// Zad_2.2
    cout << "zad_2.2" << endl;
    double a22 = 0.0, b22 = 1.0, n22 = 1000;
    double result22 = newton_cotes_simpson(drgania_tlumione,a22, b22, n22);
    cout << "Wynik -> simpson: " << result22 << endl;
    rozdziel();
    //---------
    /// Zad_3
    cout << "zad_3" << endl;
    double a3 = -2.0;  // przedzial dolny
    double a33 = 2.0; // przedzial górny
    int n3 = 10000;
    vector<double> wsp3 = {0.4, 5, -6, -2,55}; /// ( W(x) = (((a[0]x + a[1])x + a[2])x + ...)
    double trapezoidal_approx3 = trapez_wielomian(wsp3,a3, a33,n3);
    double simpson_approx3 = simpson_wielomian(wsp3,a3, a33,n3);
    double rectangle_approx3 = rectangle_wielomian(wsp3,a3, a33,n3);
    cout << "Wynik -> trapezoidal: " << trapezoidal_approx3 << endl;
    cout << "Wynik -> simpson: " << simpson_approx3 << endl;
    cout << "Wynik -> rectangle: " << rectangle_approx3 << endl;
    rozdziel();
    //---------
    /// Zad_4
    cout << "zad_4" << endl;
    double a4 = 0.0, b4 = 4.5;
    for(int i=100;i<=1000000;i *= 10) {
        double result4 = newton_cotes_trapez(funkcja_1,a4, b4, i);
        double result44 = newton_cotes_simpson(funkcja_1,a4, b4, i);
        double result444 = metoda_prostokatow(funkcja_1,a4, b4, i);
        cout << "h: " << (b4-a4)/i << " -> Wynik ( wzór Trapezow ): " << result4 << endl;
        cout << "h: " << (b4-a4)/i <<  " -> Wynik ( wzór Simpsona ): " << result44 << endl;
        cout << "h: " << (b4-a4)/i << " -> Wynik ( wzór Prostokatow ): " << result444 << endl;
    }
    rozdziel();
    //---------
    /// Zad_5
    cout << "zad_5" << endl;
    double a5 = -2, b5 = 2;
    for(int i=100;i<=1000000;i *= 10) {
        double result5 = newton_cotes_trapez(funkcja_2,a5, b5, i);
        double result55 = newton_cotes_simpson(funkcja_2,a5, b5, i);
        double result555 = metoda_prostokatow(funkcja_2,a5, b5, i);
        cout << "h: " << (b4-a4)/i << " -> Wynik ( wzór Trapezow ): " << result5 << endl;
        cout << "h: " << (b4-a4)/i <<" -> Wynik ( wzór Simpsona ): " << result55 << endl;
        cout << "h: " << (b4-a4)/i << " -> Wynik ( wzór Prostokatow ): " << result555 << endl;
    }
    rozdziel();
     //---------
     /// zad_6
     double a6 = 0.0000001;
     double b6 = 1;

     double a66 = 0;
     double b66 = 1 - 1e-4;

     double a666 = 0;
     double b666 = 1;

     int n6 = 10000;

     double calka6 = metoda_prostokatow(funkcja_3,a6,b6,n6);
     double calka66 = newton_cotes_trapez(funkcja_3,a6,b6,n6);
     double calka666 = newton_cotes_simpson(funkcja_3,a6,b6,n6);

    double calka7 = metoda_prostokatow(funkcja_4,a66,b66,n6);
    double calka77 = newton_cotes_trapez(funkcja_4,a66,b66,n6);
    double calka777 = newton_cotes_simpson(funkcja_4,a66,b66,n6);

    double calka8 = metoda_prostokatow(funkcja_5,a666,b666,n6);
    double calka88 = newton_cotes_trapez(funkcja_5,a666,b666,n6);
    double calka888 = newton_cotes_simpson(funkcja_5,a666,b666,n6);



    cout << "sin(x)/x : " << " -> Wynik ( wzór Prostokatow ): " << calka6 << endl;
    cout << "sin(x)/x : "  << " -> Wynik ( wzór Trapezow ): " << calka66 << endl;
    cout << "sin(x)/x : "  <<" -> Wynik ( wzór Simpsona ): " << calka666 << endl;
    cout << endl;
    cout << "sin(1/(1-x)) : " << " -> Wynik ( wzór Prostokatow ): " << calka7 << endl;
    cout << "sin(1/(1-x)) : "  << " -> Wynik ( wzór Trapezow ): " << calka77 << endl;
    cout << "sin(1/(1-x)) : "  <<" -> Wynik ( wzór Simpsona ): " << calka777 << endl;
    cout << endl;
    cout << "x^x: " << " -> Wynik ( wzór Prostokatow ): " << calka8 << endl;
    cout << "x^x : "  << " -> Wynik ( wzór Trapezow ): " << calka88 << endl;
    cout << "x^x : "  <<" -> Wynik ( wzór Simpsona ): " << calka888 << endl;

    rozdziel();
    //---------


    return 0;
}

