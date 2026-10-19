#pragma once
#include "cTien.h"
#include "cVang.h"
#include <vector>

class cDSGiaoDich
{
private:
    vector<cGiaoDich*> List;

public: 
    cDSGiaoDich() : List(0) {}
    cDSGiaoDich(int sophantu) : List(sophantu) {}

    void Nhap();
    void Xuat();
    cGiaoDich* operator[](int i) { return List[i]; }
    int TimViTriGiaoDichVangCoThanhTienCaoNhat();
    int TimViTriGiaoDichEuroCoThanhTienThapNhat();
    void XuatGiaoDichThanhTienTren1TiDong();
    bool KiemTraXemCoTonTaiGiaoDichThanhTienTren1TiDong();

    ~cDSGiaoDich();
};