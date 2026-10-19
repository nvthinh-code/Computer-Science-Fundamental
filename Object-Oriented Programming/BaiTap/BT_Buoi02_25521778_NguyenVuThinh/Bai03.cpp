//MSSV: 25521778   
//Họ và tên sinh viên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: CNVN.2
#include <iostream> 

using namespace std;

class cSoPhuc
{
    private:
        int iThuc;
        int iAo;
    public:
        cSoPhuc()
        {
            iThuc = 0;
            iAo = 0;
        }
        cSoPhuc(int a, int b)
        {
            iThuc = a;
            iAo = b;
        }
        void Nhap()
        {
            cin >> iThuc >> iAo;
        }
        void Xuat()
        {
            cout << iThuc << " " << iAo << endl;
        }
        void SetThuc(int iThuc)
        {
            this->iThuc = iThuc;
        }
        void SetAo(int iAo)
        {
            this->iAo = iAo;
        }
        int GetThuc()
        {
            return iThuc;
        }
        int GetAo()
        {
            return iAo;
        }
        cSoPhuc Cong(cSoPhuc a)
        {
            cSoPhuc kq;
            kq.iThuc = iThuc + a.iThuc;
            kq.iAo = iAo + a.iAo;
            return kq; 
        }
        cSoPhuc Tru(cSoPhuc a)
        {
            cSoPhuc kq;
            kq.iThuc = iThuc - a.iThuc;
            kq.iAo = iAo - a.iAo;
            return kq; 
        }
        cSoPhuc Nhan(cSoPhuc a)
        {
            cSoPhuc kq;
            kq.iThuc = iThuc*a.iThuc - iAo*a.iAo;
            kq.iAo = iThuc*a.iAo + iAo*a.iThuc;
            return kq;
        }
        cSoPhuc Chia(cSoPhuc a)
        {
            cSoPhuc kq;
            kq.iThuc = (iThuc*a.iThuc + iAo*a.iAo)/(a.iThuc*a.iThuc+a.iAo*a.iAo);
            kq.iAo = (a.iThuc*iAo - iThuc*a.iAo)/(a.iThuc*a.iThuc+a.iAo*a.iAo);
            return kq;
        }
};

int main()
{
    cSoPhuc a, b;
    cout << "Hãy nhập giá trị của số phức a: " << endl;
    a.Nhap();
    cout << "Hãy nhập giá trị của số phức b: " << endl;
    b.Nhap();

    cSoPhuc tong = a.Cong(b);
    cSoPhuc hieu = a.Tru(b);
    cSoPhuc tich = a.Nhan(b);
    cSoPhuc thuong = a.Chia(b);

    cout << "Tổng 2 số phức a và b là: " << endl;
    tong.Xuat();
    cout << "Hiệu 2 số phức a và b là: " << endl;
    hieu.Xuat();
    cout << "Tích 2 số phức a và b là: " << endl;
    tich.Xuat();
    cout << "Thương 2 số phức a và b là: " << endl;
    thuong.Xuat();

    return 0;
}