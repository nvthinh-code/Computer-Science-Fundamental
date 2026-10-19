//MSSV: 25521778   
//Họ và tên sinh viên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: CNVN.2
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class cNhanVienVP
{
private:
    int maNV;
    string hoTen;
    int ngaySinh;
    float luong;
public:
    cNhanVienVP()
    {
        maNV = 0;
        hoTen = "";
        ngaySinh = 0;
        luong = 0;
    }
    cNhanVienVP(int maNV, string hoTen, int ngaySinh, float luong)
    {
        this->maNV = maNV;
        this->hoTen = hoTen;
        this->ngaySinh = ngaySinh;
        this->luong = luong;
    }
    void Nhap()
    {
        cout << "Nhập mã nhân viên: ";
        cin >> maNV;
        cin.ignore();
        cout << "Nhập họ và tên: ";
        getline(cin, hoTen);
        cout << "Nhập ngày sinh: ";
        cin >> ngaySinh;
        cout << "Nhập lương: ";
        cin >> luong;
    }
    void Xuat()
    {
        cout << maNV << " " << hoTen << " " << ngaySinh << " " << luong << "\n";
    }
    void SetMaNV(int maNV)
    {
        this->maNV = maNV;
    }
    void SetHoTen(string hoTen)
    {
        this->hoTen = hoTen;
    }
    void SetNgaySinh(int ngaySinh)
    {
        this->ngaySinh = ngaySinh;
    }
    void SetLuong(float luong)
    {
        this->luong = luong;
    }
    int GetMaNV()
    {
        return maNV;
    }
    string GetHoTen()
    {
        return hoTen;
    }
    int GetNgaySinh()
    {
        return ngaySinh;
    }
    int GetLuong()
    {
        return luong;
    }
};

// int thangSinh = (a.GetNgaySinh()%1000000)/10000;
// int ngay = (a.GetNgaySinh()%100000000)/1000000;
int TinhTuoi(cNhanVienVP a)
{
    int namSinh = a.GetNgaySinh()%10000;
    return 2026 - namSinh;
}

bool Compare(cNhanVienVP &a, cNhanVienVP &b)
{
    return a.GetLuong() < b.GetLuong();
}

int main()
{
    cout << "Nhập số lượng nhân viên: ";
    int n;
    cin >> n;

    cNhanVienVP* arr = new cNhanVienVP[n];
    for (int i = 0; i < n; i++)
        arr[i].Nhap();
    
    cout << "Mã nhân viên Họ tên Ngày sinh Lương \n";
    for (int i = 0; i < n; i++)
        arr[i].Xuat();

    cout << "Nhân viên có lương cao nhất là:\n";
    int sum = arr[0].GetLuong(); // Tận dụng cho câu sau

    int salaryIndex = 0;
    int highestSalary = arr[0].GetLuong();

    int ageIndex = 0; // Tận dụng vòng for để tính tuổi luôn
    int highestAge = TinhTuoi(arr[0]);
    
    for (int i = 1; i < n; i++)
    {
        sum += arr[i].GetLuong();
        
        float luongNhanVienThui = arr[i].GetLuong();
        if (highestSalary < luongNhanVienThui)
        {
            salaryIndex = i;
            highestSalary = luongNhanVienThui;
        }

        int tuoiNhanVienThui = TinhTuoi(arr[i]); 
        if (highestAge < tuoiNhanVienThui)
        {
            ageIndex = i;
            highestAge = tuoiNhanVienThui;
        }
    }
    arr[salaryIndex].Xuat();

    cout << "Tổng lương công ty phải trả cho nhân viên là:\n";
    cout << sum << "\n";

    cout << "Nhân viên có tuổi cao nhất là:\n";
    arr[ageIndex].Xuat(); 

    cout << "Danh sách nhân viên sau khi sắp xếp theo lương tăng dần:\n";
    sort(arr, arr + n, Compare);
    for (int i = 0; i < n; i++)
        arr[i].Xuat();

    delete []arr;
    return 0;
}