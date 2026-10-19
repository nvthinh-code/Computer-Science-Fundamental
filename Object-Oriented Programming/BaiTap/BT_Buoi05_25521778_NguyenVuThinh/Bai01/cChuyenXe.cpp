#include "cChuyenXe.h"

void cChuyenXe::Nhap()
{
    cout << "Vui long nhap ma so chuyen: ";
    getline(cin, sMaSoChuyen);
    cout << "Vui long nhap ho ten tai xe: ";
    getline(cin, sHoTenTaiXe);
    cout << "Vui long nhap so xe: ";
    getline(cin, sSoXe);
    cout << "Vui long nhap doanh thu: ";
    cin >> fDoanhThu;
}

void cChuyenXe::Xuat()
{
    cout << sMaSoChuyen << " " << sHoTenTaiXe << " " << sSoXe << " ";
}