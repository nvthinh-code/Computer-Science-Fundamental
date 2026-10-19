#include <iostream>

using namespace std;

class cPhanSo
{
    // Thành phần dữ liệu (thuộc tính)
private:
    int iTuSo;
    int iMauSo;
    // Thành phần phương thức (hành vi)
public:
    // Nhóm các hàm khởi tạo
    cPhanSo()
    {
        iTuSo = 0;
        iMauSo = 1;
    }
    cPhanSo(int iTuSo, int iMauSo)
    {
        this->iTuSo = iTuSo;
        if (iMauSo == 0)
            iMauSo = 1;
        this->iMauSo = iMauSo;
    }
    // Nhóm
    void Nhap()
    {
        cin >> iTuSo >> iMauSo;
    }
    void Xuat()
    {
        cout << iTuSo << "/" << iMauSo;
    }
    // Nhóm các hàm get, set
    void setTuSo(int tu)
    {
        iTuSo = tu;
    }
    void setMauSo(int mau)
    {
        if (mau != 0)
            iMauSo = mau;
    }
    int getTuSo()
    {
        return iTuSo;
    }
    int getMauSo()
    {
        return iMauSo;
    }
    // Nhóm các hàm tính toán
    cPhanSo TinhTong(cPhanSo a)
    {
        cPhanSo kq;
        kq.iTuSo = iTuSo * a.iMauSo + a.iTuSo * iMauSo;
        kq.iMauSo = iMauSo * a.iMauSo;
        return kq;
    }
    ~cPhanSo();
    // const : khong the bi thay doi
    // static : bien tinh, khong phu thuoc object ma phu thuoc class
    //  constructor() : -> su dung khi class nay bao gom class khac
};

int main()
{
    cPhanSo ps1, ps2, kq;
    cout << "Nhap ps1, ps2: " << endl;
    ps1.Nhap();
    ps2.Nhap();

    return 0;
}