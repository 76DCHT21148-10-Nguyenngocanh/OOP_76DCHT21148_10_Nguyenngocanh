#include<iostream>
using namespace std;
class nguoi{
    protected:
        string hoten;
        int nsinh;
    public:
        // ham tao khong doi
        nguoi()
        { hoten=""; nsinh=0; }
        // ham tao co doi
        nguoi(string hoten, int nsinh)
        {
            this->hoten=hoten;
            this->nsinh=nsinh;
        }
        void nhap(){
            cout<<"Nhap hoten: ";getline(cin,hoten);
            cout<<"Nhap nsinh: ";cin>>nsinh;
            cin.ignore();
        }
        void xuat(){
            cout<<"Ho ten : "<<hoten<<endl;
            cout<<"Nam sinh: "<<nsinh<<endl;
        }
};
class SinhVien: public nguoi{
    private:
        string msv;
        float dtb;
    public:
        // goi lai ham tao khong doi cua nguoi
        SinhVien():nguoi(){
            msv="";
            dtb=0;
        }
        // goi lai ham tao co doi cua nguoi
        SinhVien(string hoten, int nsinh, string msv, float dtb): nguoi(hoten, nsinh){
            this->msv=msv;
            this->dtb=dtb;
        }
        void nhap(){
            nguoi::nhap(); //goi nhap cua lop nguoi, sinhvien duoc ke thua
            cout<<"Nhap msv: ";getline(cin,msv);
            cout<<"Nhap dtb: ";cin>>dtb;
            cin.ignore();
        }
        void xuat(){
            nguoi::xuat();
            cout<<"Ma sv : "<<msv<<endl;
            cout<<"Diem tb: "<<dtb<<endl;
        }
        // ham lay dtb de dung khi sap xep
        float getDtb() const{
            return dtb;
        }
};
int main()
{
    // Cau 2: chay thu ham tao co doi
    SinhVien anh("Nguyen Ngoc Anh",2007,"1111",7.5);
    cout<<"    Thong tin sinh vien vua tao    \n";
    anh.xuat();
    cout<<"\n";
  //  CAU 3 : Nhap n sinh vien, sap xep giam dan theo diem trung binh, in ra man hinh
    int n;
    cout<<"Nhap so luong sinh vien: ";
    cin>>n;
    cin.ignore();
    SinhVien ds[50]; 
    for(int i=0;i<n;i++){
        cout<<"\nNhap thong tin sinh vien thu "<<i+1<<":\n";
        ds[i].nhap();
    }
    // thuat toan sap xep noi bot sap xep diem giam dan
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(ds[j].getDtb() < ds[j+1].getDtb()){
                SinhVien a = ds[j];
                ds[j] = ds[j+1];
                ds[j+1] = a;
                }
        }
    }
    cout<<"\n       Danh sach sinh vien sau khi sap xep giam dan theo DTB     \n";
    for(int i=0;i<n;i++){
        cout<<"\nSinh vien thu "<<i+1<<":\n";
        ds[i].xuat();
    }
    return 0;
}
