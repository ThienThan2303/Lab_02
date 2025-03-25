#include<iostream>
using namespace std;

//1. Khai báo lớp thời gian
class Time
{
    private:
        int iGio;
        int iPhut;
        int iGiay;
    public:
        void nhap();
        void xuat();
        Time tinhCongThemMotGiay();
};

//2. Định nghĩa hàm nhập
void Time::nhap()
{
    do
    {
        cout << "Nhap gio: ";
        cin >> iGio;
        if (cin.fail() || iGio < 0 || iGio > 23) {
            cout << "Du lieu khong hop le. Vui long nhap so nguyen trong khoang tu 0 den 23!" << endl;
            cin.clear(); 
            cin.ignore(); 
            continue;
        }
        break;
    } while (true);
    
    do
    {
        cout << "Nhap phut: ";
        cin >> iPhut;
        if (cin.fail() || iPhut < 0 || iPhut > 59) {
            cout << "Du lieu khong hop le. Vui long nhap so nguyen trong khoang tu 0 den 59!" << endl;
            cin.clear(); 
            cin.ignore(); 
            continue;
        }
        break;
    } while (true);
    do
    {
        cout << "Nhap giay: ";
        cin >> iGiay;
        if(cin.fail() || iGiay < 0 || iGiay > 59) {
            cout << "Du lieu khong hop le. Vui long nhap so nguyen!" << endl;
            cin.clear(); 
            cin.ignore(); 
            continue;
        }
        break;
    } while (true);
}
    
//3. Định nghĩa hàm xuất
void Time::xuat()
{
    cout << iGio << ":" << iPhut << ":" << iGiay << endl;
}

//4.Định nghĩa hàm tính thời gian sau khi cộng thêm 1 giây
Time Time::tinhCongThemMotGiay()
{
    Time kq;
    kq.iGio = iGio;
    kq.iPhut = iPhut;
    kq.iGiay = iGiay + 1;
    if (kq.iGiay == 60)
    {
        kq.iGiay = 0;
        kq.iPhut++;
        if (kq.iPhut == 60)
        {
            kq.iPhut = 0;
            kq.iGio++;
            if (kq.iGio == 24)
                kq.iGio = 0;
        }
    }
    return kq;
}

//5. Hàm main
int main()
{
    Time a, kq;
    a.nhap();
    cout << "Thoi gian vua nhap la: ";
    a.xuat();
    kq = a.tinhCongThemMotGiay();
    cout << "Thoi gian sau khi cong them 1 giay la: ";
    kq.xuat();
    return 0;
}

