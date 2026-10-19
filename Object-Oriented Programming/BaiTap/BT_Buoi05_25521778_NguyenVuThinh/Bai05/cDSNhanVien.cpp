#include "cDSNhanVien.h"

void cDSNhanVien::Nhap()
{
    int n;
    cout << "Vui long nhap so luong nhan vien: ";
    cin >> n;
    List.resize(n);
    bool loai;
    for (int i = 0; i < n; i++)
    {
        cout << "Ban muon chon NVVP(1) hay NVSX(0): ";
        cin >> loai;
        cin.ignore();
        
        if (loai == 1)
            List[i] = new cNhanVienVP;
        else
            List[i] = new cNhanVienSX;

        List[i]->Nhap();
    }
}

void cDSNhanVien::Xuat()
{
    // Xuat NVVP
    cout << "-----------------------------------------------------NVVP---------------------------------------------------------------\n";
    cout << "Ho ten Ngay Sinh So Ngay Lam Viec Luong\n";
    for (int i = 0; i < List.size(); i++)
    {
        cNhanVienVP* ptr = dynamic_cast<cNhanVienVP*>(List[i]);
        if (ptr != nullptr)
        {
            List[i]->TinhLuong();
            List[i]->Xuat();
        }
    }

    // Xuat NVSX
    cout << "-----------------------------------------------------NVSX---------------------------------------------------------------\n";
    cout << "Ho ten Ngay Sinh Luong Co Ban So San Pham Luong\n";
    for (int i = 0; i < List.size(); i++)
    {
        cNhanVienSX* ptr = dynamic_cast<cNhanVienSX*>(List[i]);
        if (ptr != nullptr)
        {
            List[i]->TinhLuong();
            List[i]->Xuat();
        }
    }
}

int cDSNhanVien::TinhTongLuongPhaiTra()
{
    int tong = 0;
    for (int i = 0; i < List.size(); i++)
        tong += List[i]->GetLuong();

    return tong;
}