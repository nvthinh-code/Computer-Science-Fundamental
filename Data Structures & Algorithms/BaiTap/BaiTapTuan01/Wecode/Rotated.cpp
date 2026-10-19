#include <iostream>
#include <vector>

using namespace std;

int FindPeak(vector<int> &v)
{
    int left = 0, right = v.size()-1;
    while (left <= right)
    {	
        int mid = left + (right - left)/2;
        
        if (v[mid] > v[mid-1])
        {
            if (v[mid] > v[mid+1])
                return mid;
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

bool BinarySearch(vector<int> &v, int target, int left, int right)
{
    while (left <= right)
    {
        int mid = left + (right - left)/2;

        if (v[mid] == target)
            return true;
        
        else if (v[mid] < target)
            left = mid + 1;
        
        else   
            right = mid - 1;
    }
    
    return false;
}


int main()
{
    //Input
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &x : v)
        cin >> x;
    int target;
    cin >> target;

    //Handle
    int peak = FindPeak(v);
    if (BinarySearch(v, target, 0, peak) || BinarySearch(v, target, peak + 1, v.size()-1))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}