#include "cNhanVienSX.h"

void cNhanVienSX::Nhap()
{
    cNhanVien::Nhap();
    cout << "Vui long nhap luong can ban: ";
    cin >> iLuongCanBan;
    cout << "Vui long nhap so san pham: ";
    cin >> iSoSanPham;
    cin.ignore();
}

void cNhanVienSX::Xuat()
{
    cNhanVien::Xuat();
    cout << iLuongCanBan << " " << iSoSanPham << " " << iLuong << endl;
}

int cNhanVienSX::TinhLuong()
{
    iLuong = iLuongCanBan * iSoSanPham * 5000;
    return iLuong;
}