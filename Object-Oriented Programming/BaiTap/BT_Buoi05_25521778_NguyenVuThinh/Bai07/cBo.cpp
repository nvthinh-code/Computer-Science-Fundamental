#include "cBo.h"

void cBo::Keu()
{
    cout << "Ụm bòa" << endl;
}

float cBo::VatSua()
{
    float sua = rand() % 21;
    fSoLitSua = sua;
    return sua;
}

int cBo::SinhCon()
{
    return 1 + rand() % 2;
}