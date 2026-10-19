#pragma once
#include <iostream>
#include <string>
using namespace std;

class cKhachHang
{
protected:
    string sTenKhachHang;
    int iSoLuongHang;
    float fDonGia;
    float fSoTienPhaiTra = 0;
    string sLoai = "";
    const float THUE = 0.1f;

public:
    cKhachHang() : sTenKhachHang(""), iSoLuongHang(0), fDonGia(0) {}
    cKhachHang(string tenkhachhang, int soluonghang, float dongia) : sTenKhachHang(tenkhachhang), iSoLuongHang(soluonghang), fDonGia(dongia) {}

    virtual void Nhap();
    virtual void Xuat();
    virtual float TinhSoTienKhachTra() = 0;
    string GetLoai() { return sLoai; }
    void SetLoai(string loai) { sLoai = loai; }

    virtual ~cKhachHang() {}
};