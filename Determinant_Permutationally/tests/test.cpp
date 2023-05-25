#include "test.h"
#include "headers.h"
//----
long double det_gauss_jordan(double** mat, int n)
{
    long double d = 1;
    for (int i = 0; i < n; i++)
    {
        int k = i;
        for (int j = i + 1; j < n; j++)
        {
            if (fabs(mat[j][i]) > fabs(mat[k][i]))
            {
                k = j;
            }
        }
        if (k != i)
        {
            for (int j = 0; j < n; j++)
            {
                swap(mat[i][j], mat[k][j]);
            }
            d = -d;
        }
        if (mat[i][i] == 0)
        {
            return 0;
        }
        d *= mat[i][i];
        for (int j = i + 1; j < n; j++)
        {
            double t = mat[j][i] / mat[i][i];
            for (int k = 0; k < n; k++)
            {
                mat[j][k] -= t * mat[i][k];
            }
        }
    }
    return d;
}
void test() {
    int ts = 0;   // zmienna kontrolna
    int max = 9;  // max rozmiar testowanych macierzy
    int los = 1; // liczba prób losowych

    for(int i=1;i<=max;i++) {
        ///////
        double** mat = new double*[i];
        for(int j =0;j<i;j++) mat[j] = new double[i];
        ///////
        for(int y=0;y<los;y++) {
            for(int k=0;k<i;k++) {
                for(int l=0;l<i;l++) {
                    mat[k][l] = rand() % 2001 - 1000; /// [-1000,1000]
                }
            }
            long double wyz1 = determinant(mat,i);
            long double wyz2 = det_gauss_jordan(mat,i);

            if(abs(signi_digit(wyz1) - signi_digit(wyz2)) < ERROR) ts++;
        }

    }
    if(ts == max * los) cout << "PASSED" << endl;
    else cout << "FAILED" << endl;

}


