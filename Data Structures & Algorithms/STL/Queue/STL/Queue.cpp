#include <iostream> 
#include <queue> 

//  Queue
// FIFO - First in First out
// queue<data_type> name
// first element: q.front()
// dequeue: q.pop() O(1)
// enqueue: q.push(value) O(1)

using namespace std;

void print(queue<int> q){
    queue<int> temp = q;
    while (!temp.empty()){
        cout << temp.front() << " ";
        temp.pop();
    }
}

int main(){
    queue<int> q;
    q.push(14);
    q.push(10);
    q.push(2007);
    print(q);

    return 0;
}