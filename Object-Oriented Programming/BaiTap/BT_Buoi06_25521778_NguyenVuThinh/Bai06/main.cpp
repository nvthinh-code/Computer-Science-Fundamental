#include "cDanhSachKhachHang.h"

int main()
{
    size_t x, y, z;
    cin >> x >> y >> z;
    cin.ignore();
    cDanhSachKhachHang L(x, y, z);
    L.Nhap();
    L.Xuat();

    return 0;
}