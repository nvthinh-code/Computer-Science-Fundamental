#include <iostream>
#include <cmath>

using namespace std;

class cPhanSo
{
private:
    int iTu;
    int iMau;

    int GCD(int a, int b)
    {
        a = abs(a);
        b = abs(b);
        while (b != 0)
        {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

public:
    void rutGon()
    {
        if (iTu == 0)
        {
            iMau = 1;
            return;
        }
        int ucln = GCD(iTu, iMau);
        iTu /= ucln;
        iMau /= ucln;

        if (iMau < 0)
        {
            iTu = -iTu;
            iMau = -iMau;
        }
    }

    cPhanSo() : iTu(0), iMau(1) {}

    cPhanSo(int Tu, int Mau)
    {
        if (Mau == 0)
            Mau = 1;
        this->iTu = Tu;
        this->iMau = Mau;
        this->rutGon();
    }

    cPhanSo(int x) : iTu(x), iMau(1) {}

    friend istream &operator>>(istream &is, cPhanSo &a)
    {
        cout << "Vui long nhap tu so: ";
        is >> a.iTu;
        do
        {
            cout << "Vui long nhap mau so: ";
            is >> a.iMau;
        } while (a.iMau == 0);

        a.rutGon();
        return is;
    }

    friend ostream &operator<<(ostream &os, const cPhanSo &a)
    {
        if (a.iMau == 1)
            os << a.iTu;
        else
            os << a.iTu << "/" << a.iMau;
        return os;
    }

    friend cPhanSo operator+(const cPhanSo &a, const cPhanSo &b)
    {
        cPhanSo kq(a.iTu * b.iMau + b.iTu * a.iMau, a.iMau * b.iMau);
        kq.rutGon();
        return kq;
    }

    friend cPhanSo operator-(const cPhanSo &a, const cPhanSo &b)
    {
        cPhanSo kq(a.iTu * b.iMau - b.iTu * a.iMau, a.iMau * b.iMau);
        kq.rutGon();
        return kq;
    }

    friend cPhanSo operator/(const cPhanSo &a, const cPhanSo &b)
    {
        cPhanSo kq(a.iTu * b.iMau, a.iMau * b.iTu);
        kq.rutGon();
        return kq;
    }

    friend cPhanSo operator*(const cPhanSo &a, const cPhanSo &b)
    {
        cPhanSo kq(a.iTu * b.iTu, a.iMau * b.iMau);
        kq.rutGon();
        return kq;
    }

    friend bool operator==(const cPhanSo &a, const cPhanSo &b)
    {
        return (a.iTu * b.iMau == b.iTu * a.iMau);
    }

    friend bool operator>(const cPhanSo &a, const cPhanSo &b)
    {
        return (a.iTu * b.iMau > b.iTu * a.iMau);
    }

    friend bool operator<(const cPhanSo &a, const cPhanSo &b)
    {
        return (a.iTu * b.iMau < b.iTu * a.iMau);
    }
};

int main()
{
    // Phan so + phan so
    cPhanSo p;
    cPhanSo q;
    cin >> p;
    cin >> q;
    cout << p << " + " << q << " = " << p + q << endl;
    cout << p << " - " << q << " = " << p - q << endl;
    cout << p << " * " << q << " = " << p * q << endl;
    cout << p << " / " << q << " = " << p / q << endl;

    // Phan so + so nguyen (hoac nguoc lai)
    int x;
    cout << "Vui long nhap so nguyen x: ";
    cin >> x;
    cout << p << " + " << x << " = " << p + x << endl;
    cout << x << " + " << p << " = " << x + p << endl;

    // So sanh 2 phan so
    if (p > q)
        cout << p << " > " << q;
    else if (p < q)
        cout << p << " < " << q;
    else
        cout << p << " = " << q;

    return 0;
}