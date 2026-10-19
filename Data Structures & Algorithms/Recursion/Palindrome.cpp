#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& s, int left, int right)
{
    if (left >= right)
        return true;

    if (s[right] != s[left])   
        return false;

    return isPalindrome(s, left + 1, right - 1);
}

int main()
{
    string s;
    cout << "Vui lòng nhập s: ";
    getline(cin, s);
    int left = 0, right = s.size() - 1;

    if (isPalindrome(s, left, right))
        cout << "Chuỗi này là chuỗi Palindrome";
    else 
        cout << "Chuỗi này không phải là chuỗi Palindrome";

    return 0;
}