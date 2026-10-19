#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

vector<int> BinarySearch(vector<int>& v, int target, bool &found)
{
    int l = 0; 
    int r = v.size()-1;
    vector<int> ans;
    while (l <= r)
    {
        int mid = l + (r-l)/2;
        ans.push_back(mid);
        if (v[mid] == target) 
        {
            found = true;    
            break;
        }
        else if (v[mid] > target)
            r = mid - 1;
        else
            l = mid + 1;
    }

    return ans;
}

void Nhap(vector<int>& v, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x; 
        cin >> x;
        v.push_back(x);
    }
}

int main()
{
    int n; 
    cin >> n;
    vector<int> v;
    Nhap(v, n);
    int target;
    cin >> target;

    //BinarySearch
    vector<int> res;
    bool found = false;
    res = BinarySearch(v, target, found);
    //Output
    
    if (found)
    {
        cout << res.back() << endl;
        cout << res.size();
    }
    else 
    {
        cout << "-1";
    }

    return 0;
}