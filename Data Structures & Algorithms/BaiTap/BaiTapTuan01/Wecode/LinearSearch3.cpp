#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &x : v)
        cin >> x;
    
    vector<bool> appeared(n+1, false);
    int mex = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] <= n)
            appeared[v[i]] = true;
        while (appeared[mex])
            mex++;
        cout << mex << " ";
    }
    
    return 0;
}