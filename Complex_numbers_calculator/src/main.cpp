<<<<<<< HEAD
#include "headers.h"
#include "test.h"

int main() {
    cout << "@ Determinant Permutationally @" << endl;
    while(1) {
        rozdziel();
        cout <<"Select the operation type [1-3]:" << endl;
        cout << "1. Determinant" << endl;
        cout << "2. Test" << endl;
        cout << "3. EXIT" << endl;
        string pom1;
        int pom;
        try {
            getline(cin, pom1);
            if(pom1 == "") getline( cin, pom1);
            pom = stoi(pom1);
        }
        catch(...) {cout << "Range error" << endl; continue;}
        cout << "---" << endl;
        switch(pom) {
            case 1: {
                string n1;
                int n;
                cout <<"Enter the size of the matrix [1-9]:" << endl;
                try {
                    getline(cin, n1);
                    if(n1 == "") getline( cin, n1);
                    n = stoi(n1);
                }
                catch(...) {cout << "Range error" << endl; continue;}
                if(n < 1 || n > 10) {cout << "Range error" << endl; continue;}
                cout << "---" << endl;

                double** mat_m = new double* [n];
                for(int i =0;i<n;i++) mat_m[i] = new double [n];
                try {create_matrix(n,mat_m);}
                catch(...) {cout << "Range error" << endl; continue;}
                print_matrix(mat_m,n);
                long double wynik = determinant(mat_m,n);
                cout << endl;
                cout << "The determinant of A, computed permutationally: " << wynik << endl;
                delete_matrix(mat_m,n);
                break;
            }
            case 2: {
                test();
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                cout << "Error" << endl;
=======
#include "complex.h"
#include "test.h"
//------


int main() {
    rozdziel();
    cout << "Complex number calculator: " << endl;
    while(1) {
        rozdziel();
        string liczba;
        cout << "/// Select number:" << endl;
        cout << "0:  Argument" << endl;
        cout << "1:  Module" << endl;
        cout << "2:  Conjugate" << endl;
        cout << "3:  Addition" << endl;
        cout << "4:  Subtraction" << endl;
        cout << "5:  Multiplication" << endl;
        cout << "6:  Division" << endl;
        cout << "7:  Exponentiation:" << endl;
        cout << "8:  Roots" << endl;
        cout << "9:  Test:" << endl;
        cout << "10: EXIT" << endl;
        rozdziel();
        cout << "--> ";
        getline( cin, liczba);
        if(liczba == "") getline( cin, liczba);
        int licz;
        try {
            licz = stoi(liczba);
        }
        catch(...) {cout << "Incorrect Data\n"; continue;}

        switch (licz) {
            case 0:
            {
                double wynik_ge;
                Complex ge;
                try {
                    ge = wczytaj_liczbe();
                    wynik_ge = argument(ge);
                }
                catch(...) {cout << "Incorrect Data\n";break;}

                cout << wynik_ge << endl;
                break;
            }
            case 1:
            {
                double wynik_g;
                Complex g1;
                try {
                    g1 = wczytaj_liczbe();
                    wynik_g = module(g1);
                }
                catch(...) {cout << "Incorrect Data\n";break;}

                cout << wynik_g << endl;
                break;
            }
            case 2:
            {
                Complex wynik_g;
                Complex g1;
                try {
                    g1 = wczytaj_liczbe();
                    wynik_g = conjugate(g1);
                }
                catch(...) {cout << "Incorrect Data\n";break;}

                cout << wynik_g;
                break;
            }
            case 3:
            {
                Complex wynik_a;
                Complex a1;
                Complex a2;
                try {
                    a1 = wczytaj_liczbe();
                    a2 = wczytaj_liczbe();
                    wynik_a = a1 + a2;
                }
                catch(...) {cout << "Incorrect Data\n"; break;}

                cout << wynik_a;
                break;
            }

            case 4:
            {
                Complex wynik_b;
                Complex b1;
                Complex b2;
                try {
                    b1 = wczytaj_liczbe();
                    b2 = wczytaj_liczbe();
                    wynik_b = b1 - b2;
                }
                catch(...) {cout << "Incorrect Data\n";break;}

                cout << wynik_b;
                break;
            }
            case 5:
            {
                Complex wynik_c;
                Complex c1;
                Complex c2;
                try {
                    c1 = wczytaj_liczbe();
                    c2 = wczytaj_liczbe();
                    wynik_c = c1 * c2;
                }
                catch(...) {cout << "Incorrect Data\n";break;}

                cout << wynik_c;
                break;
            }
            case 6:
            {
                Complex wynik_d;
                Complex d1;
                Complex d2;
                try {
                    d1 = wczytaj_liczbe();
                    d2 = wczytaj_liczbe();
                    wynik_d = d1 / d2;
                }
                catch(...) {cout << "Incorrect Data\n";break;}

                cout << wynik_d;
                break;
            }
            case 7:
            {
                Complex wynik_g;
                Complex g1;
                Complex g2;
                try {
                    g1 = wczytaj_liczbe();
                    g2 = wczytaj_liczbe();
                    wynik_g = power_c(g1,g2);
                }
                catch(...) {cout << "Incorrect Data\n";break;}

                cout << wynik_g;
                break;
            }
            case 8:
            {
                Complex e1;
                try {
                    e1 = wczytaj_liczbe();
                }
                catch(...) {cout << "Incorrect Data\n";break;}

                string st1;
                cout << " Enter Degree:" << endl;
                cout << "--> ";
                cin >> st1;
                Complex* wynik_e;
                int st2;
                try {
                    st2 = stoi(st1);
                    st2 = floor(st2);
                    wynik_e = sqrt(e1,st2);
                }
                catch(...) {cout << "Incorrect Data\n";break;}

                for(int i=0;i<st2;i++) {
                    cout << wynik_e[i];
                }
                delete [] wynik_e;
                break;
            }
            case 9:
            {
                test();
                break;
            }
            case 10:
            {
                exit(0);
            }
            default: {
                cout << "Wrong number" << endl;
>>>>>>> master-holder
                break;
            }
        }
    }
<<<<<<< HEAD
}
=======

}


>>>>>>> master-holder
