#include<iostream>
using namespace std;

//1. Khai báo lớp phân số
class phanSo
{
    private:
        int iTu;
        int iMau;
    public:
        void nhap();
        void xuat();
        void rutGon();
        phanSo cong(phanSo& ps);
        phanSo tru(phanSo& ps);
        phanSo nhan(phanSo& ps);
        phanSo chia(phanSo& ps);
        void soSanh(phanSo ps);
};

//2. Định nghĩa hàm nhập
void phanSo::nhap()
{
    do {
        cout << "Nhap tu so: ";
        cin >> iTu;
        if (cin.fail()) {
            cout << "Du lieu khong hop le. Vui long nhap so nguyen!" << endl;
            cin.clear(); 
            cin.ignore(); 
            continue;
        }

        cout << "Nhap mau so: ";
        cin >> iMau;
        if (cin.fail() || iMau == 0) {
            cout << "Du lieu khong hop le. Vui long nhap so nguyen khac 0!" << endl;
            cin.clear();
            cin.ignore();
            continue;
        }
        break;
    } while (true);
}

//3. Định nghĩa hàm xuất
void phanSo::xuat()
{
    cout << iTu << "/" << iMau << endl;
}

//4. Định nghĩa hàm rút gọn
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
void phanSo::rutGon() {
    int gcdValue = gcd(abs(iTu), abs(iMau)); 
    iTu /= gcdValue;
    iMau /= gcdValue;
}

//5. Định nghĩa hàm cộng
phanSo phanSo::cong(phanSo &ps)
{
    phanSo kq;
    kq.iTu = iTu * ps.iMau +  iMau * ps.iTu;
    kq.iMau = iMau * ps.iMau;
    kq.rutGon();
    return kq;
}

//6. Định nghĩa hàm trừ
phanSo phanSo::tru(phanSo &ps)
{
    phanSo kq;
    kq.iTu =  iTu * ps.iMau -  iMau * ps.iTu;
    kq.iMau = iMau * ps.iMau;
    kq.rutGon();
    return kq;
}

//7. Định nghĩa hàm nhân
phanSo phanSo::nhan(phanSo &ps)
{
    phanSo kq;
    kq.iTu =  iTu * ps.iTu;
    kq.iMau = iMau * ps.iMau;
    kq.rutGon();
    return kq;
}

//8. Định nghĩa hàm chia
phanSo phanSo::chia(phanSo &ps)
{
    phanSo kq;
    kq.iTu = iTu * ps.iMau;
    kq.iMau =  iMau * ps.iTu;
    kq.rutGon();
    return kq;
}

//9. Định nghĩa hàm so sánh
void phanSo::soSanh(phanSo ps)
{
    if (iTu * ps.iMau > iMau * ps.iTu)
        cout << "Phan so thu nhat lon hon phan so thu hai";
    else if (iTu * ps.iMau < iMau * ps.iTu)
        cout << "Phan so thu nhat nho hon phan so thu hai";
    else
        cout << "Hai phan so bang nhau" << endl;
}

//10. Hàm main
int main()
{
    phanSo a, b, kq;
    cout << "Nhap phan so thu nhat: " << endl;
    a.nhap();
    cout << "Nhap phan so thu hai: " << endl;
    b.nhap();

    kq = a.cong(b);
    cout << "Tong hai phan so: ";
    kq.xuat();

    kq = a.tru(b);
    cout << "Hieu hai phan so: ";
    kq.xuat();

    kq = a.nhan(b);
    cout << "Tich hai phan so: ";
    kq.xuat();

    kq = a.chia(b);
    cout << "Thuong hai phan so: ";
    kq.xuat();

    a.soSanh(b);
    return 0;
}

