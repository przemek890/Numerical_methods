#include "fun_pom.h"
#include "functions.h"
int main() {
    /// Zad_1
    double a1 = 0.0;
    double b1 = 4.5;

    double a2 = -2.0;
    double b2 = 2.0;

    double a3 = -2.0;
    double b3 = 2.0;

    double a4 = -2.0;
    double b4 = 2.0;

    double a5 = 0.0;
    double b5 = 1.0;

    double a6 = 0.0;
    double b6 = 1.0 - 1e-4;

    double a7 = 0.0;
    double b7 = 1.0;



    for(int i=2;i<=7;i++) {
        double wynik1 = Gausse_lagendre(f_1,a1,b1,i);
        double wynik2 = Gausse_lagendre(f_2,a2,b2,i);
        double wynik3 = Gausse_lagendre(f_3,a3,b3,i);
        double wynik4 = Gausse_lagendre(f_4,a4,b4,i);
        double wynik5 = Gausse_lagendre(f_5,a5,b5,i);
        double wynik6 = Gausse_lagendre(f_6,a6,b6,i);
        double wynik7 = Gausse_lagendre(f_7,a7,b7,i);

        Wielomian_Lagrange(i);
        cout << "f_1 na przedziale [" << a1 << "," << b1 <<"] dla n = " << i << " : " << wynik1 << endl;
        cout << "f_2 na przedziale [" << a2 << "," << b2 <<"] dla n = " << i << " : " << wynik2 << endl;
        cout << "f_3 na przedziale [" << a3 << "," << b3 <<"] dla n = " << i << " : " << wynik3 << endl;
        cout << "f_4 na przedziale [" << a4 << "," << b4 <<"] dla n = " << i << " : " << wynik4 << endl;
        cout << "f_5 na przedziale [" << a5 << "," << b5 <<"] dla n = " << i << " : " << wynik5 << endl;
        cout << "f_6 na przedziale [" << a6 << "," << b6 <<"] dla n = " << i << " : " << wynik6 << endl;
        cout << "f_7 na przedziale [" << a7 << "," << b7 <<"] dla n = " << i << " : " << wynik7 << endl;
        rozdziel();
    }
    return 0;

}
