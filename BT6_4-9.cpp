 #include<iostream>
using namespace std;
class SinhVien
{
    private:
        string hoten;
        int namsinh;
        float diem[5];
    public:
        void nhap()
        { 
            cin.ignore();
            cout<<"Nhap ho ten: "; getline(cin, hoten);
            cout<<"Nhap nam sinh: "; cin>>namsinh;
            cout<<"Nhap diem 5 mon: \n";
            for(int i=0; i<5; i++)
            {
                cout<<"diemmon["<<i+1<<"]="; cin>>diem[i];
            }
        }
        void xuat()
        {
            cout<<"Ho ten: "<<hoten<<endl;
            cout<<"Nam sinh: "<<namsinh<<endl;
            for(int i=0; i<5; i++)
            {
                cout<<"diem mon ["<<i+1<<"]="<<diem[i]<<endl;
            }
            cout<<"diemtb= "<<diemtb()<<endl;
        }

        float diemtb()
        { 
            float tong = 0;   
            for(int i=0; i<5; i++)
            {
                tong += diem[i];
            }
            return tong / 5;
        }		

        void thilai()
        {
            bool coThiLai = false;
            for(int i=0; i<5; i++)
            {
                if(diem[i]<5)
                {
                    if(!coThiLai)
                    {
                        cout<<"ten sinh vien: "<<hoten<<"\n";
                        cout<<"nam sinh: "<<namsinh<<"\n";
                        coThiLai = true;
                    }
                    cout<<" mon "<<i+1<<": "<<diem[i]<<" diem\n";
                }
            }
            if(coThiLai)
                cout<<" diem trung binh: "<<diemtb()<<"\n";
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
    cout<<"Xuat thong tin sinh vien: "<<endl;
    for(int i=0; i<n; i++)  
    {
        ds[i].xuat();
    }
    cout<<"danh sach sinh vien thi lai\n";
    for(int i=0; i<n; i++)
        ds[i].thilai();
    return 0;
}
