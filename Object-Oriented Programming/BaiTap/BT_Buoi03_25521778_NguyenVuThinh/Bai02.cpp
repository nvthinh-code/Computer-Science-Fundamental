//MSSV: 25521778   
//Họ và tên sinh viên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: CNVN.2
#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

class cArray
{
private:
    int *ptr;
    int size;

public:
    cArray()
    {
        ptr = nullptr;
        size = 0;
    }
    cArray(int n)
    {
        ptr = new int[n];
        size = n;
    }
    void TaoMangNgauNhienNSoNguyen(int n)
    {
        ptr = new int[n];
        size = n;
        for (int i = 0; i < n; i++)
            *(ptr + i) = rand();
    }
    void XuatCacPhanTuMang()
    {
        for (int i = 0; i < size; i++)
            cout << *(ptr + i) << " ";

        cout << endl;
    }
    int DemSoLanXuatHienXTrongMang(int x)
    {
        int count = 0;
        for (int i = 0; i < size; i++)
            if (*(ptr + i) == x)
                count++;

        return count;
    }
    bool KiemTraTangDan()
    {
        for (int i = 0; i < size; i++)
            if (*(ptr + i) > *(ptr + i + 1))
                return false;

        return true;
    }
    int TimPhanTuLeNhoNhatTrongMang()
    {
        int smallest = INT_MAX;
        bool oddIsAppeared = false;
        for (int i = 0; i < size; i++)
            if (*(ptr + i) % 2 != 0)
            {
                smallest = min(smallest, *(ptr + i));
                oddIsAppeared = true;
            }
        
        if (oddIsAppeared) 
            return smallest;
        else
            return 0;
    }
    bool isPrime(int value)
    {
        if (value < 2)
            return false;
        for (int i = 2; i * i <= value; i++)
            if (value % i == 0)
                return false;

        return true;
    }
    int TimSoNguyenToLonNhatTrongMang()
    {
        int largestPrime = INT_MIN;
        bool primeIsAppeared = false;
        for (int i = 0; i < size; i++)
            if (isPrime(*(ptr + i)))
            {
                largestPrime = max(largestPrime, *(ptr + i));
                primeIsAppeared = true;
            }
        
        if (primeIsAppeared) 
            return largestPrime;
        else
            return 0;
    }
    void NhapMang()
    {
        for (int i = 0; i < size; i++)
            cin >> *(ptr + i);
    }
    // Dung BubbleSort
    void SapXepTangDan()
    {
        for (int i = 0; i < size; i++)
        {
            bool swapped = false;
            for (int j = 0; j < size - 1; j++)
            {
                if (*(ptr + j) > *(ptr + j + 1))
                {
                    swap(*(ptr + j), *(ptr + j + 1));
                    swapped = true;
                }
            }
            if (!swapped)
                break;
        }
    }
    // Merge Sort
    int* temp = new int[size];
    void SapXepGiamDan()
    {
        for (int i = 0; i < size; i++)
        {
            bool swapped = false;
            for (int j = 0; j < size - 1; j++)
            {
                if (*(ptr + j) < *(ptr + j + 1))
                {
                    swap(*(ptr + j), *(ptr + j + 1));
                    swapped = true;
                }
            }
            if (!swapped)
                break;
        }
    }
    ~cArray()
    {
        delete []ptr;
    }
};

int main()
{
    int n;
    cout << "Hãy nhập giá trị n: " << endl;
    cin >> n;
    cArray nums;
    nums.TaoMangNgauNhienNSoNguyen(n);
    
    cout << "Mảng ngẫu nhiên vừa tạo là: " << endl;
    nums.XuatCacPhanTuMang();

    cout << "Hãy nhập giá trị x cần tìm: " << endl;
    int x;
    cin >> x;
    cout << "Số lần xuất hiện phần tử x trong mảng là: " << endl;
    cout << nums.DemSoLanXuatHienXTrongMang(x) << endl;

    cout << "Mảng này ";
    if (nums.KiemTraTangDan())
        cout << "là mảng tăng dần" << endl;
    else    
        cout << "không phải là mảng tăng dần" << endl;

    cout << "Phần tử lẻ nhỏ nhất là: ";
    if (nums.TimPhanTuLeNhoNhatTrongMang() != 0)
        cout << nums.TimPhanTuLeNhoNhatTrongMang() << endl;
    else 
        cout << "Mảng không có phần tử lẻ" << endl;

    cout << "Số nguyên tố lớn nhất trong mảng là: " << endl;
    if (nums.TimSoNguyenToLonNhatTrongMang() != 0)
        cout << nums.TimSoNguyenToLonNhatTrongMang() << endl;
    else
        cout << "Mảng không có số nguyên tố" << endl; 

    cout << "Mảng khi được sắp xếp tăng dần: " << endl;
    nums.SapXepTangDan();
    nums.XuatCacPhanTuMang();
    
    cout << "Mảng khi được sắp xếp giảm dần: " << endl;
    nums.SapXepGiamDan();
    nums.XuatCacPhanTuMang();

    return 0;
}