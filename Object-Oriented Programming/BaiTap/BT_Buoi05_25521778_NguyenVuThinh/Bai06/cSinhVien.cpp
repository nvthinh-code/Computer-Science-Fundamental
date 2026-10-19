#include "cSinhVien.h"

void cSinhVien::Nhap()
{
    cout << "Vui lòng nhập mã số sinh viên: ";
    cin >> iMaSoSinhVien;
    cin.ignore();
    cout << "Vui lòng nhập họ và tên: ";
    getline(cin, sHoTen);
    cout << "Vui lòng nhập địa chỉ: ";
    getline(cin, sDiaChi);
    cout << "Vui lòng nhập tổng tín chỉ: ";
    int temp;
    cin >> temp;
    ucTongSoTinChi = (unsigned char)temp;
    cout << "Vui lòng nhập điểm trung bình: ";
    cin >> fDiemTrungBinh;
}

void cSinhVien::Xuat()
{
    cout << iMaSoSinhVien << " " << sHoTen << " " << sDiaChi << " " << (int)ucTongSoTinChi << " " << fDiemTrungBinh << " ";
}

