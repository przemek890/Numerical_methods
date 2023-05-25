#include "headers.h"
//----
void create_matrix(int n,double** mat_m) {
    cout << "Give the list of values that the matrix will take:" << endl;
    for(int j = 0;j<n;j++) {
        for(int k = 0;k<n;k++) {
            double liczba;
            string pom1;
            getline(cin, pom1);
            if(pom1 == "") getline( cin, pom1);
            liczba = stod(pom1);
            mat_m[j][k] = liczba;
        }
    }
}
void print_matrix(double** mat_m,int n) {
    string max = "";
    for(int i=0;i<n;i++) {
        for (int j = 0; j < n; j++) {
            string pom = to_string(mat_m[i][j]);
            if (max.length() < pom.length()) max = pom;
        }
    }

    cout << endl;
    center_word(max,n);
    cout <<"MATRIX__A" << endl << endl;
    cout << "   ";
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << "| ";
            string pom = to_string(mat_m[i][j]);
            cout << pom;
            for(int k=0;k<max.length() - pom.length();k++) cout << " ";
            cout << " |";
        }
        cout <<  endl << "   ";
    }
    cout << "\r";
}
void delete_matrix(double** mat_m,int n) {
    for(int i =0;i<n;i++) {
        delete [] mat_m[i];
    }
    delete [] mat_m;
}
long double determinant(double** mat_m,int n) {
    int* nums;
    int index = 0;
    int start = 0;

    int ilosc = number_of_permutations(n);
    int** result = new int*[ilosc];
    for(int i=0;i<ilosc;i++) result[i] = new int[n];

    nums = give_value(n);
    permute(nums, start, n, result, index);

    string** tablica_str = change_to_string(result,ilosc,n);

    long double wynik = 0;
    for(int i=0;i<ilosc;i++) {
        long double det = 1.0;
        for(int j=0;j<n;j++) {
            int k = result[i][j];
            det *= mat_m[j][k-1];
        }
        int inv = inversions(tablica_str[i],n);
        wynik += pow(-1,inv) * det;
    }
    return wynik;
}
//----