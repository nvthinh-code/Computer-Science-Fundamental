#pragma once
#include <iostream>
#include <string>

class cSach
{
protected:
    int iMaSach;
    std::string sNgayNhap;
    float fDonGia;
    int iSoLuong;
    std::string sNhaXuatBan;

public:
    cSach() : iMaSach(0), sNgayNhap(""), fDonGia(0), iSoLuong(0), sNhaXuatBan("") {}
    cSach(int masach, std::string ngaynhap, float dongia, int soluong, std::string nhaxuatban) : iMaSach(masach), sNgayNhap(ngaynhap), fDonGia(dongia), iSoLuong(soluong), sNhaXuatBan(nhaxuatban) {}

    virtual void Nhap();
    virtual void Xuat();
    virtual float tinhTien() = 0;
    float getDonGia() { return fDonGia; }
    std::string getNhaXuatBan() { return sNhaXuatBan; }

    virtual ~cSach() {}
};