#include "cChuyenXeNgoaiThanh.h"

void cChuyenXeNgoaiThanh::Nhap()
{
    cChuyenXe::Nhap();
    cin.ignore();
    cout << "Vui long nhap noi den: ";
    getline(cin, sNoiDen);
    cout << "Vui long nhap so ngay di duoc: ";
    cin >> iSoNgayDiDuoc;
}

void cChuyenXeNgoaiThanh::Xuat()
{
    cChuyenXe::Xuat();
    cout << sNoiDen << " " << iSoNgayDiDuoc << " " << fDoanhThu << endl;
}