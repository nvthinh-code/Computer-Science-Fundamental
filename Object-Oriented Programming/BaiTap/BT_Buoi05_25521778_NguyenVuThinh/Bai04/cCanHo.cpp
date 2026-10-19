#include "cCanHo.h"

void cCanHo::Nhap()
{
    cBDS::Nhap();
    cout << "Vui long nhap ma can: ";
    cin >> sMaCan;
    cout << "Vui long nhap vi tri tang: ";
    cin >> sTang;
    cin.ignore();
}

void cCanHo::Xuat()
{
    cBDS::Xuat();
    cout << "Ma can la: " << sMaCan << ". Vi tri tang la: " << sTang << "." << endl;
}

float cCanHo::TinhThanhTien()
{
    int soTang = stoi(sTang);
    if (soTang == 1)
        return fDienTich * fDonGia * 2;
    else if (soTang > 15)
        return fDienTich * fDonGia * 1.2;
    else
        return fDienTich * fDonGia;
}