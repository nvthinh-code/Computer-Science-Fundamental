// Selection Sort: find the smallest/largest from (i,n-1), and swap(nums[i], nums[smallest_index])
#include <iostream>
#include <vector>
using namespace std;
// Input: vector nums whose size is n
// Output: nums is sorted from low to high

void nhapVector(vector<int> &nums, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
}
// nums = [6,2,3,9,1]
// nums = [1,2,3,9,6]
// nums = [1,2,3,6,9]
void selectionSort(vector<int> &nums, int n)
{
    for (int i = 0; i < n; i++)
    {
        int small = nums[i];
        int locate = i;
        for (int j = i; j < n; j++)
        {
            if (small > nums[j])
            {
                small = nums[j];
                locate = j;
            }
        }
        swap(nums[i], nums[locate]);
    }
}

void xuatVector(vector<int> &nums, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}

int main()
{
    // input
    int n;
    cin >> n;
    vector<int> nums;
    nhapVector(nums, n);
    // selection sort
    selectionSort(nums, n);
    // output
    xuatVector(nums, n);
    return 0;
}