#include "cGiaoDich.h"
using namespace std;

void cGiaoDich::Nhap()
{
    cout << "Vui long nhap ma giao dich: ";
    cin >> sMaGiaoDich;
    cout << "Vui long nhap ngay giao dich: ";
    cin >> sNgayGiaoDich;
    cout << "Vui long nhap don gia: ";
    cin >> fDonGia;
    cout << "Vui long nhap so luong: ";
    cin >> iSoLuong;
}

void cGiaoDich::Xuat()
{
    cout << sMaGiaoDich << " " << sNgayGiaoDich << " " << fDonGia << " " << iSoLuong;
}

