#pragma once
#include "cKhachHang.h"

class cKhachHangThanThiet : public cKhachHang
{
protected:
    int iSoNamThanThiet;

public:
    cKhachHangThanThiet() :iSoNamThanThiet(0) {}
    cKhachHangThanThiet(int sonamthanthiet) : iSoNamThanThiet(sonamthanthiet) {}

    void Nhap();
    float TinhSoTienKhachTra();

    ~cKhachHangThanThiet() {}
};