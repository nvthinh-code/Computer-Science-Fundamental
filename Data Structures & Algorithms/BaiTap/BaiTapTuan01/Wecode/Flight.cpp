#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int BinarySearch(vector<pair<string, int>> &v, string target)
{
    int left = 0;
    int right = v.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (v[mid].first == target)
            return v[mid].second;
        else if (v[mid].first < target)
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
    int n;
    cin >> n;
    vector<pair<string, int>> v(n);
    for (auto &x : v)
        cin >> x.first >> x.second;
    string target;
    cin >> target;

    int found = BinarySearch(v, target);
    if (found == -1)
        cout << "Not Found";
    else 
        cout << found;

    return 0;
}