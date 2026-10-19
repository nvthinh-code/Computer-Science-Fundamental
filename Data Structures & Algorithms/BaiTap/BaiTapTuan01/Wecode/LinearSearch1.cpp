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

int LinearSearch(vector<int>& v, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (v[i] == target)
        {
            return i;
        }
    }
    return -1;
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
    int res = LinearSearch(v, n, target);
    //Output
    if (res != -1)
    {
        cout << res << endl;
        cout << res+1 << endl;
        cout << v.size()-1-res << endl;
        cout << v.size()-res;
    }
    else
    {
        cout << "-1";
    }
    
    return 0;
}

