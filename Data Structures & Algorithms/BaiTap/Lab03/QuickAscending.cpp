#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int> &v, int left, int right)
{
    if (left >= right)
        return;

    int i = left;
    int j = right;
    int pivotIndex = left + (right - left) / 2; 
    int pivotValue = v[pivotIndex];
    cout << "Truoc: ";
    for (int x : v)
        cout << x << " ";
    cout << endl;
    cout << "Left=" << left << " - Right=" << right << " - Pivot=" << pivotValue << endl;
    while (i <= j)
    {
        while (v[i] < pivotValue)
            i++;
        while (v[j] > pivotValue)
            j--;

        if (i <= j)
            swap(v[i++], v[j--]);
    }

    cout << "Sau: ";
    for (int x : v)
        cout << x << " ";
    cout << endl << endl;

    quickSort(v, left, j);
    quickSort(v, i, right);
}

int main()
{
    cout << "Vui lòng nhập số phần tử của mảng: ";
    int n;
    cin >> n;
    vector<int> v(n);
    for (int& x : v)
        cin >> x;
    cout << "Mang truoc khi sap xep:\n";
    for (int x : v)
        cout << x << " ";
    cout << endl << endl;
    cout << "Sap xep:\n";
     
    quickSort(v, 0, v.size() - 1);
    

    cout << "Mang sau khi sap xep:\n";
    for (int x : v)
        cout << x << " ";

    return 0;
}