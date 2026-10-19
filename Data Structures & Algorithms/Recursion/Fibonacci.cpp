#include <iostream>
#include <string> 

using namespace std;

int Fibonacci(int n)
{
    if (n <= 2)
        return 1;
    
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
    cout << "Vui lòng nhập giá trị n: ";
    int n;
    cin >> n;
    cout << "Số Fibonacci thứ " << n << " là:\n";
    cout << Fibonacci(n);

    return 0;
}

