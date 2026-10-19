#pragma once
#include "cSach.h"
using namespace std;

class cSTK : public cSach
{
private:
    float fThue;

public:
    cSTK() : fThue(0) {}
    cSTK(float thue) : fThue(thue) {}

    void Nhap();
    void Xuat();
    float tinhTien();

    ~cSTK() {}
};  