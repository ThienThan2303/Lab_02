#include<iostream>
using namespace std;

//1. Khai báo lớp ngày tháng năm
class ngayThangNam
{
    private:
        int iNgay;
        int iThang;
        int iNam;
    public:
        void nhap();
        void xuat();
        void ngayTiepTheo(int n);
        bool kiemTraNgayHopLe();
        int soNgayTrongThang(int iThang, int nam);
};

//2. Định nghĩa hàm kiểm tra số ngày trong tháng
int ngayThangNam::soNgayTrongThang(int iThang, int iNam)
{
    int soNgayTrongThang[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if((iNam % 4 == 0 && iNam % 100 != 0) || iNam % 400 == 0)
        soNgayTrongThang[1] = 29;
    return soNgayTrongThang[iThang - 1];
}

//3. Định nghĩa hàm kiểm tra ngày tháng năm hợp lệ
bool ngayThangNam::kiemTraNgayHopLe()
{
    if(iNam < 1)
        return false;
    if(iThang < 1 || iThang > 12)
        return false;
    if(iNgay < 1 || iNgay > soNgayTrongThang(iThang, iNam))
        return false;
    return true;
}

//4. Định nghĩa hàm nhập
void ngayThangNam::nhap() 
{
    do {
        cout << "Nhap ngay: ";
        cin >> iNgay;
        if (cin.fail() || iNgay < 1 || iNgay > 31) {
            cout << "Du lieu khong hop le. Vui long nhap so nguyen!" << endl;
            cin.clear(); // Xóa trạng thái lỗi của cin
            cin.ignore(); // Bỏ qua dữ liệu không hợp lệ
            continue;
        }

        cout << "Nhap thang: ";
        cin >> iThang;
        if (cin.fail() || iThang < 1 || iThang > 12) {
            cout << "Du lieu khong hop le. Vui long nhap so nguyen!" << endl;
            cin.clear();
            cin.ignore();
            continue;
        }

        cout << "Nhap nam: ";
        cin >> iNam;
        if (cin.fail() || iNam < 1) {
            cout << "Du lieu khong hop le. Vui long nhap so nguyen!" << endl;
            cin.clear();
            cin.ignore();
            continue;
        }

        if (!kiemTraNgayHopLe()) {
            cout << "Ngay thang nam khong hop le. Nhap lai!" << endl;
        }
    } while (!kiemTraNgayHopLe());
}

//5. Định nghĩa hàm xuất
void ngayThangNam::xuat()
{
    cout << iNgay << "/" << iThang << "/" << iNam << endl;
}


//6. Định nghĩa hàm ngày tiếp theo
void ngayThangNam::ngayTiepTheo(int n)
{
    for(int i = 0; i < n; i++)
    {
        iNgay++;
        if(iNgay > soNgayTrongThang(iThang, iNam))
        {
            iNgay = 1;
            iThang++;
            if(iThang > 12)
            {
                iThang = 1;
                iNam++;
            }
        }
    }
}

//7. Hàm main
int main()
{
    ngayThangNam a; 
    a.nhap();
    a.xuat();
    int n;
    cout << "Nhap so ngay can cong them: ";
    cin >> n;
    cout << "Ngay sau khi cong them " << n << " ngay la: ";
    a.ngayTiepTheo(n);
    a.xuat();
    return 0;
}
