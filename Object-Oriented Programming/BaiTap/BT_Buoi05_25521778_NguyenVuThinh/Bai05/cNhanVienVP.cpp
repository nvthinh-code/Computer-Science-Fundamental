#include "cNhanVienVP.h"

void cNhanVienVP::Nhap()
{
    cNhanVien::Nhap();
    cout << "Vui long nhap so ngay lam viec: ";
    cin >> shSoNgayLamViec;
    cin.ignore();
}

void cNhanVienVP::Xuat()
{
    cNhanVien::Xuat();
    cout << shSoNgayLamViec << " " << iLuong << endl;
}

int cNhanVienVP::TinhLuong()
{
    iLuong = shSoNgayLamViec * 100000;
    return iLuong;
}
