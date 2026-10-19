#include "cKhachHangThanThiet.h"

void cKhachHangThanThiet::Nhap()
{
    cKhachHang::Nhap();
    cout << "Vui lòng nhập số năm thân thiết: ";
    cin >> iSoNamThanThiet;
    cin.ignore();
}

float cKhachHangThanThiet::TinhSoTienKhachTra()
{
    return (float)iSoLuongHang * fDonGia * (1.0f - max((float)iSoNamThanThiet * 0.05f, 0.5f)) + THUE;
}