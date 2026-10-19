#include "cDanhSachChuyenXe.h"

void cDanhSachChuyenXe::Nhap()
{
    int n;
    cout << "Vui long nhap so luong chuyen xe: ";
    cin >> n;
    List.resize(n);
    bool loai;
    for (int i = 0; i < List.size(); i++)
    {
        cout << "Ban muon nhap Ngoai Thanh (0) hay Noi Thanh (1): ";
        cin >> loai;
        cin.ignore();
        if (loai == 0)
            List[i] = new cChuyenXeNgoaiThanh;
        else
            List[i] = new cChuyenXeNoiThanh;
        
        List[i]->Nhap();
    }
}

// Mã số chuyến, Họ tên tài xế, số xe, nơi đến, số ngày đi được, doanh thu.
void cDanhSachChuyenXe::Xuat()
{
    cout << "------------------------------------- Danh Sach Chuyen Xe -------------------------------------\n\n"; 

    // Xuat theo Ngoai Thanh
    cout << "------------------------------------- Chuyen Xe Ngoai Thanh -------------------------------------\n";
    cout << "Ma so chuyen - Ho ten tai xe - So xe - Noi Den - So ngay di duoc - Doanh thu\n";
    for (int i = 0; i < List.size(); i++)
    {
        cChuyenXeNgoaiThanh* ptr = dynamic_cast<cChuyenXeNgoaiThanh*>(List[i]);

        if (ptr != nullptr)
            List[i]->Xuat();
    }
    
    // Xuat theo Noi Thanh
    cout << "------------------------------------- Chuyen Xe Noi Thanh -------------------------------------\n";
    cout << "Ma so chuyen - Ho ten tai xe - So xe - So tuyen - So km di duoc - Doanh thu\n";
    for (int i = 0; i < List.size(); i++)
    {
        cChuyenXeNoiThanh* ptr = dynamic_cast<cChuyenXeNoiThanh*>(List[i]);

        if (ptr != nullptr)
            List[i]->Xuat();
    }
}

float cDanhSachChuyenXe::TinhTongDoanhThuTatCaChuyenXe()
{
    float tong = 0;
    for (int i = 0; i < List.size(); i++)
        tong += List[i]->GetDoanhThu();

    return tong;
}

float cDanhSachChuyenXe::TinhTongDoanhThuNoiThanh()
{
    float tong = 0;
    for (int i = 0; i < List.size(); i++)
    {
        cChuyenXeNoiThanh* ptr = dynamic_cast<cChuyenXeNoiThanh*>(List[i]);
        if (ptr != nullptr)
            tong += List[i]->GetDoanhThu();           
    }

    return tong;
}
float cDanhSachChuyenXe::TinhTongDoanhThuNgoaiThanh()
{
    float tong = 0;
    for (int i = 0; i < List.size(); i++)
    {
        cChuyenXeNgoaiThanh* ptr = dynamic_cast<cChuyenXeNgoaiThanh*>(List[i]);
        if (ptr != nullptr)
            tong += List[i]->GetDoanhThu();           
    }

    return tong;
}