#include "cGiaSuc.h"

void cGiaSuc::Nhap()
{
    cout << "Vui long nhap loai gia suc: ";
    getline(cin, sLoaiGiaSuc);
}

void cGiaSuc::Xuat()
{
    cout << sLoaiGiaSuc << " " << fSoLitSua << endl;
}

    