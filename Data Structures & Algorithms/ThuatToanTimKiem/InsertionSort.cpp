//Insertion Sort: start at index 1, from (0,i) if(nums[i] < nums[i-k]) with k is from (1, i), nums[i-k] move to right 1 step.
#include <iostream>
#include <vector>
using namespace std;
//Input: vector nums whose size is n
//Output: sorted vector nums from low to high

void nhapVector(vector<int>& nums){
    for (int& x : nums)
        cin >> x;
}

void xuatVector(vector<int>& nums){
    for (int x : nums)
        cout << x << " ";
}

//v = [2,3,4,7,3]

void insertionSort(vector<int>& v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > key)
        {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
    }
}

int main(){
    //Input:
    int n; cin >> n;
    vector<int> nums(n);
    nhapVector(nums);
    //Insertion Sort:
    insertionSort(nums);
    //Output:
    xuatVector(nums);
    return 0;
}