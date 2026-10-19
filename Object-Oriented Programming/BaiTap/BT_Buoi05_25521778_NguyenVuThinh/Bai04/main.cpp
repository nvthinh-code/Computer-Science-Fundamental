//MSSV: 25521778    
//Họ và Tên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: IT002.Q22.CNVN.2
#include "cListGD.h"

int main()
{
    cListGD L;
    L.Nhap();
     
    vector<int> save = L.TinhTongSoLuongTungLoai();
    cout << "Tong so luong tung loai la: " << "Dat: " << save[0] << ". Nha Pho: " << save[1] << ". Can Ho: " << save[2] << "." << endl;

    if (L.KiemTraXemCoTonTaiGiaoDichCanHoChungCuKhong()) 
        cout << "Trung binh thanh tien cua cac can ho chung cu la: " << L.TinhTrungBinhThanhTienCuaGiaoDichCanHoChungCu() << endl;
    else
        cout << "Khong co giao dich can ho chung cu nao:\n";
    
    cout << "Giao dich nha pho co gia tri cao nhat la: "; 
    L.TimNhaPhoCoThanhTienCaoNhat()->Xuat();

    cout << "Danh sach cac giao dich thang 12 nam 2024 la:\n";
    L.XuatRaDanhSachCacGiaoDichCuaThang12Nam2024();

    return 0;
}