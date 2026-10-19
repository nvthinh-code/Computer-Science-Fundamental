#include <iostream>
#include <stack>

using namespace std;

bool kiemTraChuoi(stack<char> &st, string &s)
{
    if (s.empty())
        return false;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{')
            st.push(c);
        else {
            if (st.empty()) 
                return false; // s[0] = '),],}'

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{'))
                return false;
        }
    }

    return st.empty();
}

int main()
{
    //Input
    string s;
    cout << "Hãy nhập chuỗi s toàn dấu ngoặc: " << endl;
    cin >> s;

    stack<char> st;
    //Handle
    bool res = kiemTraChuoi(st, s);
    //Output
    if (res)
        cout << "VALID";
    else    
        cout << "INVALID";

    return 0;
}