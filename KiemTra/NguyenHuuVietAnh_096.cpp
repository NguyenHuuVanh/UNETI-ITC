#include <iostream>
#include <string>
using namespace std;

class ANPHAM
{
private:
    int ngayxb;
    long donggia;

public:
    string tenxb;
    string ma;
    ANPHAM()
    {
        this->ma = this->tenxb = "";
        this->donggia = 0;
        this->ngayxb = 0;
    }
    ~ANPHAM()
    {
        this->ma = this->tenxb = "";
        this->donggia = 0;
        this->ngayxb = 0;
    }
    void nhap()
    {
        fflush(stdin);
        cout << "Nhap ma san pham:";
        getline(cin, this->ma);
        fflush(stdin);
        cout << "Nhap ten nha xuat ban:";
        getline(cin, this->tenxb);
        fflush(stdin);
        cout << "Nhap ngay xuat ban:";
        cin >> this->ngayxb;
        cout << "Nhap don gia:";
        cin >> this->donggia;
    }
    void xuat()
    {
        cout << "Ma san pham:" << this->ma << endl;
        cout << "Nha xuat ban:" << this->tenxb << endl;
        cout << "Ngay xuat ban:" << this->ngayxb << endl;
        cout << "Don gia:" << this->donggia << endl;
    }

    long get()
    {
        return this->donggia;
    }
};

class SACH : public ANPHAM
{
private:
    string ten;
    int sl;

public:
    string tacgia;
    SACH()
    {
        this->ten = this->tacgia = "";
        this->sl = 0;
    }
    ~SACH()
    {
        this->ten = this->tacgia = "";
        this->sl = 0;
    }

    friend istream &operator>>(istream &is, SACH &a)
    {
        a.ANPHAM::nhap();
        fflush(stdin);
        cout << "Nhap ten sach:";
        getline(cin, a.ten);
        cout << "Nhap ten tac gia:";
        getline(cin, a.tacgia);
        cout << "Nhap so luong:";
        cin >> a.sl;
        return is;
    }

    friend ostream &operator<<(ostream &os, SACH a)
    {
        a.ANPHAM::xuat();
        cout << "Ten sach:" << a.ten << endl;
        cout << "Ten tac gia:" << a.tacgia << endl;
        cout << "So luong:" << a.sl << endl;
        cout << "Thanh tien:" << a.Tien() << endl;
        return os;
    }

    long Tien()
    {

        return this->sl * this->get();
    }

    bool operator==(const SACH &a)
    {
        if (a.tacgia == this->tacgia)
        {
            return true;
        }
        return false;
    }

    bool operator<(SACH &a)
    {
        if (a.Tien() < this->Tien())
        {
            return true;
        }
        return false;
    }

    void sapxep(SACH a[], int n)
    {
        SACH tmp; // dùng Bubble sort
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[j].Tien() < a[i].Tien())
                {
                    tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
                }
            }
        }
    }
};

void nhapthongtin()
{
    int n, key;
    bool Danhap = false;
    do
    {
        cout << "Nhap so luong sach: ";
        cin >> n;
    } while (n <= 0);
    SACH a[n];
    while (true)
    {
        cout << "\n";
        cout << "**********************************************************************" << endl;
        cout << "**      CHUONG TRINH QUAN LY SACH                                  **" << endl;
        cout << "**           1.Nhap du lieu                                        **" << endl;
        cout << "**           2.In danh sach sach                                   **" << endl;
        cout << "**           3.In danh sach sach NXB kim dong co don gia nho nhat  **" << endl;
        cout << "**           4.Tim sach theo ma                                    **" << endl;
        cout << "**           5.So luong sach cua tac gia Nguyen Van A              **" << endl;
        cout << "**           6.Danh sach sach cua tac gia Le Minh tang dan         **" << endl;
        cout << "**           0.Thoat                                               **" << endl;
        cout << "**           Nhap lua chon cua ban:                                **" << endl;
        cout << "***************************************************************    **" << endl;
        cin >> key;

        switch (key)
        {
        case 1:
            cout << "Ban da chon nhap danh sach sach!";
            for (int i = 0; i < n; i++)
            {
                cout << "\n---------- Nhap thong tin sach thu " << i + 1 << "-----------" << endl;
                cin >> a[i];
            }
            cout << "Ban da nhap thanh cong danh sach sach!" << endl;
            Danhap = true;
            cout << "Nhap phim bat ki de tiep tuc!" << endl;
            system("pause");
            break;
        case 2:
            if (Danhap)
            {
                cout << "\nBan da chon xuat danh sach sach!";
                for (int i = 0; i < n; i++)
                {
                    cout << "\n---------- Thong tin sach thu " << i + 1 << "-----------" << endl;
                    cout << a[i];
                }
            }
            else
            {
                cout << "\nNhap danh sach sach truoc!";
            }
            cout << "\nNhap phim bat ki de tiep tuc!\n"
                 << endl;
            system("pause");
            break;
        case 3:
            if (Danhap)
            {
                for (int i = 0; i < n; i++)
                {
                    if (a[i].tenxb == "KIM DONG")
                    {
                        a[i].sapxep(a, n);
                        cout << a[i];
                    }
                }
            }
            else
            {
                cout << "\nNhap danh sach sach truoc!";
            }
            cout << "\nNhap phim bat ki de tiep tuc!\n"
                 << endl;
            system("pause");
            break;
        case 4:
            if (Danhap)
            {
                string masach;
                cout << "Nhap ma sach:";
                cin >> masach;
                for (int i = 0; i < n; i++)
                {
                    cout << "--------- Thong tin sach thu " << i + 1 << "-----------" << endl;
                    if (masach == a[i].ma)
                    {
                        cout << a[i];
                    }
                }
            }
            else
            {
                cout << "\nNhap danh sach sach truoc!";
            }
            cout << "\nNhap phim bat ki de tiep tuc!\n"
                 << endl;
            system("pause");
            break;
        case 5:
            if (Danhap)
            {
                int count = 0;
                cout << "\nBan da chon dem sach!";
                for (int i = 0; i < n; i++)
                {
                    if (a[i].tacgia == "Nguyen Van A")
                    {
                        count++;
                    }
                }
                cout << "So luong la " << count << endl;
            }
            else
            {
                cout << "\nNhap danh sach sach truoc!";
            }
            cout << "\nNhap phim bat ki de tiep tuc!\n"
                 << endl;
            system("pause");
            break;
        case 6:
            if (Danhap)
            {
                for (int i = 0; i < n; i++)
                {
                    if (a[i].tacgia == "Le Minh")
                    {
                        cout << "----------------------------------------" << endl;
                        a[i].sapxep(a, n);
                        cout << a[i];
                    }
                }
            }
            else
            {
                cout << "\nNhap danh sach sach truoc!";
            }
            cout << "\nNhap phim bat ki de tiep tuc!\n"
                 << endl;
            system("pause");
            break;
        case 0:
            cout << "\nBan da chon thoat chuong trinh!";
            system("pause");
            // return 0;

        default:
            cout << "\nKhong co chuc nang nay!";
            cout << "\nBam phim bat ky de tiep tuc!\n";
            system("pause");
        }
    }
}

int main()
{
    nhapthongtin();
}