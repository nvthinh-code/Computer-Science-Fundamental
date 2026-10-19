#pragma once
#include "cSach.h"
using namespace std;

class cSGK : public cSach
{
private:
    bool bTinhTrang; // Neu moi la 1, cu la 0

public:
    cSGK() : bTinhTrang(0) {}
    cSGK(bool tinhtrang) : bTinhTrang(tinhtrang) {}

    void Nhap();
    void Xuat();
    float tinhTien();

    ~cSGK() {}
};