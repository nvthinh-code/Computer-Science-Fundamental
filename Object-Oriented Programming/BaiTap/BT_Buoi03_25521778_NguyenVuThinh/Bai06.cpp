//MSSV: 25521778   
//Họ và tên sinh viên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: CNVN.2
#include <iostream>
#include <algorithm>

using namespace std;

class cCandidate
{
private:
    int maSo;
    string hoTen;
    int ngaySinh;
    float diemToan;
    float diemVan;
    float diemAnh;

public:
    cCandidate()
    {
        maSo = 0;
        hoTen = "";
        ngaySinh = 0;
        diemToan = 0;
        diemAnh = 0;
        diemVan = 0;
    }
    cCandidate(int maSo, string hoTen, int ngaySinh, float diemToan, float diemVan, float diemAnh)
    {
        this->maSo = maSo;
        this->hoTen = hoTen;
        this->ngaySinh = ngaySinh;
        this->diemToan = diemToan;
        this->diemVan = diemVan;
        this->diemAnh = diemAnh;
    }
    void Nhap()
    {
        cout << "Nhập mã số: " << endl;
        cin >> maSo;
        cin.ignore();
        cout << "Nhập họ và tên: " << endl;
        getline(cin, hoTen);
        cout << "Nhập ngày sinh: " << endl;
        cin >> ngaySinh;
        cout << "Nhập điểm Toán: " << endl;
        cin >> diemToan;
        cout << "Nhập điểm Văn: " << endl;
        cin >> diemVan;
        cout << "Nhập điểm Anh: " << endl;
        cin >> diemAnh;
    }
    void Xuat()
    {
        cout << "Mã số: " << endl;
        cout << maSo << endl;
        cout << "Họ và tên: " << endl;
        cout << hoTen << endl;
        cout << "Ngày sinh:" << endl;
        cout << ngaySinh << endl;
        cout << "Điểm Toán: " << endl;
        cout << diemToan << endl;
        cout << "Điểm Văn: " << endl;
        cout << diemVan << endl;
        cout << "Điểm Anh:" << endl;
        cout << diemAnh << endl;
    }
    float TinhTongDiem()
    {
        return diemToan + diemAnh + diemVan;
    }
};

bool soSanhTongDiem(cCandidate &ts1, cCandidate &ts2)
{
    return ts1.TinhTongDiem() > ts2.TinhTongDiem();
}

class cListCandidate
{
private:
    int soThiSinh;
    cCandidate *ptr;

public:
    cListCandidate() : soThiSinh(0), ptr(NULL) {}
    cListCandidate(int soThiSinh) : soThiSinh(soThiSinh), ptr(new cCandidate[soThiSinh]) {}
    void Nhap()
    {
        if (ptr != NULL)
            delete[] ptr;

        ptr = new cCandidate[soThiSinh];
        for (int i = 0; i < soThiSinh; i++)
            ptr[i].Nhap();
    }
    void Xuat()
    {
        for (int i = 0; i < soThiSinh; i++)
            ptr[i].Xuat();
    }
    void XuatDanhSachThiSinhCoTongDiemLonHon15()
    {
        for (int i = 0; i < soThiSinh; i++)
            if (ptr[i].TinhTongDiem() > 15)
                ptr[i].Xuat();
    }
    void XuatThongTinThiSinhCoTongDiemLonNhat()
    {
        int locate = 0;
        int highestScore = ptr[locate].TinhTongDiem();
        for (int i = 1; i < soThiSinh; i++)
        {
            if (ptr[i].TinhTongDiem() > highestScore)
            {
                locate = i;
                highestScore = ptr[i].TinhTongDiem();
            }
        }

        ptr[locate].Xuat();
    }
    void SapXepTheoTongDiemGiamDan()
    {
        sort(ptr, ptr + soThiSinh, soSanhTongDiem);
    }
    ~cListCandidate()
    {
        delete[] ptr;
    }
};

int main()
{
    cout << "Hãy nhập số thí sinh: " << endl;
    int n;
    cin >> n;
    cListCandidate arr(n);
    arr.Nhap();

    cout << "Danh sách thí sinh có điểm lớn hơn 15 là: " << endl;
    arr.XuatDanhSachThiSinhCoTongDiemLonHon15();

    cout << "Thí sinh có tổng điểm cao nhất là: " << endl;
    arr.XuatThongTinThiSinhCoTongDiemLonNhat();

    cout << "Danh sách thí sinh được sắp xếp theo tổng điểm giảm dần là: " << endl;
    arr.SapXepTheoTongDiemGiamDan();
    arr.Xuat();

    return 0;
}