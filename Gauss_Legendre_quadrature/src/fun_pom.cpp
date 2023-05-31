#include "fun_pom.h"
vector<double> nth_derivative(vector<double> a, int n) {
    vector<double> res = a;
    int len = a.size();
    for (int k = 0; k < n; k++) {
        vector<double> tmp(len - 1);
        for (int i = 1; i < len; i++) {
            tmp[i - 1] = i * a[i];
        }
        len--;
        res = tmp;
        a = tmp;
    }
    return res;
}
vector<double> trojkat_pascala(int n) {
    std::vector<double> row(n+1, 1);
    for(int i=1; i<n; i++){
        for(int j=i; j>=1; j--){
            row[j] += row[j-1];
        }
    }
    return row;
}
void zmien_znak(vector<double>& wsp) {
    for(int i=0; i<wsp.size(); i++){
        if(i % 2 == 0 && wsp.size() > 1) wsp[i] = -wsp[i];
    }
}
std::vector<double> dodawanie_zer(std::vector<double>& wsp) {
    std::vector<double> result;
    for(int i=0; i<wsp.size(); i++){
        result.push_back(wsp[i]);
        if(i != wsp.size()-1){
            result.push_back(0);
        }
    }
    return result;
}
int silnia(int n) {
    int result = 1;
    for(int i=2; i<=n; i++){
        result *= i;
    }
    return result;
}
void rozdziel() {
    cout << " - - - - - - - - - - - - - " << endl;
}

double Gausse_lagendre(double (*f)(double),double a, double b, int n) {

    vector<double> x(n), w(n);
    switch(n) {
        case 2:
        {
            x[0] = -0.5773502691896257645092;
            x[1] = -x[0];
            w[0] = 1.0;
            w[1] = 1.0;
            break;
        }
        case 3:
        {
            x[0] = -0.7745966692414833770359;
            x[1] = 0.0;
            x[2] = -x[0];
            w[0] = 5.0/9.0;
            w[1] = 8.0/9.0;
            w[2] = 5.0/9.0;

            break;
        }
        case 4:
        {
            x[0] = -0.861136311594052575224;
            x[1] = -0.3399810435848562648027;
            x[2] = -x[1];
            x[3] = -x[0];
            w[0] = 0.3478548451374538573731;
            w[1] = 0.6521451548625461426269;
            w[2] = 0.6521451548625461426269;
            w[3] = 0.3478548451374538573731;
            break;
        }
        case 5:
        {
            x[0] = -0.9061798459386639927976;
            x[1] = -0.5384693101056830910363;
            x[2] = 0.0;
            x[3] = -x[1];
            x[4] = -x[0];
            w[0] = 0.2369268850561890875143;
            w[1] = 0.4786286704993664680413;
            w[2] = 0.5688888888888888888889;
            w[3] = 0.4786286704993664680413;
            w[4] = 0.2369268850561890875143;
            break;
        }
        case 6:
        {
            x[0] = -0.9324695142031520278123;
            x[1] = -0.661209386466264513661;
            x[2] = -0.2386191860831969086305;
            x[3] = -x[2];
            x[4] = -x[1];
            x[5] = -x[0];
            w[0] = 0.1713244923791703450403;
            w[1] = 0.3607615730481386075698;
            w[2] = 0.4679139345726910473899;
            w[3] = w[2];
            w[4] = w[1];
            w[5] = w[0];
            break;
        }
        case 7:
        {
            x[0] = -0.9491079123427585245262;
            x[1] =-0.7415311855993944398639;
            x[2] =-0.4058451513773971669066;
            x[3] = 0.0;
            x[4] = 0.4058451513773971669066;
            x[5] = 0.7415311855993944398639;
            x[6] = 0.9491079123427585245262;


            w[0] = 0.1294849661688696932706;
            w[1] = 0.2797053914892766679015;
            w[2] = 0.38183005050511894495;
            w[3] = 0.417959183673469387755;
            w[4] = 0.38183005050511894495;
            w[5] = 0.279705391489276667901;
            w[6] = 0.129484966168869693271;
            break;
        }
        default:
        {
            cout << "Range error" << endl;
            return 0;
        }
    }


    double integral = 0.0;
    double c1 = (b + a) / 2.0;
    double c2 = (b - a) / 2.0;
    for (int i = 0; i < n; i++) {
        double t = c2 * x[i] + c1;
        integral += w[i] * (*f)(t); // w[i] * f(ti)
    }
    integral *= c2;

    return integral;
}
double Wielomian_Lagrange(int n) {
    vector<double> pom = trojkat_pascala(n);
    zmien_znak(pom);
    vector<double> pom2 = dodawanie_zer(pom);
    vector<double> pom3 = nth_derivative(pom2,n);
    double p1 = pow(2,n);
    double p2 = silnia(n);
    double p3 = 1.0/(p1 * p2);
    for(int i=0;i<=n;i++)
        pom3[i] *= p3;

    cout << "Współczynniki wielomianu Legendre W(" << n << ") : ";
    for(auto i: pom3) cout << i << " ";
    cout << endl;
}