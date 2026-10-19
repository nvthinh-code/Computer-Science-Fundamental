#pragma once
#include <iostream>
#include <string>

class cGiaoDich
{
protected:
    std::string sMaGiaoDich;
    std::string sNgayGiaoDich;
    float fDonGia;
    int iSoLuong;

public: 
    cGiaoDich() : sMaGiaoDich(""), sNgayGiaoDich(""), fDonGia(0), iSoLuong(0) {}
    cGiaoDich(std::string ma, std::string ngay, float dongia, int soluong) : sMaGiaoDich(ma), sNgayGiaoDich(ngay), fDonGia(dongia), iSoLuong(soluong) {}

    virtual void Nhap();
    virtual void Xuat();
    virtual float TinhTien() = 0;

    virtual ~cGiaoDich() {}
};