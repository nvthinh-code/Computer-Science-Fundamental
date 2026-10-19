#pragma once
#include "cGiaoDich.h"
using namespace std;

class cVang : public cGiaoDich
{
protected:
    string sLoaiVang;

public:
    cVang() : sLoaiVang("") {}
    cVang(string loaivang) : sLoaiVang(loaivang) {}

    void Nhap() override;
    void Xuat() override;
    float TinhTien() override;

    ~cVang() {}
};