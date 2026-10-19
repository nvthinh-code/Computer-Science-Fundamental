//MSSV: 25521778   
//Họ và tên sinh viên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: CNVN.2
#include <iostream>

using namespace std;

struct Date
{
    int day, month, year;
};

void nhapDate(Date &x)
{
    cin >> x.day >> x.month >> x.year;
}

void xuatDate(Date x)
{
    cout << x.day << " " << x.month << " " << x.year;
}

bool ValidDate(int day, int month, int year)
{
    if (year <= 0)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1)
        return false;

    int daysInMonth;

    if (month == 2)
    {
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
            daysInMonth = 29;
        else
            daysInMonth = 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        daysInMonth = 30;
    else
        daysInMonth = 31;

    return day <= daysInMonth;
}

bool IsLeap(int year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

void TangNgayLen1(Date& A)
{
    int iDay = A.day;
    int iMonth = A.month;
    int iYear = A.year;

    iDay++;

    if (iMonth == 1 || iMonth == 3 || iMonth == 5 || iMonth == 7 || iMonth == 8 || iMonth == 10 || iMonth == 12)
    {
        if (iDay > 31)
        {
            iDay -= 31;
            iMonth++;
        }
        if (iMonth > 12)
        {
            iMonth = 1;
            iYear++;
        }
    }
    else if (iMonth == 2)
    {
        if (IsLeap(iYear))
        {
            if (iDay > 29)
            {
                iDay -= 29;
                iMonth++;
            }
        }
        else
        {
            if (iDay > 28)
            {
                iDay -= 28;
                iMonth++;
            }
        }
    }
    else
    {
        if (iDay > 30)
        {
            iDay -= 30;
            iMonth++;
        }
    }

    A.day = iDay;
    A.month = iMonth;
    A.year = iYear;
}

int main()
{
    // Nhập date
    Date A;
    nhapDate(A);

    // Kiểm tra nếu date hợp lệ
    if (ValidDate(A.day, A.month, A.year))
    {
        cout << "Ngày hợp lệ, ngày tiếp theo là: " << endl;
        TangNgayLen1(A);
        cout << A.day << " " << A.month << " " << A.year;
    }

    else
        cout << "Ngày không hợp lệ";

    return 0;
}
