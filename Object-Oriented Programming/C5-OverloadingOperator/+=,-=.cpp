#include <iostream> 

using namespace std;

class cPhanSo
{
private:
    int iTu;
    int iMau;
public:
    cPhanSo() : iTu(0), iMau(1) {}
    cPhanSo(int Tu, int Mau)
    {
        if (Mau == 0)
            Mau = 1;
        this->iTu = Tu;
        this->iMau = Mau;
    }
    cPhanSo(int x) : iTu(x), iMau(1) {}
    friend istream& operator>>(istream& is, cPhanSo& a) 
    {
        cout << "Vui long nhap tu so: ";
        is >> a.iTu;
        do
        {
            cout << "Vui long nhap mau so: ";
            is >> a.iMau;
        } while (a.iMau == 0);

        return is;
    } 
    friend ostream& operator<<(ostream& os, const cPhanSo& a)
    {
        os << a.iTu << "/" << a.iMau;
        return os;
    }
    cPhanSo& operator+=(const cPhanSo& a)
    {
        iTu = iTu*a.iMau+a.iTu*iMau;
        iMau = iMau*a.iMau;
        return *this;
        //Luu y 1: 
        //Vi kieu tra ve cua ham la tham chieu. 
        //Ta co: this += a nen la phai return *this 
        //Neu return {iTu, iMau} la goi constructor tao ra va tra ve 1 ban sao, ban sao nay chi ton tai trong ham. sau khi ket thuc ham se bi xoa.
        //Khi ban sao da bi xoa, Ham tiep tuc tro toi vung nho vua bi xoa -> segmentation fault/sai lech kq
        //Luu y 2:
        //Ta khong dung kieu tra ve cPhanSo vi khi do Ham se tra ve 1 ban sao, vi du nhu khi (a += b) += c.
        //Neu tra ve kieu cPhanSo ta se duoc (a += b) -> 1 phan so nao do roi tiep tuc += c. khi do thi a khong += c ma chi += b.
    } 
    cPhanSo& operator-=(const cPhanSo& a)
    {
        iTu = iTu*a.iMau-a.iTu*iMau;
        iMau = iMau*a.iMau;
        return *this;
    }
    cPhanSo& operator/=(const cPhanSo& a)
    {
        iTu = iTu*a.iMau;
        iMau = iMau*a.iTu;
        return *this;
    }
    cPhanSo& operator*=(const cPhanSo& a)
    {
        iTu = iTu*a.iTu;
        iMau = iMau*a.iMau;
        return *this;
    }
    //Dung friend vi khi do ta cho phep ep kieu ngam dinh 5 + p hay p + 5 deu se ok
    friend cPhanSo operator+(cPhanSo a, const cPhanSo& b)
    {
        a += b;
        return a;
    }
    friend cPhanSo operator-(cPhanSo a, const cPhanSo& b)
    {
        a -= b;
        return a;
    }
    friend cPhanSo operator/(cPhanSo a, const cPhanSo& b)
    {
        a /= b;
        return a;
    }
    friend cPhanSo operator*(cPhanSo a, const cPhanSo& b)
    {
        a *= b;
        return a;
    }
    friend bool operator==(const cPhanSo& a, const cPhanSo& b)
    {
        return ((a.iTu == b.iTu && a.iMau == b.iMau) ? true : false);
    }
    friend bool operator>(const cPhanSo& a, const cPhanSo& b)
    {
        return ((a.iTu*b.iMau > b.iTu*a.iMau) ? true : false);
    }
    friend bool operator<(const cPhanSo& a, const cPhanSo& b)
    {
        return ((a.iTu*b.iMau < b.iTu*a.iMau) ? true : false);
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