//MSSV: 25521778   
//Họ và tên sinh viên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: CNVN.2
#include <iostream>

using namespace std;

// Cài đặt lớp biểu diễn khái niệm thời gian với các thành phần dữ liệu giờ, phút,
// giây và các thao tác thích hợp (nhập, xuất, thiết lập, thay đổi giờ/phút/giây, lấy
// giờ/phút/giây, tăng/giảm giờ/phút/giây,…). Viết chương trình minh họa các chức
// năng đã cài đặt của lớp Thời gian.

class cTime
{
private: 
    int iHour;
    int iMinute;
    int iSecond;
public:
    cTime()
    {
        iHour = 0;
        iMinute = 0;
        iSecond = 0;
    }
    cTime(int iHour, int iMinute, int iSecond)
    {
        this->iHour = iHour;
        this->iMinute = iMinute;
        this->iSecond = iSecond;
    }
    void Nhap()
    {
        do 
        {
            cin >> iHour;
        } while (iHour < 0);

        do 
        {
            cin >> iMinute;
        } while (iMinute < 0);
        
        do 
        {
            cin >> iSecond;
        } while (iSecond < 0);
    }
    void Xuat()
    {
        if (iSecond >= 60)
        {
            iMinute++;
            iSecond -= 60;
        }
        
        if (iMinute >= 60)
        {
            iHour++;
            iMinute -= 60;
        }

        cout << iHour << " " << iMinute << " " << iSecond << endl;
    }
    void TangGio(int iHour)
    {
        this->iHour += iHour;
    }
    void GiamGio(int iHour)
    {
        this->iHour -= iHour;
    }
    void TangPhut(int iMinute)
    {
        this->iMinute += iMinute;
        if (this->iMinute >= 60)
        {
            this->iHour++;
            this->iMinute -= 60;
        }
    }
    void GiamPhut(int iMinute)
    {
        this->iMinute -= iMinute;
        if (this->iMinute < 0)
        {
            this->iHour--;
            this->iMinute += 60;
        }
    }
    void TangGiay(int iSecond)
    {
        this->iSecond += iSecond;
        if (this->iSecond >= 60)
        {
            this->iMinute++;
            this->iSecond -= 60;
        }
    }
    void GiamGiay(int iSecond)
    {
        this->iSecond -= iSecond;
        if (this->iSecond < 0)
        {

        }
    }
    void ThayDoiGiay(int iSecond)
    {
        this->iSecond = iSecond;
    }
    void ThayDoiPhut(int iMinute)
    {
        this->iMinute = iMinute;
    }
    void ThayDoiGio(int iHour)
    {
        this->iHour = iHour;
    }
    int LayGio()
    {
        return iHour;
    }
    int LayPhut()
    {
        return iMinute;
    }
    int LayGiay()
    {
        return iSecond;
    }
};

int main()
{
    cTime a;
    cout << "Hãy nhập thời gian (giờ phút giây): " << endl;
    a.Nhap();

    cout << "Giờ phút giây vừa nhập là: " << endl;
    a.Xuat();
    
    cout << "Nhập giá trị tăng giờ, phút, giây: " << endl;
    int gio, phut, giay;
    cin >> gio >> phut >> giay;
    a.TangGio(gio);
    a.TangPhut(phut);
    a.TangGiay(giay);
    cout << "Giờ phút giây sau khi tăng là: " << endl;
    a.Xuat();

    cout << "Nhập giá trị giảm giờ, phút, giây: " << endl;
    int h, m, s;
    cin >> h >> m >> s;
    a.GiamGio(h);
    a.GiamPhut(m);
    a.GiamGiay(s);
    cout << "Giờ phút giây sau khi giảm là: " << endl;
    a.Xuat();
}