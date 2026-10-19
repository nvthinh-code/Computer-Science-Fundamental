#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findMaxValue(vector<int>& v, int left, int right)
{
    if (left >= right)
        return v[left];

    int mid = left + (right - left)/2;
    int leftValue = findMaxValue(v, left, mid);
    int rightValue = findMaxValue(v, mid + 1, right);
    return max(leftValue, rightValue);
}

int main()
{
    cout << "Nhập giá trị n: ";
    int n;
    cin >> n;

    cout << "Nhập các giá trị của mảng: ";
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int res = findMaxValue(v, 0, v.size() - 1);
    cout << "Max cua mang la:\n";
    cout << res;
}