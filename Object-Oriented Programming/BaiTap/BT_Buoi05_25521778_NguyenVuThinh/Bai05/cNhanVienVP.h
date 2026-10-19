#pragma once
#include "cNhanVien.h"

class cNhanVienVP : public cNhanVien
{
protected:
    short shSoNgayLamViec;

public:
    cNhanVienVP() : shSoNgayLamViec(0) {}
    cNhanVienVP(short songaylamviec) : shSoNgayLamViec(songaylamviec) {}

    void Nhap();
    void Xuat();
    int TinhLuong();

    ~cNhanVienVP() {}
};