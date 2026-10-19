//MSSV: 25521778   
//Họ và tên sinh viên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: CNVN.2
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
    void Nhap()
    {
        cin >> iTu >> iMau;
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
};

bool isPrime(int n)
{
    if (n < 2)  
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

class cDSPhanSo
{
private:
    //Vì khi gọi constructor tham chiếu, thứ tự được gán sau dấu ":" sẽ theo thứ tự từ trên xuống dưới trong private (thứ tự khai báo trong class)
    int size;
    cPhanSo *ptr;
public:
    cDSPhanSo() : ptr(NULL), size(0) {}
    cDSPhanSo(int arraySize) : size(arraySize), ptr(new cPhanSo[size]) {}
    void Nhap()
    {
        for (int i = 0; i < size; i++)
            ptr[i].Nhap();
    }
    void Xuat()
    {
        for (int i = 0; i < size; i++)
            cout << ptr[i].LayTuSo() << "/" << ptr[i].LayMauSo() << " ";
        cout << endl;
    }
    float TinhTongCacPhanSo()
    {
        float Tong = 0;
        for (int i = 0; i < size; i++)
        {
            float tuSo = ptr[i].LayTuSo();
            float mauSo = ptr[i].LayMauSo();
            Tong += tuSo/mauSo;
        }
        return Tong;
    }
    cPhanSo TimPhanSoLonNhat()
    {
        cPhanSo kq;
        kq.GanTuSo(INT_MIN);
        kq.GanMauSo(INT_MIN);
        for (int i = 0; i < size; i++)
        {
            float hieu;
            hieu = (kq.LayTuSo()*ptr[i].LayMauSo() - kq.LayMauSo()*ptr[i].LayTuSo())/(float)(kq.LayMauSo()*ptr[i].LayMauSo());
            if (hieu < 0)
            {
                kq.GanTuSo(ptr[i].LayTuSo());
                kq.GanMauSo(ptr[i].LayMauSo());
            }
        }  
        
        return kq;
    }
    cPhanSo TimPhanSoCoTuLaSoNguyenToLonNhat()
    {
        cPhanSo kq;
        kq.GanTuSo(INT_MIN);
        kq.GanMauSo(INT_MIN);
        for (int i = 0; i < size; i++)
        { 
            if (isPrime(ptr[i].LayTuSo()))
            {
                if (kq.LayTuSo() < ptr[i].LayTuSo())
                {
                    kq.GanTuSo(ptr[i].LayTuSo());
                    kq.GanMauSo(ptr[i].LayMauSo());
                }
            }
        }

        return kq;
    }
    void SapXepTangDan()
    {
        for (int i = 0; i < size; i++)
        {
            bool swapped = false;
            for (int j = 0; j < size - i - 1; j++)
            {
                int a = ptr[j].LayTuSo();
                int b = ptr[j].LayMauSo();
                int c = ptr[j+1].LayTuSo();
                int d = ptr[j+1].LayMauSo();
                if (a * d > b * c)
                {
                    cPhanSo temp = ptr[j];
                    ptr[j] = ptr[j + 1];
                    ptr[j + 1] = temp;
                    swapped = true;
                }
            }

            if (!swapped)
                return;
        }
    }
    void SapXepGiamDan()
    {
        for (int i = 0; i < size; i++)
        {
            bool swapped = false;
            for (int j = 0; j < size - i - 1; j++)
            {
                int a = ptr[j].LayTuSo();
                int b = ptr[j].LayMauSo();
                int c = ptr[j+1].LayTuSo();
                int d = ptr[j+1].LayMauSo();
                if (a * d < b * c)
                {
                    cPhanSo temp = ptr[j];
                    ptr[j] = ptr[j + 1];
                    ptr[j + 1] = temp;
                    swapped = true;
                }
            }

            if (!swapped)
                return;
        }
    }

    ~cDSPhanSo()
    {
        delete []ptr;
    }
};

int main()
{
    int n;
    cout << "Hãy nhập kích thước cho mảng: " << endl;
    cin >> n;
    
    cDSPhanSo arr(n);
    cout << "Hãy nhập (các) phân số: " << endl;
    arr.Nhap();

    cout << "Tổng các phân số là: " << endl;
    cout << arr.TinhTongCacPhanSo() << endl;

    cout << "Phân số lớn nhất là: " << endl;
    cPhanSo largest;
    largest = arr.TimPhanSoLonNhat();
    cout << largest.LayTuSo() << "/" << largest.LayMauSo() << endl;

    cout << "Phân số có tử là số nguyên tố lớn nhất là: " << endl;
    cPhanSo largestPrime;
    largestPrime = arr.TimPhanSoCoTuLaSoNguyenToLonNhat();
    cout << largestPrime.LayTuSo() << "/" << largestPrime.LayMauSo() << endl; 

    cout << "Mảng sau khi sắp xếp tăng dần: " << endl;
    arr.SapXepTangDan();
    arr.Xuat();

    cout << "Mảng sau khi sắp xếp giảm dần: " << endl;
    arr.SapXepGiamDan();
    arr.Xuat();

    return 0;
}