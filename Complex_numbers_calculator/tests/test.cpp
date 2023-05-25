#include "test.h"
<<<<<<< HEAD
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


=======
void test() {
    string tab_s_1[] = {"1 - 9i", "i + 1   ", "-i    ", "1    ", "-1 ", "-1-i  ", "-i - 1", "i + 1 ", "1+i    ", "7i - 9",
                        "9-7i", "5i -77    ", "-56 -9i  ", "8i", "9", "-9.867i    -8"};
    string tab_s_2[] = {"1", "-1-i", "-i - 1", "i + 1", "1+i", "7i - 9", "9-7i  ", "5i -77", "-56 -9i", "8i    ",
                        "9   ", "-9.867i -7", "i        ", "-i", "1", "-1           "};

    ///////////////////
    int size = 9;
    int st = 4;
    int passed[size];
    memset(passed, 0, sizeof(passed));
    ///////////////////
    int n1 = sizeof(tab_s_1) / sizeof(tab_s_1[0]);
    int n2 = sizeof(tab_s_1) / sizeof(tab_s_1[0]);
    for(int u=0;u<n1;u++) {
        for (int i = 0; i < n2; i++) {
            //0. ---------------------------------------
            double wynik_a1;
            double wynik_a2;
            Complex a_1;
            Complex a_2;
            a_1 = format(tab_s_1[u]);
            a_2 = format(tab_s_2[i]);
            wynik_a1 = argument(a_1);
            wynik_a2 = argument(a_2);

            complex<double> li1(a_1.getter_real(), a_1.getter_imaginary());
            complex<double> li2(a_2.getter_real(), a_2.getter_imaginary());
            double aa1 = arg(li1);
            double aa2 = arg(li2);

            if(abs(aa1 - wynik_a1) < ERROR && abs(aa2 - wynik_a2) < ERROR) passed[0]++;
            //1. ---------------------------------------
            double wynik_b1;
            double wynik_b2;
            Complex b_1;
            Complex b_2;
            b_1 = format(tab_s_1[u]);
            b_2 = format(tab_s_2[i]);
            wynik_b1 = module(b_1);
            wynik_b2 = module(b_2);

            complex<double> li3(b_1.getter_real(), b_1.getter_imaginary());
            complex<double> li4(b_2.getter_real(), b_2.getter_imaginary());
            double bb1 = abs(li3);
            double bb2 = abs(li4);

            if(abs(bb1 - wynik_b1) < ERROR && abs(bb2 - wynik_b2) < ERROR) passed[1]++;

            //2. ---------------------------------------
            Complex wynik_c1;
            Complex wynik_c2;
            Complex c_1;
            Complex c_2;
            c_1 = format(tab_s_1[u]);
            c_2 = format(tab_s_2[i]);
            wynik_c1 = conjugate(c_1);
            wynik_c2 = conjugate(c_2);

            complex<double> li5(c_1.getter_real(), c_1.getter_imaginary());
            complex<double> li6(c_2.getter_real(), c_2.getter_imaginary());
            complex<double> li7 = conj(li5);
            complex<double> li8 = conj(li6);

            if(abs(li7.real() - wynik_c1.getter_real()) < ERROR && abs(li7.imag() - wynik_c1.getter_imaginary()) < ERROR &&
               abs(li8.real() - wynik_c2.getter_real()) < ERROR && abs(li8.imag() - wynik_c2.getter_imaginary()) < ERROR ) passed[2]++;
            //3. ---------------------------------------
            Complex wynik_d;
            Complex d_1;
            Complex d_2;
            d_1 = format(tab_s_1[u]);
            d_2 = format(tab_s_2[i]);
            wynik_d = d_1 + d_2;

            complex<double> li9(d_1.getter_real(), d_1.getter_imaginary());
            complex<double> li10(d_2.getter_real(), d_2.getter_imaginary());
            complex<double> li11 = li9 + li10;

            if(abs(li11.real() - wynik_d.getter_real()) < ERROR && abs(li11.imag() - wynik_d.getter_imaginary()) < ERROR) passed[3]++;
            //4. ---------------------------------------
            Complex wynik_e;
            Complex e_1;
            Complex e_2;
            e_1 = format(tab_s_1[u]);
            e_2 = format(tab_s_2[i]);
            wynik_e = e_1 - e_2;

            complex<double> li12(e_1.getter_real(), e_1.getter_imaginary());
            complex<double> li13(e_2.getter_real(), e_2.getter_imaginary());
            complex<double> li14 = li12 - li13;

            if(abs(li14.real() - wynik_e.getter_real()) < ERROR && abs(li14.imag() - wynik_e.getter_imaginary()) < ERROR) passed[4]++;
            //5. ---------------------------------------
            Complex wynik_f;
            Complex f_1;
            Complex f_2;
            f_1 = format(tab_s_1[u]);
            f_2 = format(tab_s_2[i]);
            wynik_f= f_1 * f_2;

            complex<double> li15(f_1.getter_real(), f_1.getter_imaginary());
            complex<double> li16(f_2.getter_real(), f_2.getter_imaginary());
            complex<double> li17 = li15 * li16;

            if(abs(li17.real() - wynik_f.getter_real()) < ERROR && abs(li17.imag() - wynik_f.getter_imaginary()) < ERROR) passed[5]++;
            //6. ---------------------------------------
            Complex wynik_g;
            Complex g_1;
            Complex g_2;
            g_1 = format(tab_s_1[u]);
            g_2 = format(tab_s_2[i]);
            wynik_g = g_1 / g_2;

            complex<double> li18(g_1.getter_real(), g_1.getter_imaginary());
            complex<double> li19(g_2.getter_real(), g_2.getter_imaginary());
            complex<double> li20 = li18 / li19;

            if(abs(li20.real() - wynik_g.getter_real()) < ERROR && abs(li20.imag() - wynik_g.getter_imaginary()) < ERROR) passed[6]++;
            //7. ---------------------------------------
            Complex wynik_h;
            Complex h_1;
            Complex h_2;
            h_1 = format(tab_s_1[u]);
            h_2 = format(tab_s_2[i]);
            wynik_h = power_c(h_1,h_2);

            complex<double> li21(h_1.getter_real(), h_1.getter_imaginary());
            complex<double> li22(h_2.getter_real(), h_2.getter_imaginary());
            complex<double> li23 = pow(li21, li22);

            if(abs(signi_digit(li23.real()) - signi_digit(wynik_h.getter_real())) < ERROR && abs(signi_digit(li23.imag()) -
            signi_digit(wynik_h.getter_imaginary())) < ERROR) passed[7]++;

            //8. ---------------------------------------
            Complex *wynik_i;
            Complex *wynik_j;
            Complex i_1;
            Complex i_2;
            i_1 = format(tab_s_1[u]);
            i_2 = format(tab_s_2[i]);
            wynik_i = sqrt(i_1, st);
            wynik_j = sqrt(i_2, st);

            complex<double> li24(i_1.getter_real(), i_1.getter_imaginary());
            complex<double> li25(i_2.getter_real(), i_2.getter_imaginary());

            double r1 = abs(li24);
            double theta1 = arg(li24);
            double r2 = abs(li25);
            double theta2 = arg(li25);

            for(int k=0;k<st;k++) {
                int q1 = 0,q2 = 0;
                double pot = 1/static_cast<double>(st);
                complex<double> li26 = polar(pow(r1,pot), (theta1 + 2 * k * PI)/st);
                complex<double> li27 = polar(pow(r2,pot), (theta2 + 2 * k * PI)/st);
                for(int l=0;l<st;l++) {
                    if(abs(li26.real() - wynik_i[l].getter_real()) < ERROR && abs(li26.imag() - wynik_i[l].getter_imaginary()) < ERROR && q1 == 0) {
                        passed[8]++;
                        q1++;
                    }
                    if(abs(li27.real() - wynik_j[l].getter_real()) < ERROR && abs(li27.imag() - wynik_j[l].getter_imaginary()) < ERROR && q2 == 0) {
                        passed[8]++;
                        q2++;
                    }
                }
            }

            delete[] wynik_i;
            delete[] wynik_j;
        }
    }

    //---------------------------------------
    //---------------------------------------
    //---------------------------------------

    for(int i=0;i<size;i++) {
        if(i == 0 && passed[i] == n1*n2) cout << "'arg' \t -> PASSED" << endl;
        else if(i == 0 && passed[i] != n1*n2) cout << "'arg' \t -> FAILED" << endl;
        if(i == 1 && passed[i] == n1*n2) cout << "'mod' \t -> PASSED" << endl;
        else if(i == 1 && passed[i] != n1*n2) cout << "'mod' \t -> FAILED" << endl;
        if(i == 2 && passed[i] == n1*n2) cout << "'conj' \t -> PASSED" << endl;
        else if(i == 2 && passed[i] != n1*n2) cout << "'conj' \t -> FAILED" << endl;
        if(i == 3 && passed[i] == n1*n2) cout << "'+' \t -> PASSED" << endl;
        else if(i == 3 && passed[i] != n1*n2) cout << "'+' \t -> FAILED" << endl;
        if(i == 4 && passed[i] == n1*n2) cout << "'-' \t -> PASSED" << endl;
        else if(i == 4 && passed[i] != n1*n2) cout << "'-' \t -> FAILED" << endl;
        if(i == 5 && passed[i] == n1*n2) cout << "'*' \t -> PASSED" << endl;
        else if(i == 5 && passed[i] != n1*n2) cout << "'*' \t -> FAILED" << endl;
        if(i == 6 && passed[i] == n1*n2) cout << "'/' \t -> PASSED" << endl;
        else if(i == 6 && passed[i] != n1*n2) cout << "'/' \t -> FAILED" << endl;
        if(i == 7 && passed[i] == n1*n2) cout << "'**' \t -> PASSED" << endl;
        else if(i == 7 && passed[i] != n1*n2) cout << "'**' \t -> FAILED" << endl;
        if(i == 8 && passed[i] == 2*st*n1*n2) cout << "'sqrt' \t -> PASSED" << endl;
        else if(i == 8 && passed[i] != 2*st*n1*n2) cout << "'sqrt' \t -> FAILED" << endl;
    }

    /// Wyniki:
    // 0. test_arg   POZYTYWNY
    // 1. test_mod   POZYTYWNY
    // 2. test_conj  POZYTYWNY
    // 3. test_+     POZYTYWNY
    // 4. test_-     POZYTYWNY
    // 5. test_*     POZYTYWNY
    // 6. test_/     POZYTYWNY
    // 7. test_sqrt  POZYTYWNY
    // 8. test_pow_c POZYTYWNY

}

>>>>>>> master-holder
