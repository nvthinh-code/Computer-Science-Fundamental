#include "cDanhSachSinhVien.h"

void cDanhSachSinhVien::Nhap()
{
    size_t soLuongSinhVien;
    cout << "Vui lòng nhập số lượng sinh viên: ";
    cin >> soLuongSinhVien;
    List.resize(soLuongSinhVien);
    bool loai;
    for (size_t i = 0; i < List.size(); i++)
    {
        cout << "Vui lòng chọn sinh viên Đại Học (1) hoặc sinh viên Cao Đẳng (0): ";
        cin >> loai;
        
        if (loai == 1)
            List[i] = new cSinhVienDaiHoc;
        else
            List[i] = new cSinhVienCaoDang;

        List[i]->Nhap();
    }
}

void cDanhSachSinhVien::XuatDanhSachSinhVien()
{
    cout << "------------------------------ Danh Sách Sinh Viên ------------------------------\n";
    cout << "*** Sinh viên Đại Học ***\n";
    cout << "MSSV\tHo Ten\tDiaChi TongTinChi Diem Trung Binh Ten Luan Van Diem Luan Van\n";
    for (size_t i = 0; i < List.size(); i++)
    {
        cSinhVienDaiHoc* ptr = dynamic_cast<cSinhVienDaiHoc*>(List[i]);
        if (ptr != nullptr)
            List[i]->Xuat();
    }

    cout << "*** Sinh viên Cao Đẳng ***\n";
    cout << "MSSV\tHo Ten\tDiaChi TongTinChi Diem Trung Binh Diem Tot Nghiep\n";
    for (size_t i = 0; i < List.size(); i++)
    {
        cSinhVienCaoDang* ptr = dynamic_cast<cSinhVienCaoDang*>(List[i]);
        if (ptr != nullptr)
            List[i]->Xuat();
    }
}

void cDanhSachSinhVien::XuatDanhSachSinhVienDuDieuKienTotNghiep()
{
    cout << "------------------------------ Danh Sách Sinh Viên Đủ Điều Kiện Tốt Nghiệp ------------------------------\n";
    for (size_t i = 0; i < List.size(); i++)
        if (List[i]->XetTotNghiep())
            List[i]->Xuat();
}

void cDanhSachSinhVien::XuatDanhSachSinhVienKhongDuDieuKienTotNghiep()
{
    cout << "------------------------------ Danh Sách Sinh Viên Không Đủ Điều Kiện Tốt Nghiệp ------------------------------\n";
        for (size_t i = 0; i < List.size(); i++)
            if (!List[i]->XetTotNghiep())
                List[i]->Xuat();
}

cSinhVienDaiHoc* cDanhSachSinhVien::TimSinhVienDaiHocCoDiemTrungBinhCaoNhat()
{
    float DTB_MAX = -1;
    cSinhVienDaiHoc* DTB_MAX_POS = nullptr;
    for (size_t i = 0; i < List.size(); i++)
    {
        cSinhVienDaiHoc* ptr = dynamic_cast<cSinhVienDaiHoc*>(List[i]);
        if (ptr != nullptr)
        {
            if (DTB_MAX < ptr->GetDiemTrungBinh())
            {
                DTB_MAX_POS = ptr;
                DTB_MAX = ptr->GetDiemTrungBinh();
            }
        }
    }

    return DTB_MAX_POS;
}