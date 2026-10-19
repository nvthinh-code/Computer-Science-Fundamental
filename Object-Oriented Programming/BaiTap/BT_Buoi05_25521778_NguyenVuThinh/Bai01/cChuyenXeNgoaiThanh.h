#pragma once
#include "cChuyenXe.h"

class cChuyenXeNgoaiThanh : public cChuyenXe
{
protected:
    string sNoiDen;
    int iSoNgayDiDuoc;

public:
    cChuyenXeNgoaiThanh() : sNoiDen(""), iSoNgayDiDuoc(0) {}
    cChuyenXeNgoaiThanh(string noiden, int songay) : sNoiDen(noiden), iSoNgayDiDuoc(songay) {}

    void Nhap();
    void Xuat();

    ~cChuyenXeNgoaiThanh() {}
};