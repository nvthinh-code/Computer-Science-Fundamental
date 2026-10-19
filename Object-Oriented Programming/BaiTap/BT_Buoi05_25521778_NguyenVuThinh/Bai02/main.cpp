//MSSV: 25521778    
//Họ và Tên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: IT002.Q22.CNVN.2
#include <iostream>
#include <string>
#include "cDanhSach.h"

using namespace std;

int main() {
    cDanhSach ds;

    // 1. Nhap danh sach cac loai sach
    cout << "--- NHAP DANH SACH SACH ---" << endl;
    ds.Nhap();

    // 2. Xuat danh sach da nhap
    cout << "\n--- DANH SACH SACH DA NHAP ---" << endl;
    ds.Xuat();

    // 3. Tinh va xuat tong thanh tien tung loai
    cout << "\n--- THONG KE DOANH THU ---" << endl;
    cout << "Tong thanh tien Sach Giao Khoa: " << ds.tinhTienSGK() << endl;
    cout << "Tong thanh tien Sach Tham Khao: " << ds.tinhTienSTK() << endl;

    // 4. Tinh trung binh cong don gia Sach Tham Khao
    float tbc = ds.TinhTrungBinhCongDonGiaSTK();
    if (tbc != 0) {
        cout << "\nTrung binh cong don gia Sach Tham Khao: " << tbc << endl;
    } else {
        cout << "\nKhong co Sach Tham Khao trong danh sach." << endl;
    }

    // 5. Xuat cac SGK cua nha xuat ban K
    string nxbK;
    cout << "\nNhap ten nha xuat ban K can tim: ";
    cin.ignore(); // Xoa bo dem truoc khi getline
    getline(cin, nxbK);
    ds.XuatSGKTheoNXB(nxbK);

    return 0;
}