//MSSV: 25521778   
//Họ và tên sinh viên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: CNVN.2
#include <iostream>
#include <cmath> 

using namespace std;

class cDiem
{
private:
    float x;
    float y;
public:
    cDiem()
    {
        x = 0;
        y = 0;
    }
    cDiem(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    void Nhap()
    { 
        cin >> x >> y;
    }
    void GanX(float x)
    {
        this->x = x;
    }
    void GanY(float y)
    {
        this->y = y;
    }
    float LayX()
    {
        return x;
    }
    float LayY()
    {
        return y;
    }
    void TinhTien(float dx, float dy)
    {
        x += dx;
        y += dy;
    }
    void PhongToThuNho(float k)
    {
        x *= k;
        y *= k;
    }
};

class cDaGiac
{
private:
    int soDinh;
    cDiem* ptr;
public: 
    cDaGiac() : soDinh(0), ptr(NULL) {}
    
    cDaGiac(int soDinh) : soDinh(soDinh), ptr(new cDiem[soDinh]) {}
    
    ~cDaGiac() 
    {
        if (ptr != NULL) {
            delete[] ptr;
            ptr = NULL;
        }
    }

    void Nhap()
    {
        cout << "Nhập số đỉnh của đa giác (>= 3): ";
        cin >> soDinh;
        if (soDinh < 3) {
            cout << "Đa giác phải có ít nhất 3 đỉnh!" << endl;
            return;
        }

        if (ptr != NULL)
            delete []ptr;

        ptr = new cDiem[soDinh];
        for (int i = 0; i < soDinh; i++)
        {
            cout << "Nhập tọa độ đỉnh thứ " << i + 1 << " (x y): ";
            ptr[i].Nhap();
        }
    }

    void Xuat()
    {
        for (int i = 0; i < soDinh; i++)
            cout << "(" << ptr[i].LayX() << ", " << ptr[i].LayY() << ")" << endl;
    }
    
    float TinhDoDaiDoan(cDiem A, cDiem B)
    {
        return sqrt(pow(A.LayX() - B.LayX(), 2) + pow(A.LayY() - B.LayY(), 2));
    }

    float TinhChuVi()
    {
        if (soDinh < 3) return 0;
        float chuVi = 0;
        for (int i = 0; i < soDinh; i++)
        {
            int j = (i + 1) % soDinh;
            chuVi += TinhDoDaiDoan(ptr[i], ptr[j]);
        }
        return chuVi;
    }

    float TinhDienTich()
    {
        if (soDinh < 3) return 0;
        float dienTich = 0;
        for (int i = 0; i < soDinh; i++)
        {
            int j = (i + 1) % soDinh;
            dienTich += (ptr[i].LayX() * ptr[j].LayY() - ptr[j].LayX() * ptr[i].LayY());
        }
        return abs(dienTich) / 2.0;
    }

    void TinhTien(float dx, float dy)
    {
        for (int i = 0; i < soDinh; i++)
        {
            ptr[i].TinhTien(dx, dy);
        }
    }

    void PhongToThuNho(float k)
    {
        for (int i = 0; i < soDinh; i++)
        {
            ptr[i].PhongToThuNho(k);
        }
    }
};

int main()
{
    cDaGiac dg;
    
    cout << "--- NHẬP ĐA GIÁC ---\n";
    dg.Nhap();
    
    cout << "\n--- THÔNG TIN ĐA GIÁC ---\n";
    cout << "Các đỉnh của đa giác vừa nhập:\n";
    dg.Xuat();

    cout << "Chu vi đa giác: " << dg.TinhChuVi() << endl;
    cout << "Diện tích đa giác: " << dg.TinhDienTich() << endl;

    float dx, dy;
    cout << "\nNhập vector tịnh tiến (dx dy): ";
    cin >> dx >> dy;
    dg.TinhTien(dx, dy);
    cout << "Đa giác sau khi tịnh tiến:\n";
    dg.Xuat();

    float k;
    cout << "\nNhập hệ số phóng to/thu nhỏ (k > 1 là phóng to, 0 < k < 1 là thu nhỏ): ";
    cin >> k;
    dg.PhongToThuNho(k);
    cout << "Đa giác sau khi phóng to/thu nhỏ:\n";
    dg.Xuat();

    return 0;
}