#include "cSinhVien.h"

class cSinhVienCaoDang : public cSinhVien
{
protected:
    float fDiemThiTotNghiep;

public:
    cSinhVienCaoDang() : fDiemThiTotNghiep(0) {}
    cSinhVienCaoDang(float diemthitotnghiep) : fDiemThiTotNghiep(diemthitotnghiep) {}

    void Nhap();
    void Xuat();
    bool XetTotNghiep();

    ~cSinhVienCaoDang() {}
};