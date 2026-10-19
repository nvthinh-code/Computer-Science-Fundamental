#pragma once
#include "cBDS.h"

class cDat : public cBDS
{
private:
    string sLoaiDat;

public:
    cDat() : sLoaiDat("") {}
    cDat(string loai) : sLoaiDat(loai) {}

    void Nhap();
    void Xuat();
    float TinhThanhTien();

    ~cDat() {}
};