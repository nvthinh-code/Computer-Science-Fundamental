#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> BinarySearch(vector<string>& v, string target, bool& found)
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

int main()
{
    int n;
    cin >> n;
    vector<string> v;

    for (int i = 0; i < n; i++)
    {
        string temp; 
        cin >> temp;
        v.push_back(temp);
    }

    string target;
    cin >> target;
    //BS
    bool found = false;
    vector<int> res;
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