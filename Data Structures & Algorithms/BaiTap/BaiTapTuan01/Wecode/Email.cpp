#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<int> detectSpam(vector<string> &blackList, vector<string> &email)
{
    vector<int> ans;
    for (int i = 0; i < email.size(); i++)
    {
        stringstream ss(email[i]);
        string word;
        while (ss >> word)
        {
            for (string &x : blackList)
            {
                if (word == x)
                    ans.push_back(i + 1);
            }
        }
    }

    return ans;
}

int main()
{
    // Input
    int M;
    cin >> M;
    cin.ignore();
    vector<string> blackList(M);
    for (string &x : blackList)
        getline(cin, x);

    int N;
    cin >> N;
    cin.ignore();
    vector<string> email(N);
    for (string &x : email)
        getline(cin, x);

    // Handle
    vector<int> res = detectSpam(blackList, email);

    //Output
    if (res.size() == 0)
        cout << "No spam found";
    else
    {
        for (int x : res)  
            cout << x << endl;
    }

    return 0;
}