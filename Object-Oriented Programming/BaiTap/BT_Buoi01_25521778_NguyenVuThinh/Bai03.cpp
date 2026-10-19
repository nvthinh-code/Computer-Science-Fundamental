//MSSV: 25521778   
//Họ và tên sinh viên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: CNVN.2
#include <iostream>
#include <cmath>
using namespace std;

struct fraction {
    int numerator, denominator;
};

int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

void input(fraction& x) {
    cin >> x.numerator >> x.denominator;
}

void addition(fraction a, fraction b) {
    fraction c;
    c.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
    c.denominator = a.denominator * b.denominator;
    if (c.numerator == 0) {
        cout << 0;
        return;
    }
    int commonDivisor_c = GCD(c.numerator, c.denominator);
    c.numerator = c.numerator / commonDivisor_c;
    c.denominator = c.denominator / commonDivisor_c;
    if (c.denominator == 1) cout << c.numerator;
    else if (c.denominator == -1) cout << -c.numerator;
    else {
        if (c.denominator < 0) {
            cout << -c.numerator << "/" << -c.denominator;
        }
        else cout << c.numerator << "/" << c.denominator;
    }
}

void subtraction(fraction a, fraction b) {
    fraction c;
    c.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    c.denominator = a.denominator * b.denominator;
    if (c.numerator == 0) {
        cout << 0;
        return;
    }
    int commonDivisor_c = GCD(c.numerator, c.denominator);
    c.numerator = c.numerator / commonDivisor_c;
    c.denominator = c.denominator / commonDivisor_c;
    if (c.denominator == 1) cout << c.numerator;
    else if (c.denominator == -1) cout << -c.numerator;
    else {
        if (c.denominator < 0) {
            cout << -c.numerator << "/" << -c.denominator;
        }
        else cout << c.numerator << "/" << c.denominator;
    }
}

void multiplication(fraction a, fraction b) {
    fraction c;
    c.numerator = a.numerator * b.numerator;
    c.denominator = a.denominator * b.denominator;
    if (c.numerator == 0) {
        cout << 0;
        return;
    }
    int commonDivisor_c = GCD(c.numerator, c.denominator);
    c.numerator = c.numerator / commonDivisor_c;
    c.denominator = c.denominator / commonDivisor_c;
    if (c.denominator == 1) cout << c.numerator;
    else if (c.denominator == -1) cout << -c.numerator;
    else {
        if (c.denominator < 0) {
            cout << -c.numerator << "/" << -c.denominator;
        }
        else cout << c.numerator << "/" << c.denominator;
    }
}

void division(fraction a, fraction b) {
    fraction c;
    c.numerator = a.numerator * b.denominator;
    c.denominator = a.denominator * b.numerator;
    if (c.numerator == 0) {
        cout << 0;
        return;
    }
    int commonDivisor_c = GCD(c.numerator, c.denominator);
    c.numerator = c.numerator / commonDivisor_c;
    c.denominator = c.denominator / commonDivisor_c;
    if (c.denominator == 1) cout << c.numerator;
    else if (c.denominator == -1) cout << -c.numerator;
    else {
        if (c.denominator < 0) {
            cout << -c.numerator << "/" << -c.denominator;
        }
        else cout << c.numerator << "/" << c.denominator;
    }
}

int main(){
    fraction a, b;
    input(a); input(b);
    addition(a, b);
    cout << endl;
    subtraction(a, b);
    cout << endl;
    multiplication(a, b);
    cout << endl;
    division(a, b);

    return 0;
}
