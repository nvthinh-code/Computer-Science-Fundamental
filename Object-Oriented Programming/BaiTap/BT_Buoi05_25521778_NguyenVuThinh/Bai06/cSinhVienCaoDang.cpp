#include "cSinhVienCaoDang.h"

void cSinhVienCaoDang::Nhap()
{
    cSinhVien::Nhap();
    cout << "Vui lòng nhập điểm thi tốt nghiệp: ";
    cin >> fDiemThiTotNghiep;
    cin.ignore();
}

void cSinhVienCaoDang::Xuat()
{
    cSinhVien::Xuat();
    cout << fDiemThiTotNghiep << endl;
}

bool cSinhVienCaoDang::XetTotNghiep()
{
    if ((int)ucTongSoTinChi >= 110 && fDiemTrungBinh >= 5 && fDiemThiTotNghiep >= 5)
        return true;
        
    return false;
}