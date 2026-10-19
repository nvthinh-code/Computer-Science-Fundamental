#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& v)
{
    for (int i = 1; i < v.size(); i++)
    {
        cout << "i = " << i << endl;
        cout << "Mang truoc khi xu ly: ";
        for (int x : v)
            cout << x << " ";
        cout << endl;
        cout << "Phan tu dang xet A[" << i << "] = " << v[i] << endl;
        int key = v[i];              
        int j = i - 1;
        while (j >= 0 && v[j] < key)
        {
            v[j + 1] = v[j];
            j--;
        }
        cout << "Chen " << key << " vao vi tri k = " << j + 1 << endl; 
        v[j + 1] = key;
        cout << "Mang sau khi xu ly: ";
        for (int x : v)
            cout << x << " ";
        cout << endl << endl;
    }
}

int main()
{
    int n; 
    cin >> n;
    vector<int> v(n);
    for (int& x : v)
        cin >> x;
    cout << "Mang truoc khi sap xep: " << endl;
    for (int x : v)
        cout << x << " ";
    cout << endl << endl;
    cout << "Sap xep:\n";
    insertionSort(v);
    cout << "Mang sau khi sap xep:\n";
    for (int x : v)
        cout << x << " ";

    return 0;
}