#include <iostream>
#include <vector> 
using namespace std;
//Viết hàm tìm kiếm phần tử x trên mảng A chứa n số nguyên. 
//Biết A đang có thứ tự > (giảm dần) và chưa biết phân bố giá trị của các phần tử trong A. 
//Su dung Binary Search

int binarySearch(vector<int>& v, int n, int x){
    int l=0,r=n-1;
    while (l<=r){
        int mid = l+(r-l)/2;
        if (v[mid]==x) return mid;
        else if (v[mid] < x) r=mid-1;
        else l=mid+1;
    }
    return -1;
}

int main(){
    int n; cin >> n;
    vector<int> v;
    for (int i=0;i<n;i++){
        int x;cin>>x;
        v.push_back(x);
    }
    int x; cin >> x;
    cout << binarySearch(v,n,x);
    return 0;
}