<<<<<<< HEAD
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
=======
#include "complex.h"
// -----------------------
void rozdziel() {
    cout << "- - - - - - - - - - - - - - - - - " << endl;
}
// ----
int index(string& buf,char znak) {
    // Funkcja zwraca położenie znaku -> (index), gdy nie znajdzie to zwraca -1
    for(int i = 0; i < buf.length(); i++) {
        if (buf[i] == znak) return i;
    }
    return -1;
}
// ----
void remove_char(string& buf,char znak) {
    // funkcja usuwa wskazany znak z przekazanego jako pierwszy argument bufora
    int dlugosc = buf.length();

    for(int i = 0;i<dlugosc;i++) {
        if(buf[i] == znak) {
            dlugosc--;
            for(int j=i;j<dlugosc;j++) {
                buf[j] = buf[j+1];
            }
            buf[dlugosc] = NULL;
        }
    }
    string nowy_bufor;
    for(int k =0;k < buf.length();k++) {
        if(buf[k] == NULL) {break;}
        else {nowy_bufor += buf[k];}
    }
    buf = nowy_bufor;
    if(index(buf,znak) != -1) remove_char(buf,znak);
}
// ----
void check(string& buf) {
    int dlugosc = buf.length();

    int plus = 0;
    int minus = 0;
    int dot = 0;
    for(int i = 0;i<dlugosc;i++) {
        if(buf[i] < 48 || buf[i] > 57) {
            if(buf[i] == '+') plus++;
            if (plus > 1 ) throw -1;

            if(buf[i] == '-') minus++;
            if (minus > 2 ) throw -1;

            if(buf[i] == '.') dot++;
            if (dot > 2 ) throw -1;

            if (buf[i] == 'i' || buf[i] == 9 || buf[i] == 32 || buf[i] == '+' || buf[i] == '-' || buf[i] == 10 || buf[i] == '.' ) continue;
            else throw -1;

        }
    }
}
// ----
int ile_znakow(string& buf) {
    int liczba_znakow = 0;
    for(int i=0;i<buf.length();i++) {
        if(buf[i] == '-' || buf[i] == '+') liczba_znakow++;
    }
    return liczba_znakow;
}
// ----
string* rozdziel_str(string& buf) {
    /// Przypadki: -a +/- bi || a +/- bi || bi +/- a || -bi +/- a
    string napis_1 = "";
    string napis_2 = "";

    string* tab = new string[2];

    char znak_pierwszy;
    int mod = 0;

    if(ile_znakow(buf) == 2) {
        znak_pierwszy = '-';
        buf = buf.substr(1);
        mod++;
    }

    if(ile_znakow(buf) == 1) {
        int i;
        for(i=0;i<buf.length();i++) {
            if(buf[i] == '+' || buf[i] == '-') break;
            else napis_1 += buf[i];
        }
        for(i;i<buf.length();i++) {napis_2 += buf[i];}

        if(mod == 1) { tab[0] = '-' + napis_1; }
        else { tab[0] = napis_1; }

        if(index(napis_2,'+') != -1) remove_char(napis_2,'+');
        tab[1] = napis_2;

        return tab;
    }
}
// ----
Complex format(string& buf) {
    Complex wynik;
    remove_char(buf,' '); /// Usuń spacje
    remove_char(buf,'\n'); /// Usun przejscia do nowej linii
    remove_char(buf,'\t'); /// Usun przejscia do nowej linii

    /// Jeżeli czynnik zespolony nie występuje
    string buf_temporary = buf.substr(1);
    if(index(buf,'i') == -1) {
        wynik.real = stod(buf);
        wynik.imaginary = 0;
    }
        /// Jeżeli czynnik zespolony występuje sam
    else if(index(buf,'i') != -1 && ile_znakow(buf_temporary) == 0) {
        remove_char(buf,'i');
        if(buf == "-") buf = "-1";
        if(buf == "") buf = "1";
        wynik.real = 0;
        wynik.imaginary = stod(buf);

    }
        /// Jeżeli czynnik zespolony występuje wraz z rzeczywistym
    else {

        string* liczby = new string[2];
        liczby = rozdziel_str(buf);

        if(index(liczby[0],'i') != -1)  {

            remove_char(liczby[0],'i');
            if(liczby[0] == "-") liczby[0] = "-1";
            if(liczby[0] == "") liczby[0] = "1";
            wynik.real = stod(liczby[1]);
            wynik.imaginary = stod(liczby[0]);

        }

        if(index(liczby[1],'i') != -1)  {
            remove_char(liczby[1],'i');
            if(liczby[1] == "-") liczby[1] = "-1";
            if(liczby[1] == "")  liczby[1] = "1";
            wynik.real = stod(liczby[0]);
            wynik.imaginary = stod(liczby[1]);
        }
        delete [] liczby;

        return wynik;
    }
}
// ----
Complex wczytaj_liczbe() {
    cout << " Enter a complex number: " << endl;
    Complex wynik;
    string buf_1;
    cout << "--> ";
    getline(cin, buf_1);
    if(buf_1 == "") getline( cin, buf_1);
    check(buf_1);
    Complex l_1 = format(buf_1);
    return l_1;
}
// ----
>>>>>>> master-holder
double signi_digit(double number) {
    int accuracy = 6;
    string liczba = to_string(number);
    string nr = "";
    for(int i=0;i<accuracy;i++) nr += liczba[i];
    double licz = stod(nr);
    return licz;
}
<<<<<<< HEAD
//----
=======
// ----

>>>>>>> master-holder
