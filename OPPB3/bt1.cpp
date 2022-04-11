#include <iostream>
#include <string>
using namespace std;

class Nguoi
{
private:
    string ht;
    int ns;

public:
    Nguoi()
    {
        this->ht = "";
        this->ns = 0;
    }
    ~Nguoi()
    {
        this->ht = "";
        this->ns = 0;
    };
    void nhap();
    void xuat();
};

void Nguoi::nhap()
{
    fflush(stdin);
    cout << "Nhap ten:";
    getline(cin, this->ht);
    cout << "Nhap nam sinh:";
    cin >> this->ns;
}

void Nguoi::xuat()
{
    cout << "Ten:" << this->ht << endl;
    cout << "Nam sinh:" << this->ns << endl;
}

class Thisinh : public Nguoi
{
private:
    long sbd;
    float toan, ly, hoa;

public:
    Thisinh()
    {
        this->sbd = 0;
        this->toan = this->ly = this->hoa = 0;
    }
    ~Thisinh()
    {
        this->sbd = 0;
        this->toan = this->ly = this->hoa = 0;
    };
    void nhap();
    void xuat();
    float tongdiem();
    long sobaodanh();

    bool operator<(Thisinh &a)
    {

        if (a.tongdiem() < this->tongdiem())
        {
            return true;
        }
        return false;
    }

    bool operator==(Thisinh &a)
    {
        if (a.sbd == this->sbd)
        {
            return true;
        }
        return false;
    }
};

void Thisinh::nhap()
{
    Nguoi::nhap();
    cout << "Nhap so bao danh:";
    cin >> this->sbd;
    cout << "Nhap diem toan:";
    cin >> this->toan;
    cout << "Nhap diem ly:";
    cin >> this->ly;
    cout << "Nhap diem hoa:";
    cin >> this->hoa;
}

void Thisinh::xuat()
{
    Nguoi::xuat();
    cout << "So bao danh:" << this->sbd << endl;
    cout << "Diem toan:" << this->toan << endl;
    cout << "Diem ly:" << this->ly << endl;
    cout << "Diem hoa:" << this->hoa << endl;
    cout << "Tong diem:" << this->tongdiem() << endl;
}

float Thisinh::tongdiem()
{
    return (this->toan + this->ly + this->hoa);
}

void sapxep(Thisinh a[], int n)
{
    Thisinh tmp;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j].tongdiem() < a[i].tongdiem())
            {
                tmp = a[j];
                a[j] = a[i];
                a[i] = tmp;
            }
        }
    }
}

long Thisinh::sobaodanh()
{
    return this->sbd;
}

void nhapthongtin()
{
    int n, sum = 0, k;
    long sbd;
    do
    {
        cout << "Nhap so luong thi sinh:";
        cin >> n;
    } while (n < 1);
    Thisinh a[n];
    cout << "--------------- Nhap thong tin thi sinh --------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin thi sinh thu " << i + 1 << endl;
        a[i].nhap();
    }
    cout << "--------------- Xuat thong tin thi sinh --------------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Xuat thong tin thi sinh thu " << i + 1 << endl;
        a[i].xuat();
    }
    cout << "--------------- sap xep thi sinh theo diem ba mom tang dan --------------" << endl;
    sapxep(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << "Xuat thong tin thi sinh thu " << i + 1 << endl;
        a[i].xuat();
    }
    cout << "--------------- Tim thi sinh theo so bao danh --------------" << endl;
    cout << "Nhap so thi sinh can tim:";
    cin >> k;
    while (k != 0)
    {

        cout << "Nhap so bao danh thi sinh can tim:";
        cin >> sbd;
        for (int i = 0; i < n; i++)
        {
            if (sbd == a[i].sobaodanh())
            {
                a[i].xuat();
            }
        }
        k--;
    }

    for (int i = 0; i < n; i++)
    {

        if (a[i].tongdiem() >= 15)
        {
            sum += 1;
        }
    }
    cout << "Phan tram thi sinh co tong diem moi mon >= 5 la " << 1.0 * sum / n * 100 << "%" << endl;
}

int main()
{
    nhapthongtin();
}
