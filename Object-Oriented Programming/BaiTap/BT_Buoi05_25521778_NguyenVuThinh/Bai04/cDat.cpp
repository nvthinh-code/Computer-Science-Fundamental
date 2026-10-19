#include "cDat.h"

void cDat::Nhap()
{
    cBDS::Nhap();
    cout << "Vui long nhap loai dat (A/B/C): ";
    cin >> sLoaiDat;
    cin.ignore();
}

void cDat::Xuat()
{
    cBDS::Xuat();
    cout << "Loai dat la: " << sLoaiDat << endl;
}

float cDat::TinhThanhTien()
{
    if (sLoaiDat == "A")
        return fDienTich * fDonGia * 1.5;
    else
        return fDienTich * fDonGia;
}