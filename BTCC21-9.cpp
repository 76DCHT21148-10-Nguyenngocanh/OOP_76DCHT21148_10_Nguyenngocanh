#include<iostream>
#include <cmath>
using namespace std;
class PS1{
    protected:
        int ts;
        int ms;
    public:
        void nhap(){
            cout<<"Nhap ts: ";cin>>ts;
            do{
                cout<<"Nhap ms: ";cin>>ms;
            }while (ms==0);
        }
        void in(){ 
            toigian();
            if (ms<0) {
                ts=-ts;
                ms=-ms;
            }
            cout<<ts<<"/"<<ms;
        }
        void toigian(){
            int a=abs(ts), b=abs(ms);
            while (b!=0) 
            {
                int r=a%b;
                a=b;
                b=r;
            }
            int uc=a;//ucln=a+b; vi b=0 nen uocln=a
            ts=ts/uc;
            ms=ms/uc;
        }
};
class PS2:public PS1{
    public:
        void operator=(PS2 b){
            ts=b.ts;
            ms=b.ms;
        }
        int operator>(PS2 b){
            return (ts*b.ms > b.ts*ms);
        }
};
int main()
{
    PS2 a[10];
    int n;
    do
    {
        cout << "Nhap so luong phan so: ";
        cin >> n;
    } while (n< 1 || n > 10);
    cout << "\n Nhap danh sach\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\n Phan so thu " << i + 1 << ":\n";
        a[i].nhap();
        a[i].toigian();
    }
    cout << "\n Danh sach vua nhap \n";
    for (int i = 0; i < n; i++)
    {
        a[i].in();
        cout << "   ";
    }
    for (int i = 0; i < n- 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[i])
            {
                PS2 tg;
                tg = a[i];
                a[i] = a[j];
                a[j] = tg;
            }
        }
    }
    cout << "\n Danh sach sau khi sap xep giam dan:\n";
    for (int i = 0; i < n; i++)
    {
        a[i].in();
        cout << "   ";
    }
    return 0;
}

