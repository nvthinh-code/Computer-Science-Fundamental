#include "cSinhVienDaiHoc.h"

void cSinhVienDaiHoc::Nhap()
{
    cSinhVien::Nhap();
    cin.ignore();
    cout << "Vui lòng nhập tên luận văn: ";
    getline(cin, sTenLuanVan);
    cout << "Vui lòng nhập điểm luận văn: ";
    cin >> fDiemLuanVan;
    cin.ignore();
}

void cSinhVienDaiHoc::Xuat()
{
    cSinhVien::Xuat();
    cout << sTenLuanVan << " " << fDiemLuanVan << endl;
}

bool cSinhVienDaiHoc::XetTotNghiep()
{
    if ((int)ucTongSoTinChi >= 145 && fDiemTrungBinh >= 5 && fDiemLuanVan >= 5)
        return true;

    return false;
}