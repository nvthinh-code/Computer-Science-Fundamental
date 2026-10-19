#include "cKhachHang.h"

void cKhachHang::Nhap()
{
    cout << "Vui lòng nhập tên khách hàng: ";
    getline(cin, sTenKhachHang);
    cout << "Vui lòng nhập số lượng hàng: ";
    cin >> iSoLuongHang;
    cout << "Vui lòng nhập đơn giá: ";
    cin >> fDonGia;
    cin.ignore();
}

void cKhachHang::Xuat()
{
    cout << sTenKhachHang << " " << fSoTienPhaiTra << endl;
}