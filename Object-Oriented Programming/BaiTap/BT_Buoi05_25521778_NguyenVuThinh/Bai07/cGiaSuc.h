#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;

class cGiaSuc
{
protected:
    string sLoaiGiaSuc;
    float fSoLitSua;

public:
    cGiaSuc() : sLoaiGiaSuc(""), fSoLitSua(0) {}
    cGiaSuc(string loai, float sua) : sLoaiGiaSuc(loai), fSoLitSua(sua) {}

    virtual void Nhap();
    virtual void Xuat();
    virtual void Keu() = 0;
    virtual float VatSua() = 0;
    virtual int SinhCon() = 0; 

    virtual ~cGiaSuc() {}
};