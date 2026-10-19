#pragma once
#include "cKhachHangBinhThuong.h"
#include "cKhachHangDacBiet.h"
#include "cKhachHangThanThiet.h"
#include <vector>

class cDanhSachKhachHang
{
private:
    size_t iSoLuongKhachHangBinhThuong;
    size_t iSoLuongKhachHangThanThiet;
    size_t iSoLuongKhachHangDacBiet;
    vector<cKhachHang *> List;

public:
    cDanhSachKhachHang() : iSoLuongKhachHangBinhThuong(0), iSoLuongKhachHangThanThiet(0), iSoLuongKhachHangDacBiet(0) {}
    cDanhSachKhachHang(size_t x, size_t y, size_t z) : iSoLuongKhachHangBinhThuong(x), iSoLuongKhachHangThanThiet(y), iSoLuongKhachHangDacBiet(z), List(x+y+z) { }

    void Nhap();
    void Xuat();
    float TinhTongSoTienCongTyThuDuoc();

    ~cDanhSachKhachHang()
    {
        for (size_t i = 0; i < List.size(); i++)
            delete List[i];
        List.clear();
    }
};