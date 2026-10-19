#pragma once
#include <iostream>
#include "cSGK.h"
#include "cSTK.h"
#include <vector>

class cDanhSach
{
private:
    vector<cSach*> list;

public:
    cDanhSach() : list(0) {}
    cDanhSach(int n) : list(n) {}

    void Nhap();
    void Xuat();
    float tinhTienSGK();
    float tinhTienSTK();
    float TinhTongThanhTien();
    float TinhTrungBinhCongDonGiaSTK();
    void XuatSGKTheoNXB(std::string nhaXuatBanK);

    ~cDanhSach() {}
};