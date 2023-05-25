#include "complex.h"

/// Konstruktory
Complex::Complex() {
    this->real = 0;
    this->imaginary = 0;
}
Complex::Complex(double a, double b){
    this->real = a;
    this->imaginary = b;
}

/// Gettery
double Complex::getter_real() {return this->real;}
double Complex::getter_imaginary() {return this->imaginary;}

/// Funkcje operatorowe
ostream& operator<<(ostream& str, Complex& obj) {

    /// Osie Ox & Oy:
    if (abs(obj.imaginary) < ERROR && abs(obj.real) < ERROR) str <<"Wynik: " << 0 <<  endl;
    else if (abs(obj.imaginary) < ERROR) str <<"Wynik: " << obj.real <<  endl;
    else if (abs(obj.imaginary) > ERROR && abs(obj.real) < ERROR && (abs(obj.imaginary - 1) > ERROR && abs(obj.imaginary + 1) > ERROR)) str <<"Wynik: " << obj.imaginary << "i" <<  endl;

        /// Punkty (a,1) & (a,-1) -> (a) != (0):
    else if (abs(obj.imaginary - 1) < ERROR && abs(obj.real) < ERROR) str <<"Wynik: " << "i" <<endl;
    else if (abs(obj.imaginary + 1) < ERROR && abs(obj.real) < ERROR) str <<"Wynik: " << "-i" <<endl;
    else if (abs(obj.imaginary + 1) < ERROR && abs(obj.real) > ERROR) str <<"Wynik: " << obj.real << " - " << "i" <<endl;
    else if (abs(obj.imaginary - 1) < ERROR && abs(obj.real) > ERROR) str <<"Wynik: " << obj.real << " + " << "i" <<endl;

        /// Others:
    else if (obj.imaginary < ERROR && abs(obj.real) > ERROR && abs(obj.imaginary + 1) > ERROR) str <<"Wynik: " << obj.real << " - " << abs(obj.imaginary) << "i" << endl;
    else if (obj.imaginary > ERROR && abs(obj.real) > ERROR && abs(obj.imaginary - 1 ) > ERROR) str <<"Wynik: " << obj.real << " + " << abs(obj.imaginary) << "i" <<endl;

    return str;
}
Complex operator+(Complex obj1,Complex obj2) {
    Complex wynik;
    wynik.real = obj1.real + obj2.real;
    wynik.imaginary = obj1.imaginary + obj2.imaginary;
    return wynik;
}
Complex operator-(Complex obj1,Complex obj2) {
    Complex wynik;
    wynik.real = obj1.real - obj2.real;
    wynik.imaginary = obj1.imaginary - obj2.imaginary;
    return wynik;
}
Complex operator*(Complex obj1,Complex obj2) {
    Complex wynik;
    double r_1 = sqrt(pow(obj1.real,2) + pow(obj1.imaginary,2));
    double r_2 = sqrt(pow(obj2.real,2) + pow(obj2.imaginary,2));

    double fi_1 = argument(obj1);
    double fi_2 = argument(obj2);
    /// Nowy kąt:
    double fi = fi_1 + fi_2;

    wynik.real = (r_1 * r_2) * cos(fi);
    wynik.imaginary = (r_1 * r_2) * sin(fi);

    return wynik;
}
Complex operator/(Complex obj1,Complex obj2) {
    Complex wynik;
    if(obj2.real == 0 && obj2.imaginary == 0 ) throw -1;
    double r_1 = sqrt(pow(obj1.real,2) + pow(obj1.imaginary,2));
    double r_2 = sqrt(pow(obj2.real,2) + pow(obj2.imaginary,2));

    double fi_1 = argument(obj1);
    double fi_2 = argument(obj2);
    /// Nowy kąt:
    double fi = fi_1 - fi_2;

    wynik.real = (r_1 / r_2) * cos(fi);
    wynik.imaginary = (r_1 / r_2) * sin(fi);
    return wynik;
}
Complex power_c(Complex obj1, Complex obj2) {
    Complex Potega;
    // Exceptions:
    if(obj1.imaginary == 0 && obj2.imaginary == 0 && obj2.real ==0 && obj1.real == 0) {cout << "Undefined symbol: 0^0" << endl; throw -1; }
    if(obj1.imaginary == 0 && obj1.real == 0) {Potega.real = 0;Potega.imaginary = 0;return Potega;}
    // ----
    Complex pom;
    double a = obj1.real;
    double b = obj1.imaginary;
    double c = obj2.real;
    double d = obj2.imaginary;

    double r = sqrt(pow(a,2) + pow(b,2)); /// a^2 + b^2
    double arg = argument(obj1);

    Potega.real = pow(r,c) * pow(E,-d*arg) * (cos(c*arg + d*log(r)));
    Potega.imaginary = pow(r,c) * pow(E,-d*arg) * (sin(c*arg + d*log(r)));

    return Potega;
}
Complex* sqrt(Complex obj1,int n) {
    double r = sqrt(pow(obj1.real,2) + pow(obj1.imaginary,2));

    if (obj1.imaginary == 0 && obj1.real == 0) {
        Complex* tab = new Complex;
        tab[0].real = 0;
        tab[0].imaginary = 0;
        return tab;
    }

    double fi = argument(obj1);

    double potega = 1/static_cast<double>(n);

    Complex* tab = new Complex[n];
    for(int i = 0;i<n;i++) {
        tab[i].real = pow(r,potega) * cos((fi + 2 * PI * i)/n);
        tab[i].imaginary = pow(r,potega) * sin((fi + 2 * PI * i)/n);
    }
    return tab;
}
Complex conjugate(Complex obj1) {
    Complex wynik;
    wynik.real = obj1.getter_real();
    wynik.imaginary = - obj1.getter_imaginary();
    return wynik;
}
double module(Complex obj1) {
    return sqrt(pow(obj1.getter_real(),2) + pow(obj1.getter_imaginary(),2));
}
double argument(Complex obj1) {
    double arg;
    double a = obj1.getter_real();
    double b = obj1.getter_imaginary();

    if (a > 0) arg = atan(b/a);
    else if (a < 0 && b >= 0) arg = atan(b/a) + PI;
    else if (a < 0 && b < 0) arg = atan(b/a) - PI;
    else if (a == 0 && b > 0) arg = PI/2;
    else if (a == 0 && b == 0) arg = 0;
    else arg = -PI/2;

    return arg;

}