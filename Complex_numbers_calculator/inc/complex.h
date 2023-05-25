// Created by przemek890
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// ----
#define PI 3.14159265358979323846264
#define E  2.71828182845904523536028
#define ERROR 10e-6

#ifndef ZESPOLONE_H
#define ZESPOLONE_H

class Complex {
private:
    double real;
    double imaginary;
public:
    friend ostream& operator<<(ostream& str, Complex& obj);
    friend Complex operator+(Complex obj1,Complex obj2);
    friend Complex operator*(Complex obj1,Complex obj2);
    friend Complex operator-(Complex obj1,Complex obj2);
    friend Complex operator/(Complex obj1,Complex obj2);
    friend Complex power_c(Complex obj1,Complex obj2);
    friend Complex* sqrt(Complex obj1,int n);
    friend Complex format(string& buf);
    friend Complex wczytaj_liczbe();
    friend Complex conjugate(Complex obj1);
    friend double module(Complex obj1);
    friend double argument(Complex obj1);
    Complex();
    Complex(double a, double b);
    double getter_real();
    double getter_imaginary();
};
/// --------------------------------------
void rozdziel();
int index(string& buf,char znak);
void remove_char(string& buf,char znak);
int ile_znakow(string& buf);
string* rozdziel_str(string& buf);
Complex format(string& buf);
Complex wczytaj_liczbe();
double signi_digit(double number);


#endif // ZESPOLONE_H
// ----
