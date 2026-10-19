#include <iostream>
using namespace std;
// Các bước chạy với giai thừa 3:
// giaiThua(3) = 3 * giaiThua(2) = 3 * 2 * giaiThua(1) = 3 * 2 * 1 * giaiThua(0) = 3 * 2 * 1 * 1
// quay lui: 1*1 = 1, stack: 3 * 2 * 1. 2 * 1 = 2, stack: 3 * 2. 3 * 2 = 6, stack: 6 -> trả về 6.
int giaiThua(int n)
{
    if (n == 0)
        return 1;
    return n * giaiThua(n - 1);
}

// Tương tự giaiThua
int tinhTongTuMotToiN(int n)
{
    if (n == 0)
        return 0;
    return n + tinhTongTuMotToiN(n - 1);
}

int tinhTongCacPhanTuCuaMang(int* arr, int n)
{
    if (n == -1) 
        return 0;
    return arr[n] + tinhTongCacPhanTuCuaMang(arr, n - 1);
}


int main()
{
    cout << "Nhập giá trị n: ";
    int n;
    cin >> n;
    
    // cout << giaiThua(n);

    cout << "Nhập các giá trị của mảng: ";
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // cout << tinhTongCacPhanTuCuaMang(arr, n - 1) << endl;
    // cout << tinhTongTuMotToiN(n);

    return 0;
}