#pragma once
#include <iostream>
#include <string>
using namespace std;

class cBDS
{
protected:
    string sMaGiaoDich;
    string sNgayGiaoDich;
    float fDonGia;
    float fDienTich;

public:
    cBDS() : sMaGiaoDich(""), sNgayGiaoDich(""), fDonGia(0), fDienTich(0) {}
    cBDS(string ma, string ngay, float dongia, float dientich) : sMaGiaoDich(ma), sNgayGiaoDich(ngay), fDonGia(dongia), fDienTich(dientich) {}

    virtual void Nhap();
    virtual void Xuat();
    string getNgayGiaoDich() { return sNgayGiaoDich; }
    virtual float TinhThanhTien() = 0;

    virtual ~cBDS() {}  
};