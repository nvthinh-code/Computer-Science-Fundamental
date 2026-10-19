#include <iostream>
#include <stack>

//LIFO - Last in First out 
//stack<data_type> name;
//stack.push(), stack.pop(), stack.top(), stack.empty(), stack.size()
using namespace std;

int main(){
    stack<int> st;
    st.push(14);
    st.push(10);
    st.push(2007);
    while (!st.empty()){
        cout << st.top();
        st.pop();
    }

    return 0;
}