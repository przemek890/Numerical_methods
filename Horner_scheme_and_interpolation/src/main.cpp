#include "methods.h"
///-----------------
int main() {
    /// Zad_1 ( W(x) = (((a[0]x + a[1])x + a[2])x + ...)
    vector<double> wspolczynniki {0.5,1.33333333,-2.1666666666,-2};
    double x1 = -4.0;
    double x2 = -1.0;
    double x3 = 0.0;
    double x4 = 2.0;

    double result1 = horner(wspolczynniki, x1);
    double result2 = horner(wspolczynniki, x2);
    double result3 = horner(wspolczynniki, x3);
    double result4 = horner(wspolczynniki, x4);

    cout << "Wartość wielomianu dla x1 = " << x1 << " wynosi: " << result1 << endl;
    cout << "Wartość wielomianu dla x2 = " << x2 << " wynosi: " << result2 << endl;
    cout << "Wartość wielomianu dla x3 = " << x3 << " wynosi: " << result3 << endl;
    cout << "Wartość wielomianu dla x4 = " << x4 << " wynosi: " << result4 << endl;

    rozdziel();
    //------
    /// Zad_2 [ W(x) = ( W(x) = a[0] + a[1]*(x-b[0]) + a[2]*(x-b[1] + ...)
    vector<double> a {-4,1.6666666,-1.16666666,0.5};
    vector<double> b {-4,-1,0};
    double x11 = -4.0;
    double x22 = -1.0;
    double x33 = 0.0;
    double x44 = 2.0;

    double result11 = generalized_horner(a, b, x11);
    double result22 = generalized_horner(a, b, x22);
    double result33 = generalized_horner(a, b, x33);
    double result44 = generalized_horner(a, b, x44);

    cout << "Wartość wielomianu dla x = " << x11 << " wynosi: " << result11 << endl;
    cout << "Wartość wielomianu dla x = " << x22 << " wynosi: " << result22 << endl;
    cout << "Wartość wielomianu dla x = " << x33 << " wynosi: " << result33 << endl;
    cout << "Wartość wielomianu dla x = " << x44 << " wynosi: " << result44 << endl;
    rozdziel();
    //------
    /// Zad_3
    vector<double> bb = {-4,1.6666666,-1.16666666,0.5}; // współczynniki wielomianu (postać Newtona)
    vector<double> x = {-4,-1,0}; // węzły interpolacji
    vector<double> result = newton_to_standard(bb,x);
    cout << "Współczynniki wielomianu, w kolejności a + bx + ... -> wynoszą:  ";
    for(auto i: result) cout << i << "\t";
    cout << "\n";
    rozdziel();
    //------
    /// Zad_4
    double h = 0.01;
    vector<double> xx {-2,-1,0,1,2};
    vector<double> y {5,-2,4,-7,2};
    for(double i = -2; i<=2.01; i += h) {
        double wynik = lagrange_interpolation(xx, y, i);
        cout << i << " , " << wynik << endl;
    }
    rozdziel();
    //------
   /// Zad_5
    vector<double> xxx = { -1, 0, 1,2};
    vector<double> yy = { 2, 1, 2,-7};
    vector<vector<double>> ilorazy = ilorazyRoznicowe(xxx, yy);

    cout << "Ilorazy różnicowe wyznaczone dla funckji: f(x) = -0.5x^4 -x^3 + 1.5x^2 + x + 1 :" << endl;
    int n = xxx.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if(ilorazy[i][j] >= 0) cout << " ";
            cout << ilorazy[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}


