#pragma once
#include "cNhanVien.h"

class cNhanVienSX : public cNhanVien
{
protected:
    int iLuongCanBan;
    int iSoSanPham;

public:
    cNhanVienSX() : iLuongCanBan(0), iSoSanPham(0) {}
    cNhanVienSX(int luong, int sosp) : iLuongCanBan(luong), iSoSanPham(sosp) {}

    void Nhap();
    void Xuat();
    int TinhLuong();

    ~cNhanVienSX() {}
};