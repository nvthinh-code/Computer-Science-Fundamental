#include <iostream>
#include <vector>

using namespace std;

void BubbleSort(vector<int> &a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool daSwap = false;
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                daSwap = true;
            }
        }
        if (!daSwap)
            return;
    }
}

void Nhap(vector<int> &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
}

int main()
{
    // Input
    int n;
    cin >> n;
    vector<int> v;
    Nhap(v, n);
    // BS
    BubbleSort(v, n);
    // Output
    for (int x : v)
    {
        cout << x << " ";
    }

    return 0;
}