#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <limits>

using namespace std;

string bucketSortAndHighestSeverity(vector<pair<string, pair<int, bool>>> &v)
{
    //Tim size cua bucket
    int largest = INT_MIN;
    for (auto x : v)
        largest = max(largest, x.second.first);

    vector<vector<pair<string, bool>>> bucket(largest + 1);
    for (auto x : v)
        bucket[x.second.first].push_back({x.first, x.second.second});

    for (int i = bucket.size() - 1; i >= 0; i--)
    {
        if (bucket[i].empty())
            continue;
        else
        {
            for (int j = 0; j < bucket[i].size(); j++)
            {
                if (!bucket[i][j].second)
                {
                    return bucket[i][j].first;
                }
            }
        }
    }
    
    return "All patients seen";
}

int main()
{
    int n;
    cin >> n;

    vector<pair<string, pair<int, bool>>> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second.first >> v[i].second.second;

    //Handle
    string res = bucketSortAndHighestSeverity(v);

    //Output
    cout << res; 

    return 0;
}