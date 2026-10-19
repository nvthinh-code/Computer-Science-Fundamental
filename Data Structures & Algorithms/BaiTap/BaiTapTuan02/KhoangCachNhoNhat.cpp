#include <iostream>
#include <vector>
#include <cfloat>
using namespace std;
//Input: Mảng Point arr có n phần tử, Point p 
//Output: Vị trí của điểm q có k/c tới p nhỏ nhất
class Point{
    private:
        int x;
        int y;
    public:
        Point(){
            x=0;
            y=0;
        }
        Point(int a, int b){
            x=a;
            y=b;
        }
        void nhap(){
            cin>>x>>y;
        }
        float TongKC(const Point& k) const{
            return 1.0*(k.x-x)*(k.x-x)+1.0*(k.y-y)*(k.y-y);
        }
};

int ViTriCuaqNhoNhat(const vector<Point>& arr, int n, const Point& p){
    double smallest = DBL_MAX;
    int index = -1;

    for (int i=0;i<n;i++){
        float distance = arr[i].TongKC(p);
        if (smallest>distance){
            smallest = distance;
            index = i;
        }
    }

    return index;
}

int main(){
    int n; cin>>n;
    vector<Point> arr(n);
    for (int i = 0; i < n; i++){
        arr[i].nhap();
    }
    Point p; p.nhap();
    
    cout << ViTriCuaqNhoNhat(arr,n,p);

    return 0;
}