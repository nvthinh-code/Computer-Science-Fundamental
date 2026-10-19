// CSS: O(n+k), 0<=nums[i]<=10^9
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
// Input: vector nums whose size is n
// Output: sorted vector nums from low to high

void CountingSort(vector<int> &v)
{
    int n = v.size();

    // Tìm max
    int largest = INT_MIN;
    for (int x : v)
        largest = max(largest, x);

    // Mảng đếm
    vector<int> Dem(largest + 1, 0);
    for (int x : v)
        Dem[x]++;

    // Prefix sum (phải <= largest)
    for (int i = 1; i <= largest; i++)
        Dem[i] += Dem[i - 1];

    // Mảng kết quả
    vector<int> ans(n);

    // Duyệt từ phải sang trái để giữ stable
    for (int i = n - 1; i >= 0; i--)
    {
        ans[Dem[v[i]] - 1] = v[i];
        Dem[v[i]]--;
    }

    // Copy lại
    v = ans;
}

int main()
{
    // Input
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &x : v)
        cin >> x;

    // Counting Sort
    CountingSort(v);
    // Output
    for (int x : v)
        cout << x << " ";
}
