#include <iostream>
#include <vector>

using namespace std;

void MS(vector<int> &v, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    MS(v, left, mid);
    MS(v, mid + 1, right);

    vector<int> ans(right - left + 1);

    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
    {
        if (v[i] <= v[j])
            ans[k++] = v[i++];
        else
            ans[k++] = v[j++];
    }
    while (i <= mid)
        ans[k++] = v[i++];
    while (j <= right)
        ans[k++] = v[j++];

    for (int l = left; l <= right; l++)
        v[l] = ans[l - left];
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    MS(v, 0, v.size() - 1);

    for (int x : v)
        cout << x << " ";

    return 0;
}