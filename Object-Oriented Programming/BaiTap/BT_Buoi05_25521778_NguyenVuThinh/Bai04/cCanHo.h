#include "cBDS.h"

class cCanHo : public cBDS
{
private:
    string sMaCan;
    string sTang;

public:
    cCanHo() : sMaCan(""), sTang("") {}
    cCanHo(string macan, string tang) : sMaCan(macan), sTang(tang) {}

    void Nhap();
    void Xuat();
    float TinhThanhTien();

    ~cCanHo() {}
};