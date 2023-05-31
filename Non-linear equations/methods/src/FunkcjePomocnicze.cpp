#include "FunkcjePomocnicze.h"
///-------------------------------------
void rozdziel(){
    cout << "\n- - - - - - - - - - - - " << endl;
}
void wypisz(vector<double>* method,string name) {
    int size1 =  method[0].size();
    int size2 =  method[1].size();
    int size3 =  method[2].size();
    int size4 =  method[3].size();

    cout << "-------------------------------------------\n";
    cout << "  ----> " << name << " :" << endl;
    cout << "-------------------------------------------\n";
    auto max_element = std::max({size1,size2,size3,size4});
    for(int i=0;i<max_element;i++) {
        if(i+1 <10) cout << i+1 << setw(3) << " ";
        else if(i+1 < 100) cout << i+1 << setw(2) << " ";
        else cout << i+1 << setw(1) << " ";

        if(size1>i) cout << fixed << setprecision(7) << method[0][i];
        else cout << setw(9) << " ";
        cout << "  ";

        if(size2>i) cout << fixed << setprecision(7) << method[1][i];
        else cout << setw(9) << " ";
        cout << "  ";

        if(size3>i) cout << fixed << setprecision(7) << method[2][i];
        else cout << setw(9) << " ";
        cout << "  ";

        if(size4>i) cout << fixed << setprecision(7) << method[3][i];
        else cout << setw(9) << " ";
        cout << "  ";


        cout << endl;
    }
    cout << "-------------------------------------------\n";
}
