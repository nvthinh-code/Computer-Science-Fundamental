#include "cDanhSach.h"

void cDanhSach::Nhap()
{
    int n;
    cout << "Vui lòng nhập số lượng sách: ";
    cin >> n;
    list.resize(n);
    bool loai;
    for (int i = 0; i < n; i++)
    {   
        cout << "Vui lòng nhập loại sách - SGK(0), STK(1): ";
        cin >> loai;
        if (loai == 0)
            list[i] = new cSGK;
        else
            list[i] = new cSTK;
        list[i]->Nhap();
    }   
}

void cDanhSach::Xuat()
{
    for (int i = 0; i < list.size(); i++)
        list[i]->Xuat();
}

float cDanhSach::TinhTrungBinhCongDonGiaSTK() {
    float tongDonGia = 0;
    int dem = 0;

    for (int i = 0; i < list.size(); i++) {
        cSTK* pSTK = dynamic_cast<cSTK*>(list[i]);
        if (pSTK != nullptr) {
            tongDonGia += list[i]->getDonGia(); 
            dem++;
        }
    }

    if (dem == 0) return 0; // Tránh lỗi chia cho 0
    return tongDonGia / dem;
}

float cDanhSach::TinhTongThanhTien() {
    float tong = 0;
    for (int i = 0; i < list.size(); i++) {
        tong += list[i]->tinhTien(); 
    }
    return tong;
}

float cDanhSach::tinhTienSGK() {
    float tong = 0;

    for (int i = 0; i < list.size(); i++)
        if (dynamic_cast<cSGK*>(list[i]) != nullptr)
            tong += list[i]->tinhTien();

    return tong;
}

float cDanhSach::tinhTienSTK() {
    float tong = 0;
    for (int i = 0; i < list.size(); i++)
        if (dynamic_cast<cSTK*>(list[i]) != nullptr)
            tong += list[i]->tinhTien();

    return tong;
}

void cDanhSach::XuatSGKTheoNXB(std::string nhaXuatBanK) {
    bool found = false;
    cout << "\nDanh sach SGK cua nha xuat ban " << nhaXuatBanK << ":" << endl;

    for (int i = 0; i < list.size(); i++) {
        // 1. Kiểm tra xem có phải SGK không
        cSGK* pSGK = dynamic_cast<cSGK*>(list[i]);
        
        if (pSGK != nullptr && list[i]->getNhaXuatBan() == nhaXuatBanK) {
            list[i]->Xuat(); // Gọi hàm xuất của SGK
            cout << "--------------------------" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Khong tim thay sach giao khoa nao cua NXB nay." << endl;
    }
}