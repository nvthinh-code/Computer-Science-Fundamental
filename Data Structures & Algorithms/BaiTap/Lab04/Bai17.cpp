
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct NGAY {
    int Ngay, Thang, Nam;
};
struct SINHVIEN {
    string MASV;
    string HoTen;
    NGAY NgaySinh;
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};
struct NODE{
    SINHVIEN key;
    NODE* pNext;
};
struct LIST{
    NODE*pHead, *pTail;
};

void NhapNgay(NGAY &);
void XuatNgay(NGAY);
void NhapSinhVien(SINHVIEN &);
void XuatSinhVien(SINHVIEN );
NODE* CreateNode(SINHVIEN );
void CreateEmptyList(LIST &);

void Tim_SinhVien_TheoNamSinh(LIST L, int Y)
{
    NODE* p = L.pHead;
    bool found = false;
    while (p != NULL)
    {
        if (p->key.NgaySinh.Nam == Y)
        {
            XuatSinhVien(p->key);
            cout << endl;
            found = true;
        }
        
        p = p->pNext;
    }
    if (!found)
        cout << "Not found in list.";
}

void AddTail(LIST& l, NODE* p)
{
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void XuatDS(LIST L)
{
    if (L.pHead == NULL)
    {
        cout << "Empty List.";
        return;
    }

    NODE* p = L.pHead;
    while (p != NULL)
    {
        XuatSinhVien(p->key);
        cout << "\n";
        p = p->pNext;
    }
}

void NhapDS(LIST &L, int n)
{
    L.pHead = NULL;
    L.pTail = NULL;
    for (int i = 0; i < n; i++)
    {
        NODE* p = new NODE;
        NhapSinhVien(p->key);
        p->pNext = NULL;
        AddTail(L, p);
    }
}

int main() {
    LIST L;
    int n, namsinh;

    cin >> namsinh;
    cin >> n ;
    NhapDS(L, n);

    Tim_SinhVien_TheoNamSinh(L, namsinh);

    return 0;
}
void NhapNgay(NGAY &a){
    cin >> a.Ngay >> a.Thang >> a.Nam;
}
void XuatNgay(NGAY a){
    cout << a.Ngay << "/" << a.Thang << "/" << a.Nam;
}
void NhapSinhVien(SINHVIEN &a){
    cin >> ws;
    getline(cin, a.MASV);
    getline(cin, a.HoTen);
    NhapNgay(a.NgaySinh);
    cin >> a.GioiTinh;
    cin >> a.DiemToan >> a.DiemLy >> a.DiemHoa;
    a.DTB = (a.DiemToan + a.DiemLy + a.DiemHoa) / 3;
}
void XuatSinhVien(SINHVIEN a){
    cout << a.MASV;         cout << "\t";
    cout << a.HoTen;        cout << "\t";
    XuatNgay(a.NgaySinh);   cout << "\t";
    cout << a.GioiTinh;     cout << "\t";
    cout << a.DiemToan;     cout << "\t";
    cout << a.DiemLy;       cout << "\t";
    cout << a.DiemHoa;      cout << "\t";
    cout << setprecision(3);
    cout << a.DTB;
}

