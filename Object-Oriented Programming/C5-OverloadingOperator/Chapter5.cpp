#include <iostream>

using namespace std;

class cPhanSo
{
private:
    int iTu;
    int iMau;
public:
    cPhanSo()
    {
        iTu = 0;
        iMau = 1;
    }
    cPhanSo(int iTu, int iMau)
    {
        this->iTu = iTu;
        if (iMau == 0)
            iMau = 1;
        this->iMau = iMau;
    }
    cPhanSo(int x)
    {
        iTu = x;
        iMau = 1;
    }
    void Nhap()
    {
        cin >> iTu >> iMau;
    }
    void Xuat()
    {
        cout << iTu << "/" << iMau;
    }
    int LayTuSo()
    {
        return iTu;
    }
    int LayMauSo()
    {
        return iMau;
    }
    void GanTuSo(int iTu)
    {
        this->iTu = iTu;
    }
    void GanMauSo(int iMau)
    {
        this->iMau = iMau;
    }


    //kq = p + q <-> kq = p.operator+(q)
    //kq = 7 + p (lưu ý)
    cPhanSo operator+(const cPhanSo& a)
    {
        cPhanSo kq;
        kq.iTu = iTu*a.iMau+iMau*a.iTu;
        kq.iMau = iMau*a.iMau;
        
        return kq;
    }
    friend cPhanSo operator +(int x, const cPhanSo& a) //sự nhập nhằng
    {
        int iTu = a.iTu + x*a.iMau;
        return (iTu, a.iMau);
    }
    //Chuyển kiểu: 
        //ví dụ: x = 7.5 + 6 -> x = 7.5 + float(6) ngầm định. vì 6 sẽ học theo kiểu của 7.5 
        //-> kq = p + 5 -> kq = p + cPhanSo(5). khi đó cần định nghĩa constructor cPhanSo(int x).
        
        //chuyển từ kiểu đang định nghĩa -> kiểu đã có: sử dụng phép toán chuyển kiểu:
    

    //Toán tử ">>" và "<<"
    friend istream& operator >>(istream& is, cPhanSo& p)  //Nhập phải có tham chiếu. Lưu ý về nhà viết hàm 
    {
        is >> p.iTu >> p.iMau; //đưa tử và mẫu vào luồng is
        while (p.iMau == 0)
            is >> p.iMau;
        
        return is; //trả về luồng is
    }
    
    friend ostream& operator <<(ostream& os, const cPhanSo& p)
    {
        os << p.iTu << "/" << p.iMau;
        return os;
    }


    //Toán tử "[]": trên mảng.
};

int main()
{
    cPhanSo a, b;
    cin >> a;
    cin >> b;
    cout << "a + b = " << a + b;
    
    return 0;
}

//lưu ý khi thi (nằm ngoài bài chương 5 này): khi phân biệt các phạm vi truy xuất: hàm friend và lớp friend có thể truy xuất vào private.


//Về nhà tìm hiểu lại phần delete cho class có cấp phát động.