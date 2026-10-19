#include "cDanhSachKhachHang.h"

void cDanhSachKhachHang::Nhap()
{
    string loai;
    for (size_t i = 0; i < List.size(); i++)
    {
        cout << "Bạn muốn chọn khách hàng Bình Thường hay Thân Thiết hay Đặc Biệt: ";
        getline(cin, loai);

        if (loai == "Binh Thuong")
            List[i] = new cKhachHangBinhThuong;
        else if (loai == "Than Thiet")
            List[i] = new cKhachHangThanThiet;
        else   
            List[i] = new cKhachHangDacBiet;

        List[i]->SetLoai(loai);
        List[i]->Nhap();
    }
}

void cDanhSachKhachHang::Xuat()
{
    // Xuat theo KHBT
    for (size_t i = 0; i < List.size(); i++)
        if (List[i]->GetLoai() == "Binh Thuong")
            List[i]->Xuat();
    // Xuat theo KHTT
    for (size_t i = 0; i < List.size(); i++)
        if (List[i]->GetLoai() == "Than Thiet")
            List[i]->Xuat();
    // Xuat theo KHDB
    for (size_t i = 0; i < List.size(); i++)
        if (List[i]->GetLoai() == "Dac Biet")
            List[i]->Xuat();
}