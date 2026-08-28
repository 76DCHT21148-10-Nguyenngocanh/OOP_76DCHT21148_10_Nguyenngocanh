#include<iostream>
#include<iomanip>
using namespace std;
int MAX=100;   // hang so gioi han kich thuoc mang
// cau 1: khai bao lop ma tran voi cac thuoc tinh
class MaTran // khai bao lop
{
    private: // quyen truy xuat
        int m, n; // m: so hang, n: so cot
        int phantu[100][100];
    public:
// cau 2 xay dung cac phuong thuc nhap xuat
    void nhap()  // ham thanh vien 
    {
        cout<<"Nhap so hang: "; cin>>m;
        cout<<"Nhap so cot: "; cin>>n;
        for(int i=0;i<m;i++)  // bien i kieu int ton tai trong vong for nay
        {
            for(int j=0;j<n;j++)    // bien j kieu int ton tai trong vong for nay
            {
                cout<<"Nhap phan tu hang "<<i+1<<",cot "<< j+1<< ": "; cin>>phantu[i][j];
            }
        }
    }
    void xuat()   // ham thanh vien, kieu tra ve void
    {
        for(int i=0;i<m;i++) 
        {
            for(int j=0;j<n;j++) 
            {
                cout<<setw(5)<<phantu[i][j];
            }
            cout << endl;
        }
    }
    // khai bao ham ban 
    friend MaTran cong(MaTran a, MaTran b); 
};
// cau 3: nhap vao 2 ma tran dong cap vaf thuc hien cong
MaTran cong(MaTran a, MaTran b)      // ham ban cong()  ben ngoai class va kieu tra va Matran
{
    MaTran c;   // tao doi tuong ma tran moi
    c.m=a.m;       // truy cap truc tiep private cua a nho friend
    c.n = a.n;
    for(int i=0; i<c.m; i++)
        for(int j = 0;j<c.n; j++)
            c.phantu[i][j]=a.phantu[i][j] + b.phantu[i][j];   // cong tung phan tu
    return c;            // tra doi tuong c cho noi goi ham
}
int main()
{
    MaTran a, b, c;      // khai bao 3 doi tuong ma tran
    cout<<"Ma tran thu nhat:"<<endl;
    a.nhap();              // goi ham tv cho doi tuong a
    cout<<"Ma tran thu hai:"<<endl;
    b.nhap();
    c = cong(a,b);         // goi ham ban 
    cout<<"In ma tran thu nhat:"<<endl;
    a.xuat();
    cout<<"In ma tran thu hai:"<<endl;
    b.xuat();
    cout<<"Ma tran tong:"<<endl;
    c.xuat();
    return 0;
}
