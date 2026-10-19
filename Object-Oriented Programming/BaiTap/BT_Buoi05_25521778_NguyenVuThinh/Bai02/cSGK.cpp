#include "cSGK.h"

void cSGK::Nhap()
{
    cSach::Nhap();
    cout << "Vui lòng nhập tình trạng sách - moi (1), cu(0): ";
    cin >> bTinhTrang;
}

void cSGK::Xuat()
{
    cSach::Xuat();
    cout << " " << bTinhTrang << endl;
}

float cSGK::tinhTien()
{
    return (bTinhTrang == 1 ? iSoLuong * fDonGia : iSoLuong * fDonGia * 0.5);
}