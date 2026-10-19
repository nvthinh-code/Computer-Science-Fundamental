#include <iostream> 
#include <vector>

using namespace std;

void selectionSort(vector<int>& v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        cout << "i = " << i << endl;
        cout << "Mang truoc khi swap: ";
        for (int x : v)
            cout << x << " ";
        cout << endl;

        int min = INT_MAX;
        int minIndex = i;
        for (int j = i; j < v.size(); j++)
        {
            if (min > v[j])
            {
                min = v[j];
                minIndex = j;
            }
        }
        cout << "Phan tu nho nhat trong doan [" << i + 1 << ", " << v.size() - 1 << "]: " << v[minIndex] << endl;
        cout << "Swap " << v[i] << " va " << v[minIndex] << endl;
        swap(v[i], v[minIndex]);
        cout << "Mang sau khi swap: ";
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
    cout << "Mang truoc khi sap xep:\n";
    for (int x : v)
        cout << x << " ";
    cout << endl << endl;
    cout << "Sap xep:\n";
    selectionSort(v);
    cout << "Mang sau khi sap xep:\n";
    for (int x : v)
        cout << x << " ";

    return 0;
}