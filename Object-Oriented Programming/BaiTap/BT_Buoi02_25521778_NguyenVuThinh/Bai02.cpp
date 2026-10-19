//MSSV: 25521778   
//Họ và tên sinh viên: Nguyễn Vũ Thịnh
//Ngày sinh: 14/10/2007
//Lớp: CNVN.2
#include<iostream> 

using namespace std;

class Point
{
    private:
        float fHoanhDo;
        float fTungDo;
    public: 
        Point()
        {
            fHoanhDo = 0;
            fTungDo = 0;
        }
        Point(int x, int y)
        {
            fHoanhDo = x;
            fTungDo = y;
        }
        void Nhap()
        {
            cin >> fHoanhDo >> fTungDo;
        }
        void Xuat()
        {
            cout << fHoanhDo << " " << fTungDo;
        }
        void SetHoanhDo(float fHoanhDo)
        {
            this->fHoanhDo = fHoanhDo;
        }
        void SetTungDo(float fTungDo)
        {
            this->fTungDo = fTungDo;
        }
        float GetHoanhDo()
        {
            return fHoanhDo;
        }
        float GetTungDo()
        {
            return fTungDo;
        }
        void ThayDoiHoanhDo()
        {
            cin >> fHoanhDo;
        }
        void ThayDoiTungDo()
        {
            cin >> fTungDo;
        }
        void TinhTienHoanhDo(float value)
        {
            fHoanhDo += value;
        }
        void TinhTienTungDo(float value)
        {
            fTungDo += value;
        }
};

int main()
{
    //Khai báo a và nhập giá trị ban đầu
    Point a;
    cout << "Hãy nhập hoành độ và tung độ cho a: " << endl;
    a.Nhap();
    cout << "Hoành độ và tung độ của a là: " << endl;
    a.Xuat();
    cout << endl;

    //Thay đổi giá trị của a
    cout << "Hãy nhập giá trị hoành độ và tung độ mới cho a: " << endl;
    float hoanhdo;
    cin >> hoanhdo;
    float tungdo;
    cin >> tungdo;
    a.SetHoanhDo(hoanhdo);
    a.SetTungDo(tungdo);

    cout << "Hoành độ của a sau khi thay đổi là: ";
    cout << a.GetHoanhDo() << endl;   
    cout << "Tung độ của a sau khi thay đổi là: ";
    cout << a.GetTungDo() << endl; 
    
    //Tịnh tiến a
    cout << "Hãy nhập giá trị muốn tịnh tiến cho a: " << endl;
    float tinhtienhoanhdo;
    cin >> tinhtienhoanhdo;
    float tinhtientungdo;
    cin >> tinhtientungdo;
    a.TinhTienHoanhDo(tinhtienhoanhdo);
    a.TinhTienTungDo(tinhtientungdo);
    
    cout << "Hoành độ của a sau khi tịnh tiến là: ";
    cout << a.GetHoanhDo() << endl;   
    cout << "Tung độ của a sau khi tịnh tiến là: ";
    cout << a.GetTungDo() << endl;

    return 0;
}