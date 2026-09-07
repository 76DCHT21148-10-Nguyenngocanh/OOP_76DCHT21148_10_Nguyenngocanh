#include <iostream>
using namespace std;
class PhanSo
{
private:
    int tu;
    int mau;
public:
    // Ham tao khong doi
    PhanSo()
    {
        tu = 0;
        mau = 1;
    }
    // Ham tao co doi
    PhanSo(int tu, int mau)
    {
        this->tu = tu;
        this->mau = mau;
    }
    // Ham huy
    ~PhanSo() {}
    void nhap();
    void xuat();
    void rutgon();
    void cong(PhanSo b);
    void tru(PhanSo b);
    void nhan(PhanSo b);
    void chia(PhanSo b);
};
// Ham nhap
void PhanSo::nhap()
{
    cout << "Nhap tu: ";
    cin >> tu;
    do
    {
        cout << "Nhap mau: ";
        cin >> mau;
    }
    while (mau == 0);
}
// Ham xuat
void PhanSo::xuat()
{
    cout << tu << "/" << mau << endl;
}
// Ham rut gon
void PhanSo::rutgon()
{
    int a = tu;
    int b = mau;

    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    if (a != 0)
    {
        tu = tu / a;
        mau = mau / a;
    }

    if (mau < 0)
    {
        tu = -tu;
        mau = -mau;
    }
}
// Ham cong
void PhanSo::cong(PhanSo b)
{
    PhanSo kq;

    kq.tu = tu * b.mau + mau * b.tu;
    kq.mau = mau * b.mau;
    kq.rutgon();
    kq.xuat();
}
// Ham tru
void PhanSo::tru(PhanSo b)
{
    PhanSo kq;
    kq.tu = tu * b.mau - mau * b.tu;
    kq.mau = mau * b.mau;
    kq.rutgon();
    kq.xuat();
}
// Ham nhan
void PhanSo::nhan(PhanSo b)
{
    PhanSo kq;
    kq.tu = tu * b.tu;
    kq.mau = mau * b.mau;
    kq.rutgon();
    kq.xuat();
}
// Ham chia
void PhanSo::chia(PhanSo b)
{
    if (b.tu == 0)
    {
        cout << "Khong the chia cho 0!" << endl;
        return;
    }
    PhanSo kq;
    kq.tu = tu * b.mau;
    kq.mau = mau * b.tu;
    kq.rutgon();
    kq.xuat();
}
int main()
{
    PhanSo a, b;
    cout << "Nhap phan so a:" << endl;
    a.nhap();
    cout << "Nhap phan so b:"<< endl;
    b.nhap();
    cout << "Phan so a: "<< endl;
    a.xuat();
    cout << "Phan so b: "<< endl;
    b.xuat();
    cout << "Tong hai phan so: "<< endl;
    a.cong(b);
    cout << "Hieu hai phan so: "<< endl;
    a.tru(b);
    cout << "Tich hai phan so: "<< endl;
    a.nhan(b);
    cout << "Thuong hai phan so: "<< endl;
    a.chia(b);
    return 0;
}
