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

        int largest = INT_MIN;
        int largestIndex = i;
        for (int j = i; j < v.size(); j++)
        {
            if (largest < v[j])
            {
                largest = v[j];
                largestIndex = j;
            }
        }
        cout << "Phan tu lon nhat trong doan [" << i + 1 << ", " << v.size() - 1 << "]: " << v[largestIndex] << endl;
        cout << "Swap " << v[i] << " va " << v[largestIndex] << endl;
        swap(v[i], v[largestIndex]);
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