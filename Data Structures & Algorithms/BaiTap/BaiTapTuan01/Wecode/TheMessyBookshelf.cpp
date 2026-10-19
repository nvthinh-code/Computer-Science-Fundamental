#include <iostream>
#include <vector>
#include <string>

using namespace std;

int LinearSearch(vector<string>& v, string find)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == find)
            return i+1;
    }

    return -1;
}

int main()
{
    //Input
    int n;
    cin >> n;
    vector<string> v(n);

    for (string& x : v)
    {
        cin >> x;
        cin.ignore();   
    }

    string find;
    cin >> find;

    //LS
    cout << LinearSearch(v, find);

    return 0;
}