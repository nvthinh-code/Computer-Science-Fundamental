#include "cSTK.h"

void cSTK::Nhap()
{
    cSach::Nhap();
    cout << "Vui lòng nhập thuế: ";
    cin >> fThue;
}

void cSTK::Xuat()
{
    cSach::Xuat();
    cout << " " << fThue << endl;
}

float cSTK::tinhTien()
{
    return iSoLuong * fDonGia + fThue;
}