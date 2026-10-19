//MSSV: 25521778   
//Họ và tên sinh viên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: CNVN.2
#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

//Viết chương trình cho phép người dùng nhập vào hai phân số, tìm phân số lớn nhất và xuất kết quả ra màn hình.

struct fraction {
    int numerator, denominator;
};

void input(fraction &x) {
    cin >> x.numerator >> x.denominator;
}

ll GCD(ll a, ll b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

void compareFraction(fraction a, fraction b) {
    fraction result;
    result.numerator = a.numerator * b.denominator - b.numerator * a.denominator;
    result.denominator = a.denominator * b.denominator;
    double temp = result.numerator / result.denominator;
    if (temp >= 0) {
        ll commonDivisor_a = GCD(a.numerator, a.denominator);
        a.numerator = a.numerator / commonDivisor_a;
        a.denominator = a.denominator / commonDivisor_a;
        if (a.denominator == 1) cout << a.numerator;
        else {
            cout << a.numerator << "/" << a.denominator;
        }
    }
    else {
        ll commonDivisor_b = GCD(b.numerator, b.denominator);
        b.numerator = b.numerator / commonDivisor_b;
        b.denominator = b.denominator / commonDivisor_b;
        if (b.denominator == 1) cout << b.numerator;
        else {
            cout << b.numerator << "/" << b.denominator;
        }
    }
}

int main(){
    fraction a, b;
    input(a); input(b);
    compareFraction(a, b);

    return 0;
}
