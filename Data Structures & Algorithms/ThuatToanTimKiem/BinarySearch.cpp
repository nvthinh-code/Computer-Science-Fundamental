#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(const vector<int> &v, int target, int left, int right)
{
    if (left > right)
        return -1;
    int mid = left + (right - left)/2;
    if (v[mid] > target)
        return BinarySearch(v, target, left, mid - 1);
    else if (v[mid] < target)
        return BinarySearch(v, target, mid + 1, right);
    else
        return mid;
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for (int &x : v)
        cin >> x;

    int target;
    cin >> target;

    cout << (BinarySearch(v, target, 0, v.size() - 1));
    return 0;
}