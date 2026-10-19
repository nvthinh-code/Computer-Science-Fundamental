//MSSV: 25521778    
//Họ và Tên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: IT002.Q22.CNVN.2
#include "cDSGiaoDich.h"
using namespace std;

int main()
{
    cDSGiaoDich L;
    L.Nhap();

    cout << "Danh sach vua nhap la:\n";
    L.Xuat();

    cout << "Giao dich Vang co thanh tien cao nhat la:\n";
    int posMax = L.TimViTriGiaoDichVangCoThanhTienCaoNhat();
    if (posMax != -1) 
        L[posMax]->Xuat();
    else   
        cout << "Khong co giao dich Vang nao.\n";
    
    cout << "Giao dich Euro co thanh tien thap nhat la:\n";
    int posMin = L.TimViTriGiaoDichEuroCoThanhTienThapNhat();
    if (posMin != -1)
        L[posMin]->Xuat(); 
    else
        cout << "Khong co giao dich Euro nao.\n";

    cout << "Danh sach cac giao dich co thanh tien tren 1 ti dong la:\n";
    if (L.KiemTraXemCoTonTaiGiaoDichThanhTienTren1TiDong())
        L.XuatGiaoDichThanhTienTren1TiDong();
    else
        cout << "Khong ton tai giao dich nao co thanh tien tren 1 ti dong:\n";

    return 0;
}