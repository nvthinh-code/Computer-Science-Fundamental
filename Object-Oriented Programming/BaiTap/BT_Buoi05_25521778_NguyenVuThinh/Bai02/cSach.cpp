#include "cSach.h"
using namespace std;

void cSach::Nhap()
{
    cout << "Vui lòng nhập mã sách (int) : ";
    cin >> iMaSach;
    cout << "Vui lòng nhập ngày nhập (ngay/thang/nam): ";
    cin >> sNgayNhap;
    cout << "Vui lòng nhập đơn giá: ";
    cin >> fDonGia;
    cout << "Vui lòng nhập số lượng sách ";
    cin >> iSoLuong;
    cin.ignore();
    cout << "Vui lòng nhập nhà xuất bản: ";
    getline(cin, sNhaXuatBan);
}

void cSach::Xuat()
{
    cout << iMaSach << " " << sNgayNhap << " " << fDonGia << " " << iSoLuong << " " << sNhaXuatBan;
}