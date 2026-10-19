#pragma once
#include "cChuyenXeNgoaiThanh.h"
#include "cChuyenXeNoiThanh.h"
#include <iostream>
#include <vector>

class cDanhSachChuyenXe
{
private:
    vector<cChuyenXe*> List;

public:
    cDanhSachChuyenXe() {}
    cDanhSachChuyenXe(int n) : List(n) {}

    void Nhap();
    void Xuat();
    float TinhTongDoanhThuTatCaChuyenXe();
    float TinhTongDoanhThuNoiThanh();
    float TinhTongDoanhThuNgoaiThanh();

    ~cDanhSachChuyenXe() { for (int i = 0; i < List.size(); i++) delete List[i]; List.clear(); }
};
