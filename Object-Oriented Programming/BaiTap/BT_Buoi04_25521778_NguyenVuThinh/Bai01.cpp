#include <iostream>

using namespace std;

class cSoPhuc
{
private:
    float iAo;
    float iThuc;

public:
    cSoPhuc(float thuc = 0, float ao = 0) : iThuc(thuc), iAo(ao) {}
    friend istream& operator>>(istream& is, cSoPhuc& a)
    {
        is >> a.iThuc >> a.iAo;    
        return is;
    }
    friend ostream& operator<<(ostream&os, const cSoPhuc& a)
    {
        if (a.iAo < 0)
            os << a.iThuc << " - " << a.iAo << "i";
        else
            os << a.iThuc << " + " << a.iAo << "i";
        return os;
    }
    friend cSoPhuc operator+(const cSoPhuc& a, const cSoPhuc& b)
    {
        cSoPhuc kq;
        kq.iThuc = a.iThuc + b.iThuc;
        kq.iAo = a.iAo + b.iAo;
        return kq;
    }
    friend cSoPhuc operator-(const cSoPhuc& a, const cSoPhuc& b)
    {
        cSoPhuc kq;
        kq.iThuc = a.iThuc - b.iThuc;
        kq.iAo = a.iAo - b.iAo;
        return kq;
    }
    friend cSoPhuc operator*(const cSoPhuc& a, const cSoPhuc& b)
    {
        cSoPhuc kq;
        kq.iThuc = a.iThuc*b.iThuc - a.iAo*b.iAo;
        kq.iAo = a.iThuc*b.iAo + a.iAo*b.iThuc;
        return kq;
    }
    friend cSoPhuc operator/(const cSoPhuc& a, const cSoPhuc& b)
    {
        cSoPhuc kq;
        float mauSo = (b.iThuc*b.iThuc+b.iAo*b.iAo);
        bool coTheChia = (mauSo == 0 ? false : true);
        if (!coTheChia)
        {
            cout << "Vì " << b.iThuc*b.iThuc << " + " << b.iAo*b.iAo << " = 0 nên không thể thực hiện phép chia này";
            kq.iThuc = 0;
            kq.iAo = 0;
        }
        else 
        {
            kq.iThuc = (a.iThuc*b.iThuc+a.iAo*b.iAo)/mauSo;
            kq.iAo = (a.iAo*b.iThuc-a.iThuc*b.iAo)/mauSo;
        }

        return kq;
    }
    friend bool operator==(const cSoPhuc& a, const cSoPhuc& b)
    {
        return (a.iThuc == b.iThuc) && (a.iAo == b.iAo);
    }
    friend bool operator!=(const cSoPhuc& a, const cSoPhuc& b)
    {
        return (a.iThuc != b.iThuc) || (a.iAo != b.iAo);
    }
    float getThuc()
    {
        return iThuc;
    }
    float getAo()
    [
        return iAo;
    ]
};

//sua i thanh f 
//xu ly phan / cho mau bang 0

int main()
{
    cSoPhuc a;
    cSoPhuc b;
    cout << "Vui long nhap phan so phuc a: ";
    cin >> a;
    cout << "Vui long nhap phan so phuc b: ";
    cin >> b;
    
    cout << "(" << a << ")" << " + " << "(" << b << ") = " << "(" << a + b << ")" << endl;
    cout << "(" << a << ")" << " - " << "(" << b << ") = " << "(" << a - b << ")" << endl;
    cout << "(" << a << ")" << " * " << "(" << b << ") = " << "(" << a * b << ")" << endl;
    cout << "(" << a << ")" << " / " << "(" << b << ") = " << "(" << a / b << ")" << endl;

    if (a == b)
        cout << "2 số phức bằng nhau";
    else   
        cout << "2 số phức khác nhau";

    return 0;

}