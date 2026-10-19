//MSSV: 25521778   
//Họ và tên sinh viên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: CNVN.2
#include <iostream>
#include <string>
using namespace std;

//Viết chương trình cho phép người dùng nhập vào danh sách học sinh(thông tin
//mỗi học sinh giống bài 5).Tìm và xuất thông tin học sinh có điểm trung bình cao nhất, thấp nhất ra màn hình.

struct User {
    string name = "";
    float mathematics = 0;
    float literature = 0;
    float DTB = 0;
};

void UserInput(User& x) {
    getline(cin, x.name);
    do {
        cin >> x.mathematics;
        cin >> x.literature;
    } while (x.mathematics < 0 || x.literature < 0);
    x.DTB = (x.mathematics + x.literature) / 2;
    cin.ignore();
}

int main(){
    int n; 
    do {
        cin >> n;
    } while (n <= 0);
    cin.ignore();
    User* arr = new User[n];

    for (int i = 0; i < n; i++) {
        UserInput(arr[i]);
    }

    float largest_DTB = arr[0].DTB;
    int locate = 0;
    for (int i = 0; i < n; i++) {
        if (largest_DTB < arr[i].DTB) {
            largest_DTB = arr[i].DTB;
            locate = i;
        }
    }
    cout << "Highest DTB student is: " << endl;
    cout << arr[locate].name << endl;
    cout << arr[locate].mathematics << endl;
    cout << arr[locate].literature << endl;
    cout << arr[locate].DTB << endl;

    delete[] arr;

    return 0;
}
