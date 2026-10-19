#pragma once
#include "cBo.h"
#include "cDe.h"
#include "cCuu.h"
#include <vector>

class cListGiaSuc
{
private:
    vector<cGiaSuc *> List;
    int iSoLuongBo;
    int iSoLuongCuu;
    int iSoLuongDe;

public:
    cListGiaSuc() : iSoLuongBo(0), iSoLuongCuu(0), iSoLuongDe(0) {}
    cListGiaSuc(int n, int bo, int cuu, int de) : List(n), iSoLuongBo(bo), iSoLuongCuu(cuu), iSoLuongDe(de) {}

    void Nhap();

    void XuatRaNhungTiengKeuKhiChuDiVang();
    void DeCon();

    void XuatRaSoGiaSucMoiLoai();
    float TinhTongSoLitSuaDaCho();

    ~cListGiaSuc()
    {
        for (int i = 0; i < List.size(); i++)
            delete List[i];

        List.clear();
    }
};