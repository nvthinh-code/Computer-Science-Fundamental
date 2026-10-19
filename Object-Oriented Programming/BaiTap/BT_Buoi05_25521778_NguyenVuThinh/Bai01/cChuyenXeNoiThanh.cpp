#include "cChuyenXeNoiThanh.h"

void cChuyenXeNoiThanh::Nhap()
{
    cChuyenXe::Nhap();
    cout << "Vui long nhap so tuyen: ";
    cin >> iSoTuyen;
    cout << "Vui long nhap so km di duoc: ";
    cin >> iSoKmDiDuoc;
    cin.ignore();
}

void cChuyenXeNoiThanh::Xuat()
{
    cChuyenXe::Xuat();
    cout << iSoTuyen << " " << iSoKmDiDuoc << " " << fDoanhThu << endl;
}