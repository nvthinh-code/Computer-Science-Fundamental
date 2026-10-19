#pragma once
#include <iostream>
#include <string>
using namespace std;

class cSinhVien
{
protected:
    int iMaSoSinhVien;
    string sHoTen;
    string sDiaChi;
    unsigned char ucTongSoTinChi;
    float fDiemTrungBinh;

public:
    cSinhVien() : iMaSoSinhVien(0), sHoTen(""), sDiaChi(""), ucTongSoTinChi(0), fDiemTrungBinh(0) {}
    cSinhVien(int mssv, string hoten, string diachi, unsigned char tongtinchi, float dtb) : iMaSoSinhVien(mssv), sHoTen(hoten), sDiaChi(diachi), ucTongSoTinChi(tongtinchi), fDiemTrungBinh(dtb) {}
    
    virtual void Nhap();
    virtual void Xuat();
    virtual bool XetTotNghiep() = 0;
    float GetDiemTrungBinh() { return fDiemTrungBinh; }

    virtual ~cSinhVien() {}
};