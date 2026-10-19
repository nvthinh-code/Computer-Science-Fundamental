//MSSV: 25521778   
//Họ và tên sinh viên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: CNVN.2
#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
    private:
        string sChuXe;
        string sLoaiXe;
        float fTriGiaXe;
        float fDungTichXylanh;
        float fThueTruocBa = 0;
    public:
        Vehicle()
        {
            sChuXe = "";
            sLoaiXe = "";
            fTriGiaXe = 0;
            fDungTichXylanh = 0;
            fThueTruocBa = 0;
        }
        Vehicle(string sChuXe, string sLoaiXe, float fTriGiaXe, float fDungTichXylanh)
        {
            this->sChuXe = sChuXe;
            this->sLoaiXe = sLoaiXe;
            if (fTriGiaXe < 0)
                fTriGiaXe = 0;
            this->fTriGiaXe = fTriGiaXe;
            if (fDungTichXylanh < 0)
                fDungTichXylanh = 0;
            this->fDungTichXylanh = fDungTichXylanh;
        }
        void Nhap()
        {
            cout << "Hãy nhập chủ xe: " << endl;
            getline(cin, sChuXe);
            cout << "Hãy nhập loại xe: " << endl;
            getline(cin ,sLoaiXe);
            cout << "Hãy nhập trị giá xe: " << endl;
                cin >> fTriGiaXe;
            if (fTriGiaXe < 0)
                fTriGiaXe = 0;
            cout << "Hãy nhập dung tích xylanh: " << endl;
                cin >> fDungTichXylanh;
            if (fDungTichXylanh < 0)
                fDungTichXylanh = 0;
        }
        void XuatThongTinChiTiet()
        {
            cout << "Chủ xe: " << endl;
            cout << sChuXe << endl;
            cout << "Loại xe: " << endl;
            cout << sLoaiXe << endl;
            cout << "Trị giá xe: " << endl;
            cout << fTriGiaXe << endl;
            cout << "Dung tích xylanh: " << endl;
            cout << fDungTichXylanh << endl;
        }
        void TinhThueTruocBa()
        {
            if (fDungTichXylanh < 100)
            {
                fThueTruocBa = fTriGiaXe/100.0;
            }
            else if (fDungTichXylanh >= 100 && fDungTichXylanh <= 200)
            {
                fThueTruocBa = fTriGiaXe*3/100.0;
            }
            else 
                fThueTruocBa = fTriGiaXe*5/100.0;
        }
        float GetThueTruocBa()
        {   
            return fThueTruocBa;
        }
};

int main()
{
    Vehicle xe1("Thinh", "MAYBACH S300", 3000000000, 150);
    xe1.TinhThueTruocBa();
    Vehicle xe2("Hy", "Xe Tank", 5000000000, 400);
    xe2.TinhThueTruocBa();
    Vehicle xe3;
    xe3.Nhap();
    xe3.TinhThueTruocBa();

    cout << "Thông tin chi tiết của xe1: " << endl;
    xe1.XuatThongTinChiTiet();
    cout << "Thuế trước bạ là: " << endl;
    cout << xe1.GetThueTruocBa() << endl;

    cout << "Thông tin chi tiết của xe2: " << endl;
    xe2.XuatThongTinChiTiet();
    cout << "Thuế trước bạ là: " << endl;
    cout << xe2.GetThueTruocBa() << endl;

    cout << "Thông tin chi tiết của xe3: " << endl;
    xe3.XuatThongTinChiTiet();
    cout << "Thuế trước bạ là: " << endl;
    cout << xe3.GetThueTruocBa() << endl;

    return 0;
}