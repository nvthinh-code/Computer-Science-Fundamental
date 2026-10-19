//MSSV: 25521778   
//Họ và tên sinh viên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: CNVN.2
#include <iostream> 

using namespace std;

class cPhanSo
{
    private: 
        int iTuSo;
        int iMauSo;
    public: 
        //Default Constructor
        cPhanSo()
        {
            iTuSo = 0;
            iMauSo = 1;
        }
        //Parameter Constructor
        cPhanSo(int a, int b)
        {
            //Mẫu không hợp lệ
            if (b == 0)
                b = 1;
            iTuSo = a;
            iMauSo = b;
        }
        void Nhap()
        {
            cin >> iTuSo;
            do {
                cin >> iMauSo;
            } while (iMauSo == 0);
        }
        void Xuat()
        {
            cout << iTuSo << "/"  << iMauSo;
        }
        void SetTuSo(int iTuSo)
        {
            this->iTuSo = iTuSo;
        }
        void SetMauSo(int iMauSo)
        {
            if (iMauSo == 0)
                return;
            else 
                this->iMauSo = iMauSo;
        }
        cPhanSo Cong(const cPhanSo& x) const 
        {
            cPhanSo KetQua;
            KetQua.iTuSo = iTuSo*x.iMauSo+x.iTuSo*iMauSo;
            KetQua.iMauSo = iMauSo*x.iMauSo;
            return KetQua;
        }
        cPhanSo Tru(const cPhanSo& x) const
        {
            cPhanSo KetQua;
            KetQua.iTuSo = iTuSo*x.iMauSo-x.iTuSo*iMauSo;
            KetQua.iMauSo = iMauSo*x.iMauSo;
            return KetQua;
        }
        cPhanSo Nhan(const cPhanSo& x) const
        {
            cPhanSo KetQua;
            KetQua.iTuSo = iTuSo*x.iTuSo;
            KetQua.iMauSo = iMauSo*x.iMauSo;
            return KetQua;
        }
        cPhanSo Chia(const cPhanSo& x) const
        {
            cPhanSo KetQua;
            KetQua.iTuSo = iTuSo*x.iMauSo;
            KetQua.iMauSo = iMauSo*x.iTuSo;
            return KetQua;
        }
};

int main(){
    cPhanSo a, b;

    cout << "Hãy nhập phân số a: " << endl;
    a.Nhap(); 
    cout << "Hãy nhập phân số b: " << endl;
    b.Nhap();
    
    cPhanSo Tong, Hieu, Tich, Thuong;
    Tong = a.Cong(b);
    Hieu = a.Tru(b);
    Tich = a.Nhan(b);
    Thuong = a.Chia(b);

    cout << "Tổng 2 phân số là: ";
    Tong.Xuat();
    cout << endl; 
    cout << "Hiệu 2 phân số là: ";
    Hieu.Xuat();
    cout << endl;
    cout << "Tích 2 phân số là: ";
    Tich.Xuat(); 
    cout << endl;
    cout << "Thương 2 phân số là: ";
    Thuong.Xuat(); 
    cout << endl;

    return 0;
}