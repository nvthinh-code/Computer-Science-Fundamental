#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int BS(vector<pair<int, int>> &v, int ID)
{
    int left = 0, right = v.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (v[mid].first == ID)
            return v[mid].second;
        else if (v[mid].first < ID)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // Input
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &x : v)
    {
        cin >> x.first >> x.second;
    }

    int ID;
    cin >> ID;

    // Handle
    int foundIndex = BS(v, ID);

    // Output
    if (foundIndex != -1)
        cout << foundIndex;
    else
        cout << "Not Found";

    return 0;
}