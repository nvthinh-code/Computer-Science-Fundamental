#pragma once
#include "cChuyenXe.h"

class cChuyenXeNoiThanh : public cChuyenXe
{
protected:
    int iSoTuyen;
    int iSoKmDiDuoc;

public:
    cChuyenXeNoiThanh() : iSoTuyen(0), iSoKmDiDuoc(0) {}
    cChuyenXeNoiThanh(int sotuyen, int sokm) : iSoTuyen(sotuyen), iSoKmDiDuoc(sokm) {}

    void Nhap();
    void Xuat();

    ~cChuyenXeNoiThanh() {}
};