#include<iostream>
using namespace std;
class SinhVien
{
    // CAU 1: Khai bao lop sinh vien voi 4 mon hoc 
    private:
        string hoten;
        int namsinh;
        float diem[4];
    public:
        // CAU 2: Cac phuong thuc nhap, xuat, tinh diem TB 
        void nhap()
        { 
            cin.ignore();
            cout<<"Nhap ho ten: "; getline(cin, hoten);
            cout<<"Nhap nam sinh: "; cin>>namsinh;
            cout<<"Nhap diem 4 mon: \n";
            for(int i=0; i<4; i++)
            {
                cout<<"  diem mon["<<i+1<<"]="; cin>>diem[i];
            }
        }
        void xuat()
        {
            cout<<"Ho ten      : "<<hoten<<endl;
            cout<<"Nam sinh    : "<<namsinh<<endl;
            for(int i=0; i<4; i++)
            {
                cout<<"Diem mon "<<i+1<<"  : "<<diem[i]<<endl;
            }
            cout<<"Diem TB     : "<<diemtb()<<endl;
        }
        float diemtb()
        { 
            float tong = 0;   
            for(int i=0; i<4; i++)
            {
                tong += diem[i];
            }
            return tong / 4;
        }
        //CAU 3: Kiem tra dieu kien thi tot nghiep, va in ra 
        // Dieu kien: diem trung binh > 7 va khong co mon nao duoi 5
        void kiemTraTotNghiep()
        {
            int dat = 1;   // 1 = du dieu kien, 0 = khong du
            if(diemtb() <= 7)
                dat = 0;
            for(int i=0; i<4; i++)
            {
                if(diem[i] < 5)
                    dat = 0;
            }
            if(dat == 1)
                xuat();
        }
};
int main()
{
    int n;
    SinhVien ds[100];
    cout<<"Nhap n= "; cin>>n; 
    for(int i=0; i<n; i++)  
    {
        cout<<"Nhap thong tin sinh vien thu "<<i+1<<endl;
        ds[i].nhap();
    }
    cout<<"\nXuat thong tin sinh vien:\n";
    for(int i=0; i<n; i++)  
    {
        ds[i].xuat();
        cout<<endl;
    }
    cout<<"Danh sach sinh vien du dieu kien tot nghiep:\n";
    for(int i=0; i<n; i++)
        ds[i].kiemTraTotNghiep();
    return 0;
}
