#include "cNhaPho.h"

void cNhaPho::Nhap()
{
    cBDS::Nhap();
    cout << "Vui long nhap loai nha: ";
    getline(cin, sLoaiNha);
    cout << "Vui long nhap dia chi: ";
    getline(cin, sDiaChi);
}

void cNhaPho::Xuat()
{
    cBDS::Xuat();
    cout << "Loai nha la: " << sLoaiNha << ". Dia chi la: " << sDiaChi << "." << endl;
}

float cNhaPho::TinhThanhTien()
{
    return (sLoaiNha == "cao cap" ? fDienTich * fDonGia : fDienTich * fDonGia * 0.9);
}