#include <iostream>
using namespace std;

class Sanpham
{
private:
    string masp, tensp;
    int nam;

public:
    Sanpham()
    {
        this->masp = this->tensp = "";
        this->nam = 0;
    }
    ~Sanpham()
    {
        this->masp = this->tensp = "";
        this->nam = 0;
    }
    void nhap()
    {
        cout << "Nhap ma san pham:";
        cin >> this->masp;
        fflush(stdin);
        cout << "nhap ten san pham:";
        getline(cin, this->tensp);
        cout << "Nhap nam san xuat:";
        cin >> this->nam;
    }
    void xuat()
    {
        cout << "Ma san pham " << this->masp << endl;
        cout << "Ten san pham " << this->tensp << endl;
        cout << "Nam san xuat " << this->nam << endl;
    }
};

class Tivi : public Sanpham
{
private:
    float dai, rong;

public:
    Tivi()
    {
        this->dai = this->rong = 0;
    }
    ~Tivi()
    {
        this->dai = this->rong = 0;
    }
    void nhap()
    {
        Sanpham::nhap();
        cout << "Nhap chieu dai:";
        cin >> this->dai;
        cout << "Nhap chieu rong:";
        cin >> this->rong;
    }
    void xuat()
    {
        Sanpham::xuat();
        cout << "Chieu dai " << this->dai << endl;
        cout << "Chieu rong " << this->rong << endl;
        cout << "Dien tich man hinh:" << this->dientich() << endl;
    }
    float dientich()
    {
        return (this->dai * this->rong);
    }
    bool operator<(Tivi &a)
    {
        if (a.dientich() < this->dientich())
        {
            return true;
        }
        return false;
    }
};

void sapxep(Tivi a[], int n)
{
    Tivi tmp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j].dientich() < a[i].dientich())
            {
                tmp = a[j];
                a[j] = a[i];
                a[i] = tmp;
            }
        }
    }
}

void thongtin()
{
    int n;
    do
    {
        cout << "Nhap so luong ti vi:";
        cin >> n;
    } while (n < 1);
    Tivi a[n];
    cout << "------------ Nhap thong tin -------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin ti vi thu " << i + 1 << endl;
        a[i].nhap();
    }
    cout << "------------ Xuat thong tin -------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << " Thong tin ti vi thu " << i + 1 << endl;
        a[i].xuat();
    }
    sapxep(a, n);
    cout << "------------ Xuat thong tin sau sap xep  -------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << " Thong tin ti vi thu " << i + 1 << endl;
        a[i].xuat();
    }
}

int main()
{
    thongtin();
}