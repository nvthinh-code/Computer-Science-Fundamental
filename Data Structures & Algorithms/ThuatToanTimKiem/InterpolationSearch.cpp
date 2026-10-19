#include <iostream>
#include <vector>
using namespace std;
// Input: Mảng v có n phần tử đã được sắp xếp tăng dần
// Output: Vị trí của target

int interpolationSearch(vector<int> &v, int n, int target)
{
    int l = 0, r = v.size() - 1;
    while (l <= r && target >= v[l] && target <= v[r])
    {
        if (l == r)
        {
            if (v[l] == target)
                return l;
            return -1;
        }
        int pos = l + ((r - l) * (target - v[l]) / (v[r] - v[l]));
        if (v[pos] == target)
            return pos;
        else if (v[pos] > target)
            r = pos - 1;
        else
            l = pos + 1;
    }
    return -1;
}

int main()
{
    cout << "Nhap so luong phan tu: " << endl;
    int n;
    cin >> n;
    cout << "Nhap cac phan tu cua mang v: " << endl;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << "Target la: " << endl;
    int target;
    cin >> target;

    cout << "Vi tri xuat hien la: " << interpolationSearch(v, n, target);

    return 0;
}