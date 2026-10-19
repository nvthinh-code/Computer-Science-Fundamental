#pragma once
#include <iostream>
#include <string>
using namespace std;

class cChuyenXe
{
protected:
    string sMaSoChuyen;
    string sHoTenTaiXe;
    string sSoXe;
    float fDoanhThu;

public:
    cChuyenXe() : sMaSoChuyen(""), sHoTenTaiXe(""), sSoXe(""), fDoanhThu(0) {}
    cChuyenXe(string MaSoChuyen, string HoTenTaiXe, string SoXe, float DoanhThu) : sMaSoChuyen(MaSoChuyen), sHoTenTaiXe(HoTenTaiXe), sSoXe(SoXe), fDoanhThu(DoanhThu) {}

    virtual void Nhap();
    virtual void Xuat();
    float GetDoanhThu() { return fDoanhThu; }
    
    ~cChuyenXe() {}
};