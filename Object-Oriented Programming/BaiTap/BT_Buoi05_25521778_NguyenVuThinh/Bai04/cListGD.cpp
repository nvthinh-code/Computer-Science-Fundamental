#include "cListGD.h"

void cListGD::Nhap()
{
    int n;
    cout << "Vui long nhap so luong BDS: ";
    cin >> n;
    cin.ignore();
    List.resize(n);
    string loai;
    for (int i = 0; i < n; i++)
    {
        cout << "Vui long chon Dat/Nha Pho/Can Ho: ";
        getline(cin, loai);
        if (loai == "Dat")
            List[i] = new cDat;
        else if (loai == "Nha Pho")
            List[i] = new cNhaPho;
        else
            List[i] = new cCanHo;

        List[i]->Nhap();
    }
}

void cListGD::Xuat()
{
    // Xuat theo Dat
    for (int i = 0; i < List.size(); i++)
        if (dynamic_cast<cDat*>(List[i]) != NULL)
            List[i]->Xuat();

    // Xuat theo Nha Pho
    for (int i = 0; i < List.size(); i++)
        if (dynamic_cast<cNhaPho*>(List[i]) != NULL)
            List[i]->Xuat();
        
    // Xuat theo Can Ho
    for (int i = 0; i < List.size(); i++)
        if (dynamic_cast<cCanHo*>(List[i]) != NULL)
            List[i]->Xuat();
}

vector<int> cListGD::TinhTongSoLuongTungLoai()
{
    int dat = 0;
    int nhaPho = 0;
    int canHo = 0;
    for (int i = 0; i < List.size(); i++)
    {
        if (dynamic_cast<cDat*>(List[i]) != NULL)
            dat++;
        else if (dynamic_cast<cNhaPho*>(List[i]) != NULL)
            nhaPho++;
        else
            canHo++;
    }

    vector<int> res;
    res.push_back(dat);
    res.push_back(nhaPho);
    res.push_back(canHo);

    return res; 
}

float cListGD::TinhTrungBinhThanhTienCuaGiaoDichCanHoChungCu()
{
    float res = 0;
    int quantity = 0;
    for (int i = 0; i < List.size(); i++)
    {
        cCanHo* ptr = dynamic_cast<cCanHo*>(List[i]);
        if (ptr != NULL)
        {
            res += ptr->TinhThanhTien();
            quantity++;
        }
    }

    return res/quantity;
}

bool cListGD::KiemTraXemCoTonTaiGiaoDichCanHoChungCuKhong()
{
    for (int i = 0; i < List.size(); i++)
    {
        cCanHo* ptr = dynamic_cast<cCanHo*>(List[i]);
        if (ptr != NULL)
            return true;
    }

    return false;
}

cNhaPho* cListGD::TimNhaPhoCoThanhTienCaoNhat()
{
    cNhaPho* ptr = NULL;
    float thanhTienMax = 0;
    for (int i = 0; i < List.size(); i++)
    {
        cNhaPho* p = dynamic_cast<cNhaPho*>(List[i]);
        if (p != NULL)
        {
            if (p->TinhThanhTien() > thanhTienMax)
            {
                ptr = p;
                thanhTienMax = p->TinhThanhTien();
            }
        }
    }

    return ptr;
}

void cListGD::XuatRaDanhSachCacGiaoDichCuaThang12Nam2024()
{
    for (int i = 0; i < List.size(); i++)
        if (List[i]->getNgayGiaoDich().find("12/2024") != string::npos)
            List[i]->Xuat();
}