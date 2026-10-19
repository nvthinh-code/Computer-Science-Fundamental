#include <iostream>
#include <vector>

using namespace std;

// 18. Giả sử cho dãy ban đầu là A : {12, 8, 2, 14, 3, 5, 10, 15, 36}. Hãy
// sắp xếp dãy đã cho theo quy tắc:
// a. Các số chẵn (nếu có) có thứ tự tăng dần.
// b. Các số lẻ (nếu có) có thứ tự giảm dần.
// c. Tính chất chẵn / lẻ tại mỗ i vị trí trong dãy A không thay đổ i
// sau khi sắp xếp (tức là trước khi sắp xếp, tại vị trí i của dãy
// A là số chẵn/lẻ thì tại vị trí i của mảng sau khi sắp xếp cũng
// là số chẵn/lẻ).

void quickSort(vector<int> &v, int left, int right)
{
    if (left >= right)
        return;

    int pivot = v[left + (right - left) / 2];
    int i = left, j = right;

    while (i <= j)
    {
        while (v[i] < pivot)
            i++;
        while (v[j] > pivot)
            j--;

        if (i <= j)
            swap(v[i++], v[j--]);
    }

    if (left < j)
        quickSort(v, left, j);
    if (right > i)
        quickSort(v, i, right);
}

int main()
{
    vector<int> A = {12, 8, 2, 14, 3, 5, 10, 15, 36};
    vector<int> copy = A;

    quickSort(A, 0, A.size() - 1);

    //  copy = [12,8,2,14,3,5,10,15,36]
    //     A = [2,3,5,8,10,12,14,15,36]

    //     A = [2,3,5,8,15,12,14,10,36]
    int i=0;
    while (i < A.size())
    {
        if (copy[i] % 2 == 0 && A[i] % 2 == 0)
            i++;
        else if (copy[i] % 2 != 0 && A[i] % 2 != 0)
            i++;
        else if (copy[i] % 2 == 0 && A[i] % 2 != 0)
        {
            int temp = i;
            while (A[temp] % 2 != 0)
                temp++;
            swap(A[i], A[temp]);

            quickSort(A, i+1, temp);

            i++;
        }
        else
        {
            int temp = i;
            while (A[temp] % 2 == 0)
                temp++;
            swap(A[i], A[temp]);

            quickSort(A, i+1, temp);

            i++;
        }
    }

    for (int x : A)
        cout << x << " ";

    return 0;
}