#include <iostream>
#include <queue> 

//  Priority Queue
// priority_value<int> pq
// pq.push(value) đẩy value vào pq O(logn)
// Top là phần tử có độ ưu tiên cao nhất -> pq.top() - xem phần tử có độ ưu tiên cao nhất 
// pq.pop() lấy phần tử có độ ưu tiên cao nhất O(logn)

using namespace std;

void print(priority_queue<int> pq){
    priority_queue<int> temp = pq;
    while (!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
}

int main(){
    priority_queue<int> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);
    print(pq);
    
    return 0;
}