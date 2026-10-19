#include "cTien.h"

void cTien::Nhap()
{
    cGiaoDich::Nhap();
    cout << "Vui long nhap loai tien (VNV/USD/EURO): ";
    cin >> sLoaiTien;
    if (sLoaiTien != "VND")
    {
        cout << "Vui long nhap ti gia: ";
        cin >> fTiGia;
    } 
    else
        fTiGia = 1;
}

void cTien::Xuat()
{
    cGiaoDich::Xuat();
    cout << " " << sLoaiTien << " " << cTien::TinhTien() << endl;
}

float cTien::TinhTien()
{
    return (sLoaiTien == "VND" ? iSoLuong * fDonGia : iSoLuong * fDonGia * fTiGia);
}