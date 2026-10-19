//MSSV: 25521778    
//Họ và Tên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: IT002.Q22.CNVN.2
#include "cDanhSachChuyenXe.h"

int main()
{
    cDanhSachChuyenXe L;
    L.Nhap();
    L.Xuat();

    cout << "\n----------------------------------- Tong Doanh Thu Tat Ca Chuyen Xe ------------------------------------------------\n";
    cout << L.TinhTongDoanhThuTatCaChuyenXe() << endl;
    cout << "\n----------------------------------- Tong Doanh Thu Chuyen Xe Noi Thanh ------------------------------------------------\n";
    cout << L.TinhTongDoanhThuNoiThanh() << endl;
    cout << "\n----------------------------------- Tong Doanh Thu Chuyen Xe Ngoai Thanh ------------------------------------------------\n";
    cout << L.TinhTongDoanhThuNgoaiThanh() << endl; 

    return 0;
}