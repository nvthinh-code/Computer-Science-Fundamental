#pragma once
#include <vector>
#include "cNhanVienSX.h"
#include "cNhanVienVP.h"

class cDSNhanVien
{
private:
    vector<cNhanVien*> List;

public:
    cDSNhanVien() : List(0) {}
    cDSNhanVien(int n) : List(n) {};

    void Nhap();
    void Xuat();
    int TinhTongLuongPhaiTra();

    ~cDSNhanVien()
    {
        for (int i = 0; i < List.size(); i++)
            delete List[i];
        
        List.clear();
    }
};