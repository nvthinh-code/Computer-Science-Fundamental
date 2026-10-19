#pragma once
#include "cBDS.h"

class cNhaPho : public cBDS
{
private:
    string sLoaiNha;
    string sDiaChi;

public:
    cNhaPho() : sLoaiNha(""), sDiaChi("") {}
    cNhaPho(string loainha, string diachi) : sLoaiNha(loainha), sDiaChi(diachi) {}

    void Nhap();
    void Xuat();
    float TinhThanhTien();

    ~cNhaPho() {}
};