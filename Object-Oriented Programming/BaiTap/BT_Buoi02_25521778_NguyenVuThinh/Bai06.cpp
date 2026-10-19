//MSSV: 25521778   
//Họ và tên sinh viên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: CNVN.2
#include <iostream>
#include <string>

using namespace std;

class cString
{
    private:
        string s;
    public:
        cString()
        {
            s = "";
        }
        cString(string s)
        {
            this->s = s;
        }
        string NoiChuoi(cString temp)
        {
            string kq;
            kq += s;
            kq += temp.s;
            return kq;
        }
        void DaoChuoi()
        {
            int l = 0; 
            int r = s.size()-1;
            while (l <= r)
            {
                swap(s[l++], s[r--]);
            }
        }
        void InHoaToanBoChuoi()
        {
            for (int i = 0; i < s.size(); i++)
            {
                s[i] = toupper(s[i]);
            }
        }
        void InThuongToanBoChuoi()
        {
            for (int i = 0; i < s.size(); i++)
            {
                s[i] = tolower(s[i]);
            }
        }
        void Nhap()
        {
            getline(cin, s);
        }
        void Xuat()
        {
            cout << s << endl;
        }
        int GetChieuDaiChuoi()
        {
            return s.size();
        }
        string GetS()
        {
            return s;
        }
};

int main()
{
    cString a, b; //Chuỗi a dùng cho các hàm in hoa/thường và chiều dài, chuỗi b dùng cho hàm đảo ngược chuỗi và nối chuỗi a với chuỗi b
    cout << "Hãy nhập chuỗi a: " << endl;
    a.Nhap();
    cout << "Hãy nhập chuỗi b: " << endl;
    b.Nhap();

    cout << "Chuỗi a là: " << endl;
    a.Xuat();
    cout << "Chiều dài chuỗi a là: " << endl;
    cout << a.GetChieuDaiChuoi() << endl;

    cout << "Chuỗi a sau khi được in hoa toàn bộ chuỗi: " << endl;
    a.InHoaToanBoChuoi();
    a.Xuat();

    cout << "Chuỗi a sau khi được in thường toàn bộ chuỗi: " << endl;
    a.InThuongToanBoChuoi();
    a.Xuat();

    cString c;
    c = a.NoiChuoi(b);
    cout << "Sau khi nối chuỗi a và b ta thu được chuỗi: " << endl;
    cout << c.GetS() << endl;

    cout << "Chuỗi b sau khi đảo ngược: " << endl;
    b.DaoChuoi();
    b.Xuat();

    return 0;
}