
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct NGAY
{
    int Ngay, Thang, Nam;
};
struct SINHVIEN
{
    string MASV;
    string HoTen;
    NGAY NgaySinh;
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};
struct NODE
{
    SINHVIEN key;
    NODE *pNext;
};
struct LIST
{
    NODE *pHead, *pTail;
};

void NhapNgay(NGAY &a);
void XuatNgay(NGAY a);
void NhapSinhVien(SINHVIEN &a);
void XuatSinhVien(SINHVIEN a);

void CreateEmptyList(LIST &L);

NODE *CreateNode(SINHVIEN x)
{
    NODE* p =  new NODE;
    p->key = x;
    p->pNext = NULL;
    return p;
}

void AddTail(LIST &l, NODE *p)
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

    NODE *p = L.pHead;
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
        NODE *p = new NODE;
        NhapSinhVien(p->key);
        p->pNext = NULL;
        AddTail(L, p);
    }
}

void SapXep(LIST &L)
{
    if (L.pHead == nullptr)
        return;

    NODE *p = L.pHead;
    while (p != NULL)
    {
        NODE *temp = p;
        NODE *max = p;
        while (temp != NULL)
        {
            if (max->key.MASV < temp->key.MASV)
                max = temp;
            temp = temp->pNext;
        }
        swap(p->key, max->key);
        p = p->pNext;
    }
}

void ChenGiam(LIST& L, SINHVIEN sv)
{
    NODE* SV = CreateNode(sv);
    if (L.pHead == NULL)
    {
        AddTail(L, SV);
        return;
    }

    NODE* p = L.pHead;
    bool found = false;

    if (SV->key.MASV > p->key.MASV)
    {
        SV->pNext = p;
        L.pHead = SV;
        return;
    }

    while (p->pNext != NULL)
    {
        if (found)
            break;

        if (p->key.MASV > SV->key.MASV)
        {
            if (SV->key.MASV > p->pNext->key.MASV)
            {
                SV->pNext = p->pNext;
                p->pNext = SV;
                found = true;
            }
        }

        p = p->pNext;
    }

    if (!found)
        AddTail(L, SV);
}

bool Xoa_TheoHoTen(LIST &L, string hoten)
{
    if (L.pHead == NULL)
        return false;

    bool found = false;

    while (L.pHead != NULL && L.pHead->key.HoTen == hoten)
    {
        NODE* temp = L.pHead;
        L.pHead = L.pHead->pNext;
        delete temp;
        found = true;
    }

    if (L.pHead == NULL)
        return found;

    NODE* p = L.pHead;
    while (p->pNext != NULL)
    {
        if (p->pNext->key.HoTen == hoten)
        {
            NODE* temp = p->pNext;
            p->pNext = temp->pNext;
            delete temp;
            found = true;
        }
        else 
            p = p->pNext;
    }
    L.pTail = p;
    return found;
}

int main()
{
    LIST L;
    int n;
    string hoten;

    getline(cin, hoten);
    cin >> n ;

    NhapDS(L, n);

    Xoa_TheoHoTen(L, hoten);

    XuatDS(L);

    return 0;
}
void NhapNgay(NGAY &a)
{
    cin >> a.Ngay >> a.Thang >> a.Nam;
}
void XuatNgay(NGAY a)
{
    cout << a.Ngay << "/" << a.Thang << "/" << a.Nam;
}
void NhapSinhVien(SINHVIEN &a)
{
    cin >> ws;
    getline(cin, a.MASV);
    getline(cin, a.HoTen);
    NhapNgay(a.NgaySinh);
    cin >> a.GioiTinh;
    cin >> a.DiemToan >> a.DiemLy >> a.DiemHoa;
    a.DTB = (a.DiemToan + a.DiemLy + a.DiemHoa) / 3;
}
void XuatSinhVien(SINHVIEN a)
{
    cout << a.MASV;
    cout << "\t";
    cout << a.HoTen;
    cout << "\t";
    XuatNgay(a.NgaySinh);
    cout << "\t";
    cout << a.GioiTinh;
    cout << "\t";
    cout << a.DiemToan;
    cout << "\t";
    cout << a.DiemLy;
    cout << "\t";
    cout << a.DiemHoa;
    cout << "\t";
    cout << setprecision(3);
    cout << a.DTB;
}
