#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int q;
    cin >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    //luu vi tri xuat hien
    unordered_map<long long, vector<int>> mp; //<num, index>
    for (int i = 0; i < n; i++)
    {
        mp[v[i]].push_back(i);
    }

    vector<int> ans;

    for (int i = 0; i < q; i++)
    {
        int x; 
        int y;
        cin >> x;
        cin >> y;

        if (!mp.count(y))
        {
            ans.push_back(-1);
            continue;
        }

        if (x == 1)
        {
            ans.push_back(mp[y][0]);
        }
        else 
        {
            ans.push_back(mp[y][1]);
        }
    }
    
    for (int x : ans)
    {
        cout << x << endl;
    }

    return 0;
}