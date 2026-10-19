#include "cBDS.h"

void cBDS::Nhap()
{
    cout << "Vui long nhap ma giao dich: ";
    cin >> sMaGiaoDich;
    cout << "Vui long nhap ngay giao dich (dd/mm/yy): ";
    cin >> sNgayGiaoDich;
    cout << "Vui long nhap don gia: ";
    cin >> fDonGia;
    cout << "Vui long nhap dien tich: ";
    cin >> fDienTich;
    cin.ignore();
}

void cBDS::Xuat()
{
    cout << "Ma giao dich la: " << sMaGiaoDich << ". Ngay giao dich la: " << sNgayGiaoDich << ". Dien tich la: " << fDienTich << ". ";
}