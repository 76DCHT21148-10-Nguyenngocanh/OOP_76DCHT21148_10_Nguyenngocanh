#include<iostream>
#include<string>
#include<vector>
using namespace std;
class NhanVien 
{
private:
    string hoten;
    string manv;
    string ngaysinh;
    string diachi;
public:
void nhap() 
{
    cout<<"Nhap ma nhan vien: "; getline(cin, manv);
    cout<<"Nhap ho ten: "; getline(cin, hoten);
    cout<<"Nhap ngay sinh: "; getline(cin, ngaysinh);
    cout<<"Nhap dia chi: ";getline(cin, diachi);
}
void xuat() 
	{
    cout<<"Ma nhan vien: "<<manv<< endl;
    cout<<"Ho ten: "<<hoten<<endl;
    cout<<"Ngay sinh: "<<ngaysinh<<endl;
    cout<<"Dia chi: "<<diachi<<endl;
    }
};
int main()
{
	int i;
// CACH 1: MANG TINH 
    NhanVien dsnv1[10];
    for(i=0; i<10; i++)
	{
        cout<<"==NHAP THONG TIN CHO NHAN VIEN THU "<<(i + 1)<<endl;
        dsnv1[i].nhap();
        cout << endl;
    }
    for(i=0; i<10; i++)
	{
        cout<<"\n=== XUAT THONG TIN NHAN VIEN THU "<<(i + 1)<< endl;
        dsnv1[i].xuat();
    }
// CACH 2: DUNG MANG DONG (TOAN TU NEW)
NhanVien *dsnv2;         
dsnv2 = new NhanVien[10];
for(i=0; i<10; i++)
{
    cout<<"==NHAP THONG TIN CHO NHAN VIEN THU "<<(i + 1)<< endl;
    dsnv2[i].nhap();
    cout<<endl;
}
for(i=0; i<10; i++)
   {
    cout<<"\n==XUAT THONG TIN NHAN VIEN THU "<<(i + 1)<<endl;
    dsnv2[i].xuat();
    }
    delete[] dsnv2;
// CACH 3: DUNG VECTOR 
vector<NhanVien> ds;
for (i = 0; i < 10; i++)
{
    NhanVien nv; 
    cout<<"==NHAP THONG TIN CHO NHAN VIEN THU "<<(i + 1)<<endl;
    nv.nhap();
    ds.push_back(nv);
    cout<< endl;
}
for (i=0; i<(int)ds.size(); i++) 
{
    cout<<"\n==XUAT THONG TIN NHAN VIEN THU "<<(i + 1)<<endl;
    ds[i].xuat();
}
    return 0;
}
