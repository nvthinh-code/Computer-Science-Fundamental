//MSSV: 25521778   
//Họ và tên sinh viên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: CNVN.2
#include <iostream>
using namespace std;

//Viết chương trình cho phép người dùng nhập họ tên, điểm toán, điểm văn của
//một học sinh.Tính điểm trung bình và xuất kết quả ra màn hình.

struct User {
    string name = "";
    float mathematics = 0;
    float literature = 0;
};

void UserInput(User& x) {
    getline(cin, x.name);
    do {
        cin >> x.mathematics;
        cin >> x.literature;
    } while (x.mathematics < 0 || x.literature < 0);
}

float DTB(User x) {
    return (x.mathematics + x.literature)/2;
}

int main(){
    User A;
    UserInput(A);
    cout << DTB(A);

    return 0;
}

