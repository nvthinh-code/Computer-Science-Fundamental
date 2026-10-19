#include <iostream>
#include <vector>

using namespace std;

void QuickSort(vector<int>& v, int left, int right, int& step)
{
    if (left >= right)
        return;

    int pivot = v[left+(right-left)/2];
    int i = left;
    int j = right;

    while (i <= j)
    {
        while (v[i] < pivot)
            i++;
        //Dừng lại khi đã tìm thấy phần tử > pivot nhưng lại đứng ở mảng bên trái (mảng có những số nhỏ hơn pivot)
        while (v[j] > pivot)
            j--;
        //Tương tự
        
        if (i <= j)
        {
            swap(v[i++], v[j--]);
            step++;
            //Sau khi swap rồi thì tăng i lên và giảm j xuống để tìm xem còn sót lại phần tử nào không thì swap tiếp
        }
    }

    QuickSort(v, left, j, step);
    QuickSort(v, i, right, step);
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

    //[2,3,1]
    //-> [1,2,3]

    return 0;
}