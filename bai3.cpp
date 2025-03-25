#include<iostream>
using namespace std;

//1. Khai báo lớp Số Phức
class soPhuc
{
    private:
        float iThuc;
        float iAo;
    public:
        void nhap();
        void xuat();
        soPhuc cong(soPhuc& sp);
        soPhuc tru(soPhuc& sp);
        soPhuc nhan(soPhuc& sp);
        soPhuc chia(soPhuc& sp);
};

//2. Định nghĩa hàm nhập
void soPhuc::nhap()
{
    cout << "Nhap so phuc: " << endl;
    do
    {
        cout << "Nhap phan thuc: ";
        cin >> iThuc;
        if (cin.fail()) {
            cout << "Du lieu khong hop le. Vui long nhap so thuc!" << endl;
            cin.clear(); 
            cin.ignore(); 
            continue;
        }
        break;
    } while (true);
    do
    {
        cout << "Nhap phan ao: ";
        cin >> iAo;
        if (cin.fail()) {
            cout << "Du lieu khong hop le. Vui long nhap so thuc!" << endl;
            cin.clear(); 
            cin.ignore(); 
            continue;
        }
        break;
    } while (true);
}

//3. Định nghĩa hàm xuất
void soPhuc::xuat()
{
    cout << iThuc << " + " << iAo << "i" << endl;
}

//4. Định nghĩa hàm cộng
soPhuc soPhuc::cong(soPhuc& sp)
{
    soPhuc kq;
    kq.iThuc = iThuc + sp.iThuc;
    kq.iAo = iAo + sp.iAo;
    return kq;
}

//5. Định nghĩa hàm trừ
soPhuc soPhuc::tru(soPhuc& sp)
{
    soPhuc kq;
    kq.iThuc = iThuc - sp.iThuc;
    kq.iAo = iAo - sp.iAo;
    return kq;
}

//6. Định nghĩa hàm nhân
soPhuc soPhuc::nhan(soPhuc& sp)
{
    soPhuc kq;
    kq.iThuc = iThuc * sp.iThuc - iAo * sp.iAo;
    kq.iAo = iThuc * sp.iAo + iAo * sp.iThuc;
    return kq;
}

//7. Định nghĩa hàm chia
soPhuc soPhuc::chia(soPhuc& sp)
{
    soPhuc kq;
    kq.iThuc = (iThuc * sp.iThuc + iAo * sp.iAo) / (sp.iThuc * sp.iThuc + sp.iAo * sp.iAo);
    kq.iAo = (iAo * sp.iThuc - iThuc * sp.iAo) / (sp.iThuc * sp.iThuc + sp.iAo * sp.iAo);
    return kq;
}

//8. Hàm main
int main()
{
    soPhuc a, b,  kq;
    cout << "Nhap so phuc a: " << endl;
    a.nhap();
    cout << "Nhap so phuc b: " << endl;
    b.nhap();
    cout << "So phuc a: ";
    a.xuat();
    cout << "So phuc b: ";
    b.xuat();
    
    kq = a.cong(b);
    cout << "Tong hai so phuc: ";
    kq.xuat();

    kq = a.tru(b);
    cout << "Hieu hai so phuc: ";
    kq.xuat();

    kq = a.nhan(b);
    cout << "Tich hai so phuc: ";
    kq.xuat();

    kq = a.chia(b);
    cout << "Thuong hai so phuc: ";
    kq.xuat();
    return 0;
}