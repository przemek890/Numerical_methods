#include "headers.h"
//----
void rozdziel() {
    cout << "--------------------------" << endl;
}
void center_word(string max,int n) {
    for(int i=0;i < (max.length() - 7 + 11) * 0.5 * n -1;i++ ) cout << " ";
}
void change(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}
long int number_of_permutations(int n) {
    long int wynik = 1;
    do {
        wynik *= n;
    } while(--n != 0);
    return wynik;
}
int* give_value(int n) {
    int* nums = new int[n];
    for(int i =0;i<n;i++) {
        nums[i] = i + 1;
    }
    return nums;
}
void permute(int *nums, int start, int end, int** result, int &index) {
    if (start == end) {
        for (int i = 0; i < end; i++) {
            result[index][i] = nums[i];
        }
        index++;
    }
    else {
        for (int i = start; i < end; i++) {
            change(nums[start], nums[i]);
            permute(nums, start + 1, end, result, index);
            change(nums[start], nums[i]);
        }
    }
}
string** change_to_string(int** result,int ilosc,int n) {
    string** tablica_str = new string*[ilosc];   // ilosc permutacji
    for(int i=0;i< ilosc;i++) {
        tablica_str[i] = new string[n];         // ilosc elementow permutacji
    }

    for(int i = 0;i < ilosc;i++) {
        for(int j=0;j<n;j++) {
            string el;
            el = to_string(result[i][j]);
            tablica_str[i][j] = el;
        }

    }
    return tablica_str;
}
int inversions(string* tablica_str, int n) {
    int invers = 0;
    for(int j=0;j<n;j++) { // element sprawdzany
        for(int k=j;k<n;k++) { // elementy porównywane
            if(tablica_str[j] > tablica_str[k]) {
                invers++;
            }
        }
    }
    return invers;
}
double signi_digit(double number) {
    int accuracy = 6;
    string liczba = to_string(number);
    string nr = "";
    for(int i=0;i<accuracy;i++) nr += liczba[i];
    double licz = stod(nr);
    return licz;
}
//----