#include <iostream>
#include <vector>

using namespace std;

void Nhap(vector<int>& v, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x; 
        cin >> x;
        v.push_back(x);
    }
}

vector<int> LinearSearch(vector<int>& v, int n, int target)
{
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (v[i] == target)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    Nhap(v, n);
    int target;
    cin >> target;
    //LinearSearch
    vector<int> ans; 
    ans = LinearSearch(v,n,target);
    //Output
    if (ans.size() == 0)
    {
        cout << "0";
        return 0;
    }
    else 
        cout << ans.size() << endl;
    for (int x : ans)
    {
        cout << x << " " << x+1 << endl;
    }   
    
    return 0;
}