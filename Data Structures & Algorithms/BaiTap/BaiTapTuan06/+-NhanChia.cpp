#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string Cong(string s1, string s2)
{
    int i = s1.size() - 1, j = s2.size() - 1;

    string kq;
    kq.resize(max(s1.size(), s2.size()) + 1);
    int k = kq.size() - 1;

    int luusodu = 0;

    while (i >= 0 || j >= 0 || luusodu)
    {
        int so1 = (i >= 0) ? s1[i] - '0' : 0;
        int so2 = (j >= 0) ? s2[j] - '0' : 0;

        int tong = so1 + so2 + luusodu;

        kq[k--] = (tong % 10) + '0';
        luusodu = tong / 10;

        i--;
        j--;
    }

    return kq.substr(k + 1);
}

// Nếu s1 > s2 thì 1, s2 > s1 thì -1, s2 == s1 thì 0
int Compare(string s1, string s2)
{
    if (s1.size() == s2.size())
    {
        int size = s1.size();
        int m = 0;
        while (m < size)
        {
            if (s1[m] == s2[m])
                m++;
            else if (s1[m] > s2[m])
                return 1;
            else
                return -1;
        }
    }

    else if (s1.size() > s2.size())
        return 1;
    else
        return -1;

    return 0;
}

// Mặc định là s1 - s2
string Tru(string s1, string s2)
{
    int num = Compare(s1, s2);

    if (num == 0)
        return "0";

    int i = s1.size() - 1, j = s2.size() - 1;
    
    string kq;
    kq.resize(max(s1.size(), s2.size()) + 1);
    int k = kq.size() - 1;

    // s1 > s2
    if (num == 1)
        while (i >= 0 || j >= 0)
        {
            int so1 = (i >= 0) ? s1[i] - '0' : 0;
            int so2 = (j >= 0) ? s2[j] - '0' : 0;

            int hieu = so1 - so2;

            kq[k--] = hieu + '0';

            i--;
            j--;
        }

    // s2 > s1
    else
    {
        while (i >= 0 || j >= 0)
        {
            int so1 = (i >= 0) ? s1[i] - '0' : 0;
            int so2 = (j >= 0) ? s2[j] - '0' : 0;

            int hieu = abs(so1 - so2);

            kq[k--] = hieu + '0';

            i--;
            j--;
        }
        kq[k] = '-';
    }

    return kq;
}

string Nhan(string s1, string s2)
{
    string kq = "";

    return kq;
}

int main()
{
    string s1 = "";
    string s2 = "";

    cout << "Hãy nhập s1: " << endl;
    getline(cin, s1);
    cout << "Hãy nhập s2: " << endl;
    getline(cin, s2);

    // Tong
    string Tong = Cong(s1, s2);
    cout << "Kết quả s1 + s2 là: " << endl;
    cout << Tong << endl;

    // Hieu
    string Hieu = Tru(s1, s2);
    cout << "Kết quả s1 - s2 là: " << endl;
    cout << Hieu << endl;

    // Tich
    string Tich = Nhan(s1, s2);
    cout << "Kết quả s1 * s2 là: " << endl;
    cout << Tich << endl;

    return 0;
}