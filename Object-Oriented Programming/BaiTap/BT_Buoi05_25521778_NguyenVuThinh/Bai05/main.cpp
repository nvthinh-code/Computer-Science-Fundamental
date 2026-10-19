//MSSV: 25521778    
//Họ và Tên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: IT002.Q22.CNVN.2
#include "cDSNhanVien.h"

int main()
{
    cDSNhanVien L;
    L.Nhap();
    L.Xuat();

    cout << "------------------------------------------------------- Tong Luong Phai Tra --------------------------------------------------------\n";
    cout << L.TinhTongLuongPhaiTra();

    return 0;
}