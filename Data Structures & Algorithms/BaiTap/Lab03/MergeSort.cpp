#include <iostream> 
#include <vector>
using namespace std;

void mergeSort(vector<int>& v, int left, int right)
{
    if (left >= right)
        return;
    
    int mid = left + (right - left)/2;
    mergeSort(v, left, mid);
    mergeSort(v, mid + 1, right);

    int i = left;
    int j = mid + 1;
    int k = 0;

    vector<int> ans(right - left + 1);
    while (i <= mid && j <= right)
    {
        if (v[i] < v[j])
            ans[k++] = v[i++];
        else
            ans[k++] = v[j++];
    }

    while (i <= mid)
        ans[k++] = v[i++];
    while (j <= right)
        ans[k++] = v[j++];

    for (int l = left; l <= right; l++)
        v[l] = ans[l - left];
}

int main()
{
    int n; 
    cin >> n;
    vector<int> v(n);
    for (int& x : v)
        cin >> x;
    cout << "Mang truoc khi sap xep:\n";
    for (int x : v)
        cout << x << " ";
    cout << endl << endl;
    cout << "Sap xep:\n";
    mergeSort(v, 0, v.size() - 1);
    for (int x : v)
        cout << x << " ";
    return 0;
}