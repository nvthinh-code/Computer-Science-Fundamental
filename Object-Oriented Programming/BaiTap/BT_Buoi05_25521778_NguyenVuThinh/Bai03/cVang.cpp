#include "cVang.h"

void cVang::Nhap()
{
    cGiaoDich::Nhap();
    cout << "Vui long nhap loai vang: ";
    cin >> sLoaiVang;
}

void cVang::Xuat()
{
    cGiaoDich::Xuat();
    cout << " " << sLoaiVang << " " << cVang::TinhTien() << endl;
}

float cVang::TinhTien()
{
    return iSoLuong * fDonGia;
}