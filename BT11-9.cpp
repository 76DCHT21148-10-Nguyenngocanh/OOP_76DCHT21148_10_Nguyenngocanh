#include<iostream>
using namespace std;
class SoPhuc
{
private:
    float thuc, ao;
public:
    // Ham tao khong doi
    SoPhuc()
    {
        thuc = 0;
        ao = 0;
    }
    // Ham tao co doi
    SoPhuc(float thuc, float ao)
    {
        this->thuc = thuc;
        this->ao = ao;
    }
    // Ham huy
    ~SoPhuc(){}
    //nap chong nhap xuat la ham ban
    friend istream& operator>>(istream &is, SoPhuc &a);
    friend ostream& operator<<(ostream &os, SoPhuc a);
    SoPhuc operator+(SoPhuc a);
    SoPhuc operator-(SoPhuc a);
    SoPhuc operator*(SoPhuc a);
    SoPhuc operator/(SoPhuc a);
};
//ham nhap
istream& operator>>(istream &is, SoPhuc &a){
    cout<<"Nhap phan thuc: "; is>>a.thuc;
    cout<<"Nhap phan ao: "; is>>a.ao;
    return is;
}
//ham xuat
ostream& operator<<(ostream &os, SoPhuc a)
{
    os<<"So phuc: "<<a.thuc<<"+"<<a.ao<<"*i"<<endl;
    return os;
}
SoPhuc SoPhuc::operator+(SoPhuc a){
    SoPhuc kq;
    kq.thuc = this->thuc + a.thuc;
    kq.ao = this->ao + a.ao;
    return kq;
}
SoPhuc SoPhuc::operator-(SoPhuc a){
    SoPhuc kq;
    kq.thuc = thuc - a.thuc;
    kq.ao = ao - a.ao;
    return kq;
}
SoPhuc SoPhuc::operator*(SoPhuc a){
    SoPhuc kq;
    kq.thuc = thuc*a.thuc - ao*a.ao;
    kq.ao = thuc*a.ao + ao*a.thuc;
    return kq;
}
SoPhuc SoPhuc::operator/(SoPhuc a){
    SoPhuc kq;
    float mau = a.thuc*a.thuc + a.ao*a.ao;
    if(mau==0){
        cout<<"Khong the chia cho so phuc 0!"<<endl;
        kq.thuc=0; kq.ao=0;
        return kq;
    }
    kq.thuc = (thuc*a.thuc + ao*a.ao)/mau;
    kq.ao = (ao*a.thuc - thuc*a.ao)/mau;
    return kq;
}
int main()
{
    SoPhuc a,b;
    cin>>a;
    cin>>b;
    cout<<"So phuc a: "<<endl;
    cout<<a;
    cout<<"So phuc b: "<<endl;
    cout<<b;
    SoPhuc tong, hieu, tich, thuong;
    cout<<"Tong hai so phuc:"<<endl;
    tong = a+b;
    cout<<tong;
    cout<<"Hieu hai so phuc:"<<endl;
    hieu = a-b;
    cout<<hieu;
    cout<<"Tich hai so phuc:"<<endl;
    tich = a*b;
    cout<<tich;
    cout<<"Thuong hai so phuc:"<<endl;
    thuong = a/b;
    cout<<thuong;
    return 0;
}
