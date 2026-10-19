#include <iostream> 
#include <vector>
#include <limits>
using namespace std;
//Thiết kế giải thuật dạng vét cạn để tìm tập con có tích lớn nhất của dãy a, cài đặt chương trình bằng C/C++/Python
//Input: Mảng a có n phần tử
//Output: Tập con có tích lớn nhất
long long maxProductSubset(vector<int>& a) {
    int n = a.size();
    long long maxProduct = LLONG_MIN;

    for (int k = 1; k <= n; k++) {
        vector<int> idx(k);
        for (int i = 0; i < k; i++)
            idx[i] = i;
        while (true) {
            long long product = 1;
            for (int i = 0; i < k; i++)
                product *= a[idx[i]];
            maxProduct = max(maxProduct, product);
            int i = k - 1;
            while (i >= 0 && idx[i] == n - k + i)
                i--;
            if (i < 0) break;
            idx[i]++;
            for (int j = i + 1; j < k; j++)
                idx[j] = idx[j - 1] + 1;
        }
    }
    return maxProduct;
}
int main(){
    int n; cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x; cin >> x; v.push_back(x);
    }
    cout << maxProductSubset(v);
    return 0;
}