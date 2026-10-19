//MSSV: 25521778   
//Họ và tên sinh viên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: CNVN.2
#include <iostream>
#include <vector>

using namespace std;

class DonThuc
{
private:
    int iHeSo;
    int iMu;
public:
    DonThuc() : iHeSo(0), iMu(0) {}
    DonThuc(int heSo, int mu) : iHeSo(heSo), iMu(mu) {}
    void Nhap()
    {
        cin >> iHeSo >> iMu;
    }
    void GanHeSo(int iHeSo)
    {
        this->iHeSo = iHeSo;
    }
    void GanMu(int iMu)
    {
        this->iMu = iMu;
    }
    int LayHeSo()
    {
        return iHeSo;
    }
    int LayMu()
    {
        return iMu;
    }
};

class DaThuc
{
private:
    int iBac;
    DonThuc* ptr;
public:
    DaThuc() : iBac(0), ptr(NULL) {}
    DaThuc(int bac, int mangHeSo[]) : iBac(bac)
    {
        int mu = bac;
        ptr = new DonThuc[bac + 1];
        for (int i = 0; i < bac + 1; i++)
        {
            ptr[i].GanHeSo(mangHeSo[i]);
            ptr[i].GanMu(mu--);
        }
    }
    void Nhap()
    {
        if (ptr != NULL)
            delete []ptr;
            
        cout << "Hãy nhập bậc của đa thức: " << endl;
        cin >> iBac;
        int size = iBac + 1;
        int mu = iBac;

        ptr = new DonThuc[size];
        for (int i = 0; i < size; i++)
        {
            cout << "Hãy nhập hệ số bậc " << iBac - i << ":" << endl;
            int heso;
            cin >> heso;

            ptr[i].GanHeSo(heso);
            ptr[i].GanMu(mu--);
        }
    }
    void Xuat()
    {
        for (int i = 0; i < iBac; i++)
        {
            if (ptr[i+1].LayHeSo() > 0)
            {
                if (ptr[i].LayMu() == 0)
                    cout << ptr[i].LayHeSo();
                else if (ptr[i].LayMu() == 1)
                    cout << ptr[i].LayHeSo() << "x";

                else if (ptr[i].LayHeSo() != -1 && ptr[i].LayHeSo() != 1)
                    cout << ptr[i].LayHeSo() << "x^" << ptr[i].LayMu();
                else if (ptr[i].LayHeSo() == 1)
                    cout <<  "x^" << ptr[i].LayMu();
                else if (ptr[i].LayHeSo() == -1)
                    cout << "-x^" << ptr[i].LayMu();   
                
                cout << "+";
            }
            else if (ptr[i+1].LayHeSo() < 0)
            {
                if (ptr[i].LayMu() == 0)
                    cout << ptr[i].LayHeSo();
                else if (ptr[i].LayMu() == 1)
                    cout << ptr[i].LayHeSo() << "x";

                else if (ptr[i].LayHeSo() != -1 && ptr[i].LayHeSo() != 1)
                    cout << ptr[i].LayHeSo() << "x^" << ptr[i].LayMu();
                else if (ptr[i].LayHeSo() == 1)
                    cout <<  "x^" << ptr[i].LayMu();
                else if (ptr[i].LayHeSo() == -1)
                    cout << "-x^" << ptr[i].LayMu();   

                cout << "-";
            }
            else    
                continue;
        }
    }

    ~DaThuc()
    {
        delete []ptr;
    }
};

int main()
{
    DaThuc arr;
    arr.Nhap();

    cout << "Đa thức vừa nhập là: " << endl;
    arr.Xuat();

    return 0;
}