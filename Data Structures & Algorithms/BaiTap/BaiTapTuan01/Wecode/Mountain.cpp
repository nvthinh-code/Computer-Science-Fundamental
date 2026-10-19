#include <iostream>
#include <vector>

using namespace std;

int BS(vector<int> &v)
{
    int left = 0, right = v.size()-1;
    while (left <= right)
    {	
        int mid = left + (right - left)/2;
        if (v[mid] > v[mid-1])
        {
            if (v[mid] > v[mid+1])
                return v[mid];
            else 
                {
                    left = mid + 1;
                    if (v[left] > v[left+1] && v[left] > v[left-1])
                        return v[left];
                }
        }   
        else
            right = mid - 1;
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //Input
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &x : v)
        cin >> x;
    
    //BS
    int res = BS(v);
    //Output

    cout << res;

    return 0;
}