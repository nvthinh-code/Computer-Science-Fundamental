#include "cDSGiaoDich.h"

void cDSGiaoDich::Nhap()
{
    cout << "Vui long nhap so phan tu cua danh sach: ";
    int n;
    cin >> n;
    List.resize(n);
    for (int i = 0; i < n; i++)
    {
        bool bLoaiGiaoDich;
        cout << "Ban muon nhap Vang (1) hay Tien (0): ";
        cin >> bLoaiGiaoDich;

        if (bLoaiGiaoDich)
            List[i] = new cVang;
        else
            List[i] = new cTien;

        List[i]->Nhap();
    }
}

void cDSGiaoDich::Xuat()
{
    // Xuat Vang
    for (int i = 0; i < List.size(); i++)
        if (dynamic_cast<cVang*>(List[i]) != NULL)
            List[i]->Xuat();
    
    // Xuat Tien
    for (int i = 0; i < List.size(); i++)
        if (dynamic_cast<cTien*>(List[i]) != NULL)
            List[i]->Xuat();
}

int cDSGiaoDich::TimViTriGiaoDichVangCoThanhTienCaoNhat()
{
    float tienCaoNhat = -1;
    int viTri = -1;
    for (int i = 0; i < List.size(); i++)
    {
        cVang* ptr = dynamic_cast<cVang*>(List[i]);
        if (ptr != NULL)
        {
            if (viTri == -1 || ptr->TinhTien() > tienCaoNhat)
            {
                tienCaoNhat = ptr->TinhTien();
                viTri = i;
            }
        }
    }    

    return viTri;
}

int cDSGiaoDich::TimViTriGiaoDichEuroCoThanhTienThapNhat()
{
    float tienThapNhat = -1;
    int viTri = -1;
    for (int i = 0; i < List.size(); i++)
    {
        cTien* ptr = dynamic_cast<cTien*>(List[i]);
        if (ptr != NULL && ptr->GetLoaiTien() == "EURO")
        {
            if (viTri == -1 || ptr->TinhTien() < tienThapNhat)
            {
                tienThapNhat = ptr->TinhTien();
                viTri = i;
            }
        }
    }
    
    return viTri;
}

cDSGiaoDich::~cDSGiaoDich()
{
    for (int i = 0; i < List.size(); i++)
        delete List[i];
    
    List.clear();
}

bool cDSGiaoDich::KiemTraXemCoTonTaiGiaoDichThanhTienTren1TiDong()
{
    for (int i = 0; i < List.size(); i++)
        if (List[i]->TinhTien() > 1000000000)
            return true;
        
    return false;
}

void cDSGiaoDich::XuatGiaoDichThanhTienTren1TiDong()
{
    for (int i = 0; i < List.size(); i++)
        if (List[i]->TinhTien() > 1000000000)
            List[i]->Xuat();
}