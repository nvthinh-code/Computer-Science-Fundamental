#include "cDe.h"

void cDe::Keu()
{
    cout << "be...eee.eee" << endl;
}

float cDe::VatSua()
{
    float sua = rand() % 11;
    fSoLitSua = sua;
    return sua;
}

int cDe::SinhCon()
{
    return 1 + rand() % 2;
}