#include <iostream> 
#include <vector>
#include <algorithm> 
using namespace std;

//Input: Một danh sách sinh viên
//Output: DSSV được xử lý theo câu hỏi mà đề yêu cầu


//Câu 1. Hãy khai báo cấu trúc dữ liệu dạng DSLK đơn để lưu danh sách sinh viên nói trên.
struct Node
{
    int MSSV;
    string Ten;
    float DTB;
    Node* pNext;
};

Node* InitNode(int MaSoSinhVien, string TenSinhVien, float DTBSinhVien)
{
    Node* p = new Node;
    p->MSSV = MaSoSinhVien;
    p->Ten = TenSinhVien;
    p->DTB = DTBSinhVien;
    p->pNext = NULL;
    return p;
}

struct List
{
    Node* pHead;
    Node* pTail;
};

void InitList(List& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

void AddHead(List& l, Node* p)
{
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else 
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void AddTail(List& l, Node* p)
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

bool IsThatExist(List& l, Node* p)
{
    Node* ptr = l.pHead;
    while (ptr != NULL)
    {
        if (ptr->MSSV == p->MSSV)
        {
            return true;
        }
        ptr = ptr->pNext;
    }
    return false;

    delete []ptr;
}

void Xoa1SVcoMSSVBangX(List& l, int x)
{
    if (l.pHead == NULL) 
        return;

    //Xóa ở đầu
    if (l.pHead->MSSV == x)
    {
        Node* temp = l.pHead;
        l.pHead = l.pHead->pNext;
        delete temp;
        return;
    } 
    Node* p;
    for (p = l.pHead; p->pNext->pNext != NULL; p = p->pNext)
    {
        if (p->pNext->MSSV == x)
        {
            Node* temp = p->pNext;
            p->pNext = temp->pNext;
            delete temp;
            return; 
        }
    }
    //Xóa ở cuối
    if (p->pNext->MSSV == x)
    {
        Node* temp = p->pNext;
        l.pTail = p;
        delete temp;
    }
}

void LietKeThongTinHocSinhCoDTBLonHonBang5(List& l)
{
    Node* p = l.pHead;
    while (p != NULL)
    {
        if (p->DTB >= 5.0)
        {
            cout << p->MSSV << " " << p->Ten << " " << endl;
        }
        p = p->pNext;
    }
}

void XepLoaiVaInRaThongTinCuaHocSinhTheoDTB(List& l)
{
    for (Node* p = l.pHead; p != NULL; p = p->pNext)
    {
        float score = p->DTB;
        if (score < 3.6) 
        {
            cout << p->MSSV << " " << p->Ten << " " << "Loai Kem" << endl;
        }
        else if (score >= 3.6 && score < 5.0)
        {
            cout << p->MSSV << " " << p->Ten << " " << "Loai Yeu" << endl;
        }
        else if (score >= 5.0 && score < 6.5)
        {
            cout << p->MSSV << " " << p->Ten << " " << "Loai Trung Binh" << endl;
        }
        else if (score >= 6.5 && score < 7.0)
        {
            cout << p->MSSV << " " << p->Ten << " " << "Loai Trung Binh Kha" << endl;
        }
        else if (score >= 7.0 && score < 8.0)
        {
            cout << p->MSSV << " " << p->Ten << " " << "Loai Kha" << endl;
        }
        else if (score >= 8.0 && score < 9.0)
        {
            cout << p->MSSV << " " << p->Ten << " " << "Loai Gioi" << endl;
        }
        else 
            cout << p->MSSV << " " << p->Ten << " " << "Loai Xuat Sac" << endl;
    }
}

bool Compare(Node* a, Node* b)
{
    return a->DTB < b->DTB;
}

void SapXepDSSVTangTheoDTB(List& l)
{
    if (l.pHead == NULL) return;

    //Sắp xếp:

    vector<Node*> arr;
    //Đưa các Node vào arr
    for (Node* p = l.pHead; p != NULL; p = p->pNext)
        arr.push_back(p);
    //Sort
    sort(arr.begin(), arr.end(), Compare);
    //Sửa lại List l mới từ arr
    l.pHead = arr[0]; 
    for (int i = 0; i < arr.size()-1; i++)
    {
        arr[i]->pNext = arr[i+1];
    }
    arr.back()->pNext = NULL;
    l.pTail = arr.back();
}

void ChenSVVaoDSSVDangTang(List& l, Node* ptr)
{
    if (l.pHead == NULL)
    {
        l.pHead = ptr;
        l.pTail = ptr;
        return;
    }

    //Chèn vào đầu List
    if (l.pHead->DTB > ptr->DTB)
    {
        ptr->pNext = l.pHead;
        l.pHead = ptr;
        return;
    }

    //Chèn vào giữa List
    Node* p; 
    for (p = l.pHead; p->pNext != NULL; p = p->pNext)
    {
        if (p->DTB <= ptr->DTB && p->pNext->DTB >= ptr->DTB)
        {
            ptr->pNext = p->pNext;
            p->pNext = ptr;
            return;
        }
    }

    //Chèn vào cuối List
    if (p->DTB <= ptr->DTB)
    {
        p->pNext = ptr;
        l.pTail = ptr;
    }
}

void InDSSV(List& l)
{
    Node* p = l.pHead;
    while (p != NULL)
    {
        cout << p->MSSV << " " << p->Ten << " " << p->DTB << endl;
        p = p->pNext;
    }
}

int main()
{
    //Khởi tạo danh sách sinh viên 
    List DSSV;
    InitList(DSSV);
    
    //Câu 2. Nhập danh sách các sinh viên, và thêm từng sinh viên vào đầu danh sách (việc nhập kết thúc khi tên của một sinh viên bằng khoảng trắn
    cout << "Hãy nhập thông tin từng sinh viên" << endl;
    string name = "";
    while (true)
    {
        cout << "Nhập tên sinh viên: " << endl;
        getline(cin, name);
        if (name.empty()) 
            break;
        cout << "Nhập MSSV: " << endl;
        int MSSV = 0; 
        cin >> MSSV;
        cout << "Nhập DTB" << endl;
        float DTB = 0;
        cin >> DTB;
        cin.ignore();
        Node* p = InitNode(MSSV,name,DTB);
        AddHead(DSSV, p);
    } 
    
    //Câu 3. Tìm một sinh viên có trong lớp học hay không ?
    cout << "Hãy nhập thông tin sinh viên cần tìm: " << endl;
    int MSSV = 0; 
    string Ten = "";
    float DTB = 0;
    cin >> MSSV; 
    cin.ignore();
    getline(cin, Ten);
    cin >> DTB;
    Node* p = InitNode(MSSV, Ten, DTB);
    if (IsThatExist(DSSV, p))
    {
        cout << "Có tồn tại sinh viên trong lớp: " << endl;
    }
    else
    {
        cout << "Không tồn tại sinh viên trong lớp: " << endl;
    }
    //Câu 4. Xoá một sinh viên có MSSV bằng x (x nhập từ bàn phím).
    int x; 
    cin >> x;
    Xoa1SVcoMSSVBangX(DSSV, x);
    //Câu 5. Liệt kê thông tin của các sinh viên có điểm trung bình lớn hơn hay bằng 5.
    cout << "Danh sách sinh viên có DTB >= 5.0: " << endl;
    LietKeThongTinHocSinhCoDTBLonHonBang5(DSSV);
    //Câu 6. Xếp loại và in ra thông tin của từng sinh viên.
    cout << "Thông tin xếp loại của sinh viên dựa trên điểm trung bình: " << endl;
    XepLoaiVaInRaThongTinCuaHocSinhTheoDTB(DSSV);
    //Câu 7. Sắp xếp và in ra danh sách sinh viên tăng theo điểm trung bình.
    cout << "Danh sách sau khi sắp xếp theo: " << endl;
    SapXepDSSVTangTheoDTB(DSSV);
    InDSSV(DSSV);
    //Câu 8. Chèn một sinh viên vào danh sách sinh viên tăng theo điểm trung bình nói trên, sao cho sau khi chèn danh sách sinh viên vẫn tăng theo điểm trung bình
    //Chèn sinh viên vừa được nhập thông tin ở Câu 3. 
    cout << "Danh sách sau khi chèn: " << endl;
    ChenSVVaoDSSVDangTang(DSSV, p);
    InDSSV(DSSV);

    return 0;
}