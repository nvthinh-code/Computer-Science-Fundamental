#include "cListGiaSuc.h"

void cListGiaSuc::Nhap()
{
    int n;
    cout << "Vui long nhap so luong gia suc: ";
    cin >> n;
    cin.ignore();
    List.resize(n);
    string sLoai;
    for (int i = 0; i < n; i++)
    {
        cout << "Ban muon nhap Cuu/De/Bo? ";
        getline(cin, sLoai);
        
        if (sLoai == "Cuu")
        {
            List[i] = new cCuu;
            iSoLuongCuu++;
        }
        else if (sLoai == "De")
        {
            List[i] = new cDe;
            iSoLuongDe++;
        }
        else 
        {
            List[i] = new cBo;
            iSoLuongBo++;
        }
    }
}

void cListGiaSuc::XuatRaNhungTiengKeuKhiChuDiVang()
{
    if (iSoLuongBo > 0)
        cout << "Ụm bòa" << endl; 
    if (iSoLuongCuu > 0)
        cout << "beeee....beeee" << endl;;
    if (iSoLuongDe> 0)
        cout << "be...eee...ee" << endl;
}           

void cListGiaSuc::XuatRaSoGiaSucMoiLoai()
{
    cout << "Bo: " << iSoLuongBo << endl;
    cout << "Cuu: " << iSoLuongCuu << endl;
    cout << "De: " << iSoLuongDe << endl;
}

float cListGiaSuc::TinhTongSoLitSuaDaCho()
{
    float tong = 0;
    for (int i = 0; i < List.size(); i++)
        tong += List[i]->VatSua();

    return tong;
}

void cListGiaSuc::DeCon()
{
    for (int i = 0; i < List.size(); i++)
    {
        cBo* bo = dynamic_cast<cBo*>(List[i]);
        if (bo != NULL)
            iSoLuongBo += List[i]->SinhCon();

        cDe* de = dynamic_cast<cDe*>(List[i]);
        if (de != NULL)
            iSoLuongDe += List[i]->SinhCon();

        cCuu* cuu = dynamic_cast<cCuu*>(List[i]);
        if (cuu != NULL)
            iSoLuongCuu += List[i]->SinhCon();
    }
}