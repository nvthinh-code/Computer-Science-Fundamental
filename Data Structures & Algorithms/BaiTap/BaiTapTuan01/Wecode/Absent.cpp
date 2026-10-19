#include <iostream>
#include <vector>
#include <string>

using namespace std;

string LinearSearch(vector<string>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].back() == 'A')
            return v[i];
    }

    return "All Present";
}

int main()
{
    //Input
    int n;
    cin >> n;
    cin.ignore();
    vector<string> v(n);

    for (string& x : v)
        getline(cin, x);  

    //LS
    string temp;
    temp = LinearSearch(v);
    if (temp != "All Present")
    {
        string res = ""; 
        for (int i = 0; i < temp.size()-2; i++)
            res += temp[i];
        cout << res;
    }
    else
        cout << temp;
    
    return 0;
}