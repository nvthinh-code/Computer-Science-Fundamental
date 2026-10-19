#include "cCuu.h"

void cCuu::Keu()
{
    cout << "beeee....beeee" << endl;
}

float cCuu::VatSua()
{
    float sua = rand() % 6;
    fSoLitSua = sua;
    return sua;
}

int cCuu::SinhCon()
{
    return 1 + rand() % 2;
}