#include "cSinhVienCaoDang.h"
#include "cSinhVienDaiHoc.h"
#include <vector>

class cDanhSachSinhVien
{
private:
    vector<cSinhVien*> List;

public:
    cDanhSachSinhVien() {}
    cDanhSachSinhVien(size_t size) : List(size) {}

    void Nhap();
    void XuatDanhSachSinhVien();
    void XuatDanhSachSinhVienDuDieuKienTotNghiep();
    void XuatDanhSachSinhVienKhongDuDieuKienTotNghiep();
    cSinhVienDaiHoc* TimSinhVienDaiHocCoDiemTrungBinhCaoNhat();

    ~cDanhSachSinhVien()
    {
        for (size_t i = 0; i < List.size(); i++)
            delete List[i];

        List.clear();
    }
};