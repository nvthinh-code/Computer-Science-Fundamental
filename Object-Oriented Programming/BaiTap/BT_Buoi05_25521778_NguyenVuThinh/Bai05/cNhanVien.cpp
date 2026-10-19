#include "cNhanVien.h"

void cNhanVien::Nhap()
{
    cout << "Vui long nhap ho ten: ";
    getline(cin, sHoTen);
    cout << "Vui long nhap ngay sinh (dd/mm/yyyy): ";
    getline(cin, sNgaySinh);
}

void cNhanVien::Xuat()
{
    cout << sHoTen << " " << sNgaySinh << " ";
}