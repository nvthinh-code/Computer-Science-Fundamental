//MSSV: 25521778   
//Họ và tên sinh viên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: CNVN.2
#include <iostream>
#include <cmath>
using namespace std;

// Viết chương trình cho phép người dùng nhập vào một ngày(ngày tháng năm).
// Xuất ra thứ trong tuần của ngày đó.
// 30-1-2026 is Friday

struct Date
{
    int iDay;
    int iMonth;
    int iYear;
};

void NhapDate(Date &x)
{
    do
    {
        cin >> x.iDay;
    } while (x.iDay <= 0);

    do
    {
        cin >> x.iMonth;
    } while (x.iMonth <= 0);

    do
    {
        cin >> x.iYear;
    } while (x.iYear <= 0);
}

bool IsLeap(int year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

void Xuat(Date x)
{
    if (x.iMonth == 1 || x.iMonth == 3 || x.iMonth == 5 || x.iMonth == 7 || x.iMonth == 8 || x.iMonth == 10 || x.iMonth == 12)
    {
        if (x.iDay > 31)
        {
            x.iDay -= 31;
            x.iMonth++;
        }
        if (x.iMonth > 12)
        {
            x.iMonth = 1;
            x.iYear++;
        }
    }
    else if (x.iMonth == 2)
    {
        if (IsLeap(x.iYear))
        {
            if (x.iDay > 29)
            {
                x.iDay -= 29;
                x.iMonth++;
            }
        }
        else
        {
            if (x.iDay > 28)
            {
                x.iDay -= 28;
                x.iMonth++;
            }
        }
    }
    else
    {
        if (x.iDay > 30)
        {
            x.iDay -= 30;
            x.iMonth++;
        }
    }

    cout << x.iDay << " " << x.iMonth << " " << x.iYear << endl;
}

void XuatRaThuTrongTuan(Date x)
{
    int days = 0;
    for (int y = 1; y < x.iYear; y++)
    {
        if (IsLeap(y))
            days += 366;
        else
            days += 365;
    }

    int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    for (int m = 1; m < x.iMonth; m++)
    {
        days += monthDays[m-1];

        if (m == 2 && IsLeap(x.iYear))
            days += 1;
    }
    days += x.iDay;

    int thu = days % 7;
    thu++;
    if (thu == 1)
        cout << "Chủ nhật" << endl; 
    else 
        cout << thu;
}

int main()
{
    Date a;
    NhapDate(a);

    cout << "Ngày tháng năm hiện tại là: " << endl;
    Xuat(a);

    cout << "Thứ trong tuần là: " << endl;
    XuatRaThuTrongTuan(a);

    return 0;
}
