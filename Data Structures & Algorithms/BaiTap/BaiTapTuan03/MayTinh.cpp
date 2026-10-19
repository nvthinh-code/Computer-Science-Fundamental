#include <iostream>
#include <string>
#include <vector>
// Input: Mảng MayTinh có n phần tử
// Output: In ra 3 mảng được sắp xếp theo 3 tiêu chí, in ra danh sách máy tính có giá trong đoạn [p1,p2], Ghz trong đoạn [s1,s2]

using namespace std;

// 3. Định nghĩa cấu trúc dữ liệu lưu trữ thông tin máy tính gồm: nhãn hiệu máy, tốc độ xử lý (tính theo GHz) và giá bán. Cài đặt các hàm sau
// a)sortByName(…) Sắp xếp danh sách máy theo thứ tự tăng dần đối với nhãn hiệu
// b)sortBySpeed(…) Sắp xếp danh sách máy theo thứ tự giảm dần đối với tốc độ xử lý
// c)sort(…) Sắp xếp danh sách máy theo thứ tự tăng dần giá bán và trong trường hợp cùng giá thì xếp theo thứ tự giảm dần tốc độ xử lý
// d)filter(…) Lọc danh sách các máy tính có giá trong đoạn [p1, p2] và tốc độ xử lý trong đoạn [s1, s2].

struct MayTinh
{
    string NhanHieuMay;
    // GHz và GiaBan có kiểu là int để dễ viết hàm quickSort, mergeSort
    int GHz;
    int GiaBan;
};

void NhapMayTinh(MayTinh &x)
{
    cout << "Hãy nhập nhãn hiệu máy: " << endl;
    cin >> x.NhanHieuMay;
    cout << "Hãy nhập tốc độ xử lý: " << endl;
    cin >> x.GHz;
    cout << "Hãy nhập giá bán: " << endl;
    cin >> x.GiaBan;
    cin.ignore();
}

void sortByName(vector<string> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < v.size() - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            return;
    }
}

void sortBySpeed(vector<MayTinh> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < v.size() - 1; j++)
        {
            if (v[j].GHz > v[j+1].GHz)
            {
                swap(v[j], v[j+1]);
                swapped = true; 
            }
        }
        if (!swapped)
            return;
    }
}

void sortTheoGiaTien(vector<MayTinh> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
        for (int j = 0; j < v.size() - 1; j++)
            if (v[j].GiaBan > v[j + 1].GiaBan || (v[j].GiaBan == v[j + 1].GiaBan && v[j].GHz < v[j + 1].GHz))
                swap(v[j], v[j + 1]);
}

vector<string> filter(vector<MayTinh> &v, int p1, int p2, int s1, int s2)
{
    vector<string> ans;
    for (int i = 0; i < v.size(); i++)
        if (v[i].GiaBan >= p1 && v[i].GiaBan <= p2 && v[i].GHz >= s1 && v[i].GHz <= s2)
            ans.push_back(v[i].NhanHieuMay);

    return ans;
}

int main()
{
    // Nhập dữ liệu
    cout << "Hãy nhập số lượng máy tính: " << endl;
    int n;
    cin >> n;
    vector<MayTinh> v(n);
    for (int i = 0; i < n; i++)
    {
        NhapMayTinh(v[i]);
    }

    // a) sortByName()
    vector<string> name(n);
    for (int i = 0; i < n; i++)
    {
        name[i] = v[i].NhanHieuMay;
    }

    sortByName(name);
    cout << "Sắp xếp theo tên: " << endl;
    for (string x : name)
        cout << x << " ";

    cout << endl;
    // b) sortBySpeed()

    sortBySpeed(v);
    cout << "Sắp xếp theo tốc độ xử lý: " << endl;
    for (auto x : v)
        cout << x.NhanHieuMay << " ";

    cout << endl;
    // c) sort theo giá tiền, nếu trùng thì sort tiếp theo tốc độ xử lý
    sortTheoGiaTien(v);

    cout << "Sắp xếp theo giá tiền: " << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i].NhanHieuMay << " ";

    cout << endl;
    // d) filter(…) Lọc danh sách các máy tính có giá trong đoạn [p1, p2] và tốc độ xử lý trong đoạn [s1, s2].  
    int p1, p2, s1, s2;
    cout << "Hãy nhập p1, p2, s1, s2: " << endl;
    cin >> p1 >> p2 >> s1 >> s2;
    vector<string> res = filter(v, p1, p2, s1, s2);
    cout << "Danh sách các máy tính có giá trong đoạn p1, p2, s1, s2 vừa nhập là: " << endl;
    for (string x : res)
        cout << x << " ";
    
    return 0;
}