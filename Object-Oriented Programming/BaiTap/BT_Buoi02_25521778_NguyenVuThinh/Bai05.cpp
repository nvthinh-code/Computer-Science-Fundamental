//MSSV: 25521778   
//Họ và tên sinh viên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: CNVN.2
#include <iostream>

using namespace std;

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

class cDate
{
private:
    int iDay;
    int iMonth;
    int iYear;

public:
    cDate()
    {
        iDay = 1;
        iMonth = 1;
        iYear = 1;
    }
    cDate(int iDay, int iMonth, int iYear)
    {
        if (ValidDate(iDay, iMonth, iYear))
        {
            this->iDay = iDay;
            this->iMonth = iMonth;
            this->iYear = iYear;
        }
        else
        {
            this->iDay = 1;
            this->iMonth = 1;
            this->iYear = 1;
        }
    }
    void Nhap()
    {
        cin >> iDay >> iMonth >> iYear;
    }
    void Xuat()
    {
        cout << iDay << " " << iMonth << " " << iYear << endl;
    }
    void SetDay(int iDay)
    {
        this->iDay = iDay;
    }
    void SetMonth(int iMonth)
    {
        this->iMonth = iMonth;
    }
    void SetYear(int iYear)
    {
        this->iYear = iYear;
    }
    int GetDay()
    {
        return iDay;
    }
    int GetMonth()
    {
        return iMonth;
    }
    int GetYear()
    {
        return iYear;
    }

    void IncreaseDay(int value)
    {
        iDay += value;
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
    }
    void DecreaseDay(int value)
    {
        iDay -= value;
        if (iDay < 1)
        {
            if (iMonth == 1)
            {
                iMonth = 12;
                iYear--;
            }
            else if (iMonth == 1 || iMonth == 3 || iMonth == 5 || iMonth == 7 || iMonth == 8 || iMonth == 10 || iMonth == 12)
            {
                iDay += 31;
                iMonth--;
            }
            else if (iMonth == 2)
            {
                if (IsLeap(iYear))
                {
                    iDay += 29;
                    iMonth--;
                }
                else
                {
                    iDay += 28;
                    iMonth--;
                }
            }
            else
            {
                iDay += 30;
                iMonth--;
            }
        }
    }

    void XuatRaThuTrongTuan()
    {
        int days = 0;
        for (int y = 1; y < iYear; y++)
        {
            if (IsLeap(y))
                days += 366;
            else
                days += 365;
        }

        int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        for (int m = 1; m < iMonth; m++)
        {
            days += monthDays[m - 1];

            if (m == 2 && IsLeap(iYear))
                days += 1;
        }
        days += iDay;

        int thu = days % 7;
        thu++;
        if (thu == 1)
            cout << "Chủ nhật" << endl;
        else
            cout << thu;
    }
};

int main()
{
    cDate a;
    cout << "Hãy nhập ngày tháng năm: " << endl;
    a.Nhap();

    cout << "Ngày tháng năm đã nhập là: " << endl;
    a.Xuat();

    cout << "Nhập giá trị muốn thay đổi: " << endl;
    int day, month, year;
    cin >> day >> month >> year;
    a.SetDay(day);
    a.SetMonth(month);
    a.SetYear(year);

    cout << "Ngày tháng năm đã thay đổi là: " << endl;
    a.Xuat();

    cout << "Thứ trong tuần là: " << endl;
    a.XuatRaThuTrongTuan();

    if (IsLeap(a.GetYear()))
        cout << a.GetYear() << "là năm nhuận" << endl;
    else
        cout << a.GetYear() << "không phải là năm nhuận" << endl;
    
    return 0;
}