#include<iostream>
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
	this->tu =tu;
	if(mau!=0)
		this->mau =mau;
	else
		this->mau =1;
	}
// Ham huy
~PhanSo(){}
//nap chong nhap la ham ban 
friend istream& operator>>(istream &in,PhanSo &p); 
friend ostream& operator<<(ostream &on, PhanSo p);
int UCLN(int a,int b);
void rutgon();
PhanSo operator+(PhanSo b);
PhanSo operator-(PhanSo b);
PhanSo operator*(PhanSo b);
PhanSo operator/(PhanSo b);
};
//ham nhap 
istream& operator>>(istream &in,PhanSo &p){
	cout<<"Nhap tu: "; in>>p.tu;
	do{
		cout<<"Nhap mau: "; in>>p.mau; 
	} while (p.mau==0);
	return in;              
    } 
//sua ham xuat 
ostream& operator<<(ostream &on,PhanSo p){
	on<<p.tu<<"/"<<p.mau<<endl; 
	return on;              
}
//tim uoc chung lon nhat de rut gon
int PhanSo::UCLN(int a,int b){
	if(a<0) a=-a;
	if(b<0) b=-b;
	while(b!=0){
		int r=a%b;
		a=b;
		b=r;
	}
	return (a==0)?1:a;
}
//rut gon phan so 
void PhanSo::rutgon(){
	int u=UCLN(tu,mau);
	tu=tu/u;
	mau=mau/u;
	if(mau<0){         
		tu=-tu;
		mau=-mau;
	}
}
PhanSo PhanSo ::operator+(PhanSo b){
	PhanSo kq;
	kq.tu = tu *b.mau + mau *b.tu;
	kq.mau = mau*b.mau;
	kq.rutgon();
	return kq; 
} 
PhanSo PhanSo::operator-(PhanSo b){
	PhanSo kq;
	kq.tu = tu*b.mau - mau*b.tu;
	kq.mau = mau*b.mau;
	kq.rutgon();
	return kq;
}
PhanSo PhanSo::operator*(PhanSo b){
	PhanSo kq;
	kq.tu = tu*b.tu;
	kq.mau = mau*b.mau;
	kq.rutgon();
	return kq;
}
PhanSo PhanSo::operator/(PhanSo b){
	PhanSo kq;
	kq.tu = tu*b.mau;
	kq.mau = mau*b.tu;
	kq.rutgon();
	return kq;
}
int main()
{
	PhanSo a,b;
	cin>>a;
	cin>>b;
	cout<<"PS a: "<<endl;
	cout<<a; 
	cout<<"PS b: "<<endl;
	cout<<b; 
	PhanSo tong,hieu,tich,thuong;
	cout<<"tong hai phan so:"<<endl; 
	tong=a+b;
	cout<<tong; 
	cout<<"hieu hai phan so:"<<endl;
	hieu=a-b;
	cout<<hieu;
	cout<<"tich hai phan so:"<<endl;
	tich=a*b;
	cout<<tich;
	cout<<"thuong hai phan so:"<<endl;
	thuong=a/b;
	cout<<thuong;
	return 0;
 }
