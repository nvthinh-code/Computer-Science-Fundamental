#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(vector<string> &v, string input)
{
    int left = 0, right = v.size() - 1;
    
    while (left <= right)
    {
        int mid = left + (right - left)/2;
        if (v[mid] == input)    
            return mid + 1;
        else if (v[mid] < input)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main()
{
    //Input
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    string input;
    cin >> input;

    //Handle
    int res = BinarySearch(v, input);
    //Output
    cout << res;

    return 0;
}