#pragma once
#include "cSinhVien.h"

class cSinhVienDaiHoc : public cSinhVien
{
protected:
    string sTenLuanVan;
    float fDiemLuanVan;

public:
    cSinhVienDaiHoc() : sTenLuanVan(""), fDiemLuanVan(0) {}
    cSinhVienDaiHoc(string tenluanvan, float diemluanvan) : sTenLuanVan(tenluanvan), fDiemLuanVan(diemluanvan) {}

    void Nhap();
    void Xuat();
    bool XetTotNghiep();

    ~cSinhVienDaiHoc() {}
};