//MSSV: 25521778   
//Họ và tên sinh viên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: CNVN.2
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class cNhanVienSX
{
private:
    int maNV;
    string hoTen;
    int ngaySinh;
    int soSanPham;
    float luong;
    const static int donGia = 10;
public:
    cNhanVienSX() : maNV(0), hoTen(""), ngaySinh(0), soSanPham(0), luong(0) {}
    cNhanVienSX(int maNV, string hoTen, int ngaySinh, int soSanPham) : maNV(maNV), hoTen(hoTen), ngaySinh(ngaySinh), soSanPham(soSanPham), luong(soSanPham*donGia) {}
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
    int GetSoSanPham()
    {
        return soSanPham;
    }
    float GetLuong()
    {
        return luong;
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
    void SetSoSanPham(int soSanPham)
    {
        this->soSanPham = soSanPham;
    }
    void Nhap()
    {
        cout << "Nhập mã nhân viên:";
        cin >> maNV;
        cin.ignore();
        
        cout << "\nNhập họ tên:";
        getline(cin, hoTen);

        cout << "\nNhập ngày sinh theo dạng DDMMYYYY: ";
        cin >> ngaySinh;

        cout << "\nNhập số sản phẩm:";
        cin >> soSanPham;
    }
    void Xuat()
    {
        cout << maNV << " " << hoTen << " " << ngaySinh << " " << soSanPham << " " << luong << "\n";
    }
    float GetDonGia()
    {
        return donGia;
    }
    void TinhLuongNhanVien()
    {
        luong = soSanPham*donGia;
    }
    int TinhTuoi()
    {
        return 2026-ngaySinh%10000;
    }
};

bool compareSalary(cNhanVienSX& a, cNhanVienSX& b)
{
    return a.GetLuong() < b.GetLuong();
}


int main()
{
    cout << "Nhập số nhân viên:\n";
    int n;
    cin >> n;

    cNhanVienSX* ptr = new cNhanVienSX[n];
    for (int i = 0; i < n; i++)
    {
        //Nhập thông tin
        ptr[i].Nhap();
        //Tính lương nhân viên
        ptr[i].TinhLuongNhanVien();
    }

    cout << "Danh sách nhân viên vừa nhập là:\n";
    int indexSalary = 0; 
    float minSalary = ptr[0].GetLuong();
    float sumSalary = 0;
    int indexAge = 0;
    int maxAge = ptr[0].TinhTuoi();
    cout << "Mã số Họ Tên Số Sản Phẩm Lương\n";
    for (int i = 0; i < n; i++)
    {
        sumSalary += ptr[i].GetLuong();
        //Sẵn tiện tìm minSalary
        if (minSalary > ptr[i].GetLuong())
        {
            minSalary = ptr[i].GetLuong();
            indexSalary = i;
        }

        if (maxAge < ptr[i].TinhTuoi())
        {
            maxAge = ptr[i].TinhTuoi();
            indexAge = i;
        }
        ptr[i].Xuat();
    }

    cout << "Nhân viên có lương thấp nhất là:\n";
    cout << "Mã số Họ Tên Ngày Sinh Số Sản Phẩm Lương\n";
    ptr[indexSalary].Xuat();   

    cout << "Tổng lương mà công ty phải trả cho nhân viên là:\n";
    cout << sumSalary << endl;
    
    cout << "Nhân viên có tuổi lớn nhất là:\n";
    cout << "Mã số Họ Tên Ngày Sinh Số Sản Phẩm Lương\n";
    ptr[indexAge].Xuat();   

    sort(ptr, ptr + n, compareSalary);

    cout << "Danh sách nhân viên sau khi sắp xếp theo mức lương tăng dần là:\n";
    cout << "Mã số Họ Tên Ngày Sinh Số Sản Phẩm Lương\n";
    for (int i = 0; i < n; i++)
        ptr[i].Xuat();

    delete []ptr;
    return 0;
}