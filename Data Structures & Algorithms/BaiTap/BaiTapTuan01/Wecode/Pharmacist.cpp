#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

//Input: so nguyen n, n loai thuoc va so luong
//Output: loai thuoc con it so luong nhat

string BucketSort(vector<string>& v)
{
    //Tim max stock va tao vector bucket
    vector<pair<int, string>> storage(v.size());
    //Lay cac stocks dua vao storage
    for (int i = 0; i < v.size(); i++)
    {
        int j = v[i].size()-1;
        string num = "";
        while (v[i][j] != ' ')
        {
            num += v[i][j];
            j--;
        }

        reverse(num.begin(), num.end());
        int number = stoi(num);

        storage[i].first = number;
        storage[i].second = v[i];
    }
    int largest = INT_MIN;
    for (auto x : storage)
        largest = max(largest, x.first);

    //Tao bucket
    vector<vector<string>> bucket(largest+1);
    for (auto x : storage)
        bucket[x.first].push_back(x.second);
    for (int i = 0; i < bucket.size(); i++)
    {
        for (int j = 0; j < bucket[i].size(); j++)
        {
            return bucket[i][j];
        }
    }

    return "";
}

int main()
{
    //Input
    int n;
    cin >> n;
    cin.ignore();
    vector<string> v(n);

    for (string& x : v)
        getline(cin, x);  

    //LS
    string temp;
    temp = BucketSort(v);
    
    if (!temp.empty())
    {
        string res = "";
        int i = 0; 
        while (temp[i] != ' ')
        {
            res += temp[i];
            i++;
        }
        cout << res;
    }
    
    return 0;
}