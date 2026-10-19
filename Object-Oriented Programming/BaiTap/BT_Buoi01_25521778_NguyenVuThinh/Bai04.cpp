//MSSV: 25521778   
//Họ và tên sinh viên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: CNVN.2
#include <iostream>
using namespace std;

//Viết chương trình cho phép người dùng nhập vào một dãy gồm n phân số.Tìm
//và xuất ra màn hình phân số lớn nhất.Sắp xếp dãy phân số tăng dần / giảm dần.

struct fraction {
    int numerator, denominator;
};

void fractionInput(fraction &x) {
    cin >> x.numerator;
    do {
        cin >> x.denominator;
    } while (x.denominator == 0);
}

int main(){
    int n; cin >> n;
    fraction* arr = new fraction[n];

    for (int i = 0; i < n; i++) {
        fractionInput(arr[i]);
    }
    //The largest fraction 
    float largest = 0;
    int locate = 0;
    for (int i = 0; i < n; i++) {
        float value = (float)arr[i].numerator / arr[i].denominator;
        if (largest < value) {
            largest = value;
            locate = i;
        }
    }
    cout << "The largest fraction is: " << arr[locate].numerator << "/" << arr[locate].denominator << endl;
    //Sort: Low to high
    for (int i = 0; i < n-1; i++) {
        float value_i = (float)arr[i].numerator / arr[i].denominator;
        int smallest_index = i;
        float smallest = value_i;
        for (int j = i+1; j < n; j++) {
            float value_j = (float)arr[j].numerator / arr[j].denominator;
            if (smallest > value_j) {
                smallest = value_j;
                smallest_index = j;
            }
        }
        swap(arr[i], arr[smallest_index]);
    } 
    cout << "Sort: Low to high: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i].numerator << "/" << arr[i].denominator << " ";
    }
    cout << endl;
    //Sort: High to low
    for (int i = 0; i < n - 1; i++) {
        float value_i = (float)arr[i].numerator / arr[i].denominator;
        int largest_index = i;
        float largest = value_i;
        for (int j = i + 1; j < n; j++) {
            float value_j = (float)arr[j].numerator / arr[j].denominator;
            if (largest < value_j) {
                largest = value_j;
                largest_index = j;
            }
        }
        swap(arr[i], arr[largest_index]);
    }
    cout << "Sort: High to low: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i].numerator << "/" << arr[i].denominator << " ";
    }
    cout << endl;
    
    delete[] arr;

    return 0;
}
