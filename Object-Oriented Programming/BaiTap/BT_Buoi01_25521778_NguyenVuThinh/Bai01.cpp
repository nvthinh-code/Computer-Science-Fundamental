//MSSV: 25521778   
//Họ và tên sinh viên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: CNVN.2

#include <iostream>
#include <cmath>
using namespace std;
//Viết chương trình cho phép người dùng nhập vào một phân số, rút gọn phân số và xuất kết quả ra màn hình.

struct PhanSo {
    int Tu, Mau;
};

int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

void nhapPhanSo(PhanSo &x) {
    cin >> x.Tu >> x.Mau;
}

void RutGon(PhanSo &x) {
    int UocChung = GCD(x.Tu, x.Mau);
    x.Tu = x.Tu / UocChung;
    x.Mau = x.Mau / UocChung;
}

int main(){
    PhanSo x;
    nhapPhanSo(x);
    RutGon(x);
    if (x.Mau == 1) {
        cout << x.Tu;
    }
    else if (x.Mau < 0) {
        cout << -x.Tu << "/" << -x.Mau;
    }
    else {
        cout << x.Tu << "/" << x.Mau;
    }

    return 0;
}