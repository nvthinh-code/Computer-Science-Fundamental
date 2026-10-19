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
    float GetX()
    {
        return x;
    }
    float GetY()
    {
        return y;
    }
    void SetX(float x)
    {
        this->x = x;
    }
    void SetY(float y)
    {
        this->y = y;
    }
};


class cTamGiac
{
private:
    cDiem A;
    cDiem B;
    cDiem C;
public:
    cTamGiac() : A(0, 0), B(0, 0), C(0, 0) {}
    cTamGiac(float a1, float a2, float b1, float b2, float c1, float c2) : A(a1, a2), B(b1, b2), C(c1, c2) {}
    void Nhap()
    {
        cout << "Hãy nhập điểm A: " << endl;
        A.Nhap();
        cout << "Hãy nhập điểm B: " << endl;
        B.Nhap();
        cout << "Hãy nhập điểm C: " << endl;
        C.Nhap();
    }
    void Xuat()
    {
        cout << A.GetX() << " " << A.GetY() << endl;
        cout << B.GetX() << " " << B.GetY() << endl;
        cout << C.GetX() << " " << C.GetY() << endl;
    }
    float TinhDoDaiDoan(cDiem A, cDiem B)
    {
        return sqrt(pow(A.GetX()-B.GetX(), 2) + pow(A.GetY()-B.GetY(), 2));
    }
    float TinhChuVi()
    {
        float canh1, canh2, canh3;
        canh1 = TinhDoDaiDoan(A, B);
        canh2 = TinhDoDaiDoan(A, C);
        canh3 = TinhDoDaiDoan(B, C);
        
        return canh1 + canh2 + canh3;
    }
    float TinhDienTich()
    {
        float nuaChuVi = TinhChuVi()/2.0;
        return sqrt(nuaChuVi*(nuaChuVi-TinhDoDaiDoan(A, B))*(nuaChuVi-TinhDoDaiDoan(A, C))*(nuaChuVi-TinhDoDaiDoan(B, C)));
    }
    void TinhTien(float dx, float dy)
    {
        A.SetX(A.GetX() + dx);
        A.SetY(A.GetY() + dy);
        B.SetX(B.GetX() + dx);
        B.SetY(B.GetY() + dy);
        C.SetX(C.GetX() + dx);
        C.SetY(C.GetY() + dy);
    }
    void Zoom(float k)
    {
        A.SetX(A.GetX()*k);
        A.SetY(A.GetY()*k);
        B.SetX(B.GetX()*k);
        B.SetY(B.GetY()*k);
        C.SetX(C.GetX()*k);
        C.SetY(C.GetY()*k);
    }
    bool LaTamGiacVuong()
    {
        float canh1, canh2, canh3;
        canh1 = TinhDoDaiDoan(A, B);
        canh2 = TinhDoDaiDoan(A, C);
        canh3 = TinhDoDaiDoan(B, C);

        if (canh1*canh1+canh2*canh2 == canh3*canh3 || canh1*canh1+canh3*canh3 == canh2*canh2 || canh2*canh2+canh3*canh3 == canh1*canh1)
            return true;
        
        return false;
    }
    bool LaTamGiacCan()
    {
        float canh1, canh2, canh3;
        canh1 = TinhDoDaiDoan(A, B);
        canh2 = TinhDoDaiDoan(A, C);
        canh3 = TinhDoDaiDoan(B, C);

        if (canh1 == canh2 || canh1 == canh3 || canh2 == canh3)
            return true;
        
        return false;
    }
    bool LaTamGiacDeu()
    {
        float canh1, canh2, canh3;
        canh1 = TinhDoDaiDoan(A, B);
        canh2 = TinhDoDaiDoan(A, C);
        canh3 = TinhDoDaiDoan(B, C);

        if (canh1 == canh2 && canh2 == canh3)
            return true;

        return false;
    }
    bool LaTamGiacThuong()
    {
        if (!LaTamGiacVuong() && !LaTamGiacCan())
            return true;
        
        return false;
    }
};

int main()
{
    cTamGiac t;
    t.Nhap();
    
    cout << "Tam giác vừa nhập là: " << endl;
    t.Xuat();

    cout << "Chu vi tam giác này là: " << endl;
    cout << t.TinhChuVi() << endl;

    cout << "Diện tích tam giác này là: " << endl;
    cout << t.TinhDienTich() << endl;

    cout << "Hãy nhập giá trị tịnh tiến cho tam giác: " << endl;
    float dx, dy;
    cin >> dx, dy;
    t.TinhTien(dx, dy);
    cout << "Tam giác sau khi tịnh tiến: " << endl;
    t.Xuat();

    cout << "Hãy nhập giá trị để phóng to/thu nhỏ tam giác: " << endl;
    float k;
    cin >> k;
    t.Zoom(k);
    cout << "Tam giác sau khi phóng to/thu nhỏ " << k << " lần: " << endl;
    t.Xuat();

    cout << "Tam giác này là: " << endl;
    if (t.LaTamGiacDeu())
        cout << "Tam giác đều" << endl;
    else if (t.LaTamGiacVuong())
        cout << "Tam giác vuông" << endl;
    else if (t.LaTamGiacCan())
        cout << "Tam giác cân" << endl;
    else if (t.LaTamGiacThuong())
        cout << "Tam giác thường" << endl;

    return 0;
}