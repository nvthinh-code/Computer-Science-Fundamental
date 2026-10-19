#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<string> find(vector<pair<string, pair<int, string>>> &v, pair<pair<int, int>, string> &x)
{
    vector<string> ans;
    for (auto t : v)
        if (t.second.first >= x.first.first && t.second.first <= x.first.second && t.second.second == x.second)
            ans.push_back(t.first);
        
    return ans;
}

int main()
{
    //Input
    int n;
    cin >> n;
    vector<pair<string, pair<int, string>>> v(n);
    for (auto &x : v)
        cin >> x.first >> x.second.first >> x.second.second;

    pair<pair<int, int>, string> x;
    cin >> x.first.first >> x.first.second >> x.second;

    //Find
    vector<string> res = find(v, x);
    
    //Output
    
    if (res.empty())
        cout << "No suspects found";
    else
    {
        for (string t : res)
            cout << t << " " << endl;
    }
    

    return 0;
}