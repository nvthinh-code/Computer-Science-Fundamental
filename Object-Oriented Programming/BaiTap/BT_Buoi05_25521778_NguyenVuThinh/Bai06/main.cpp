//MSSV: 25521778    
//Họ và Tên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: IT002.Q22.CNVN.2
#include "cDanhSachSinhVien.h"
#include <cstdio>

int main()
{
    system("chcp 65001 > nul");
    cDanhSachSinhVien L;
    L.Nhap();
    L.XuatDanhSachSinhVien();
    L.XuatDanhSachSinhVienDuDieuKienTotNghiep();
    L.XuatDanhSachSinhVienKhongDuDieuKienTotNghiep();
    cSinhVienDaiHoc* MAX = L.TimSinhVienDaiHocCoDiemTrungBinhCaoNhat();
    if (MAX != nullptr)
    {
        cout << "------------------------------ Sinh viên Đại Học có điểm trung bình cao nhất ------------------------------\n";
        MAX->Xuat();
    }
    else 
        cout << "------------------------------ Không có sinh viên Đại Học trong danh sách này ------------------------------\n";

    return 0;
}
