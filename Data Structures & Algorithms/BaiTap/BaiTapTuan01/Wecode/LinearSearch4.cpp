#include <iostream>
#include <vector>

using namespace std;

//Input: t: so test case, trong moi test case co 1 mang n phan tu 
//Output: return ket qua max1-min1 + max2-min2 cua t test case
void quickSort(vector<int>& v, int left, int right)
{
    if (left >= right)
        return;
    int pivot = v[left + (right - left)/2];
    int i = left, j = right, k = left; 
    while (i <= j)
    {
        while (v[i] < pivot)
            i++;
        while (v[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(v[i++], v[j--]);
        }
    }
    if (left < j)
        quickSort(v, left, j);
    if (right > i)
        quickSort(v, i, right);
}

int main()
{
    int t;
    cin >> t;
    vector<int> ans;
    
    while (t--)
    {
        int n; 
        cin >> n;
        vector<int> v(n);
            

        for (int i = 0; i < n; i++)
            cin >> v[i];
        
        quickSort(v, 0, v.size()-1);

        ans.push_back(v[n-1]-v[0] + v[n-2]-v[1]);
    }

    for (int x : ans)
        cout << x << endl;

    return 0;
}