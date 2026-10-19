#include <iostream> 
#include <vector>

using namespace std;

void quickSort(vector<int> &v, int left, int right)
{
    if (left >= right)
        return;
    
    int i = left, j = right, pivot = v[left + (right - left)/2];

    while (i <= j)
    {
        while (v[i] < pivot)
            i++;
        while (v[j] > pivot)
            j++;

        if (i <= j)
            swap(v[i++], v[j--]);
    }
    
    if (left < j)
        quickSort(v, left, j);
    if (i > right)
        quickSort(v, i, right);
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i]; 
    }

    quickSort(v, 0, v.size()-1);

    for (int x : v)
        cout << x << " ";

    return 0;
}