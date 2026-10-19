#pragma once
#include <iostream>
#include <string>
using namespace std;

class cNhanVien
{
protected:
    string sHoTen;
    string sNgaySinh;
    int iLuong;

public:
    cNhanVien() : sHoTen(""), sNgaySinh(""), iLuong() {}
    cNhanVien(string hoten, string ngaysinh, int luong) : sHoTen(hoten), sNgaySinh(ngaysinh), iLuong(luong) {}
    
    virtual void Nhap(); 
    virtual void Xuat();
    virtual int TinhLuong() = 0;
    int GetLuong() { return iLuong; }

    virtual ~cNhanVien() {}
};