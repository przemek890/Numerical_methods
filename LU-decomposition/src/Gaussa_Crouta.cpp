#include "Doolittle.h"
#include "Front_back.h"

vector<vector<double>> A1 = {{60, 30, 20},{30, 20, 15},{20, 15, 12}};
vector<vector<double>> A2 = {{3, 0,  1},{0, -1, 3},{1, 3,  0}};
vector<vector<double>> A3 = {{2, 1,  -2},{4, 2,  -1},{6, 3,  11}};

int n1 = A1.size();
int n2 = A2.size();
int n3 = A3.size();

/// Macierz L i U
vector<vector<double>> L1(n1, vector<double>(n1, 0));
vector<vector<double>> U1(n1, vector<double>(n1, 0));

vector<vector<double>> L2(n2, vector<double>(n2, 0));
vector<vector<double>> U2(n2, vector<double>(n2, 0));

vector<vector<double>> L3(n3, vector<double>(n3, 0));
vector<vector<double>> U3(n3, vector<double>(n3, 0));

///----------------------------------------------------------------
vector<vector<double>> Troj_1 =  { {1, 0, 0 },  /// W przod (macierz dolna)
                                   {2, 3, 0 },
                                   {4, 5, 6 } };

vector<vector<double>> Troj_2 =  { {1, 2, 3 },  /// Wstecz (macierz gorna)
                                   {0, 4, 5 },
                                   {0, 0, 6 } };

vector<double> Wol_1 = {1, 2, 3};
vector<double> Wol_2 = {1, 2, 3};

int main() {
    //-----------------------------------
    doolittle(A1, L1, U1);
    cout << "Matrix A1: " << endl;
    print_matrix(A1);
    cout << "Matrix L1: " << endl;
    print_matrix(L1);
    cout << "Matrix U1: " << endl;
    print_matrix(U1);
    //-----------------------------------
    rozdziel();
    doolittle(A2, L2, U2);
    cout << "Matrix A2: " << endl;
    print_matrix(A2);
    cout << "Matrix L2: " << endl;
    print_matrix(L2);
    cout << "Matrix U2: " << endl;
    print_matrix(U2);
    //-----------------------------------
    rozdziel();
    doolittle(A3, L3, U3);
    cout << "Matrix A3: " << endl;
    print_matrix(A3);
    cout << "Matrix L3: " << endl;
    print_matrix(L3);
    cout << "Matrix U3: " << endl;
    print_matrix(U3);
    //-----------------------------------
    rozdziel();
    cout << endl;

    vector<double> x_przod_1 = podstawianiePrzod(Troj_1, Wol_1);
    cout << "Rozwiązanie (podstawianie w przód): ";
    for (float i : x_przod_1) cout << i << " ";
    cout << endl << endl;

    //-------------------

    vector<double> x_wstecz_1 = podstawianieWstecz(Troj_2, Wol_2);
    cout << "Rozwiązanie (podstawianie wstecz): ";
    for (float i : x_wstecz_1) cout << i << " ";
    cout << endl;

    return 0;
}


