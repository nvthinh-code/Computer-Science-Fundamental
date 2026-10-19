#pragma once
#include "cGiaoDich.h"
using namespace std;

class cTien : public cGiaoDich
{
protected:
    float fTiGia;
    string sLoaiTien;

public:
    cTien() : fTiGia(0), sLoaiTien("") {}
    cTien(float tigia, string loaitien) : fTiGia(tigia), sLoaiTien(loaitien) {}

    void Nhap() override;
    void Xuat() override;   
    string GetLoaiTien() { return sLoaiTien; }
    float TinhTien() override;

    ~cTien() {}
};