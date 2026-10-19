//MSSV: 25521778    
//Họ và Tên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: IT002.Q22.CNVN.2
#include "cListGiaSuc.h"

int main()
{
    srand(time(NULL));
    cListGiaSuc L;
    L.Nhap();

    cout << "Nhung tieng keu trong nong trai khi chu di vang:\n";
    L.XuatRaNhungTiengKeuKhiChuDiVang();

    cout << "Tong lit sua da cho la: ";
    cout << L.TinhTongSoLitSuaDaCho() << endl;

    cout << "Sau 1 luot sinh con, so gia suc moi loai la:\n";
    L.DeCon();
    L.XuatRaSoGiaSucMoiLoai();

    return 0;
}