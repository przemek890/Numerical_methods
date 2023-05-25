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
                break;
            }
        }
    }
}
