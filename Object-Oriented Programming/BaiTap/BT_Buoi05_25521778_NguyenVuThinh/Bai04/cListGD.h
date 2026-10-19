#include "cDat.h"
#include "cNhaPho.h"
#include "cCanHo.h"
#include <vector>

class cListGD
{
private:
    vector<cBDS*> List;

public:
    cListGD() : List(0) {}
    cListGD(int n) : List(n) {}

    void Nhap();
    void Xuat();
    vector<int> TinhTongSoLuongTungLoai();
    float TinhTrungBinhThanhTienCuaGiaoDichCanHoChungCu();
    bool KiemTraXemCoTonTaiGiaoDichCanHoChungCuKhong();
    cNhaPho* TimNhaPhoCoThanhTienCaoNhat();
    void XuatRaDanhSachCacGiaoDichCuaThang12Nam2024();

    ~cListGD() { for(int i = 0; i < List.size(); i++) delete List[i]; List.clear(); }
};
