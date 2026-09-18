#include <iostream>
#include <string>
using namespace std;
class monhoc {
public:
    string tenmon;
    float cc, kt, dt;
    void nhap() {
        cout<<"Nhap ten mon: "; getline(cin, tenmon);
        cout<<"Nhap diem CC: "; cin>>cc;
        cout<<"Nhap diem KT: "; cin>>kt;
        cout<<"Nhap diem DT: "; cin>>dt;
        cin.ignore();
    }
    void xuat() {
        cout<<"Ten mon: "<<tenmon<<endl;
        cout<<"CC: " <<cc<<endl;
		cout<<" KT: "<<kt<<endl;
		cout<<" DT: "<<dt<<endl;
    }
};
class sinhvien : public monhoc {
public:
    string hoten, lop, msv;
    void nhap() {
        cout<<"Nhap ho ten: "; getline(cin, hoten);
        cout<<"Nhap lop: "; getline(cin, lop);
        cout<<"Nhap ma sv: "; getline(cin, msv);
        monhoc::nhap();
    }
    void xuat() {
        cout<<"Ho ten: "<<hoten<<endl; 
		cout<<"Lop: "<<lop<<endl;
		cout<<"MSV: "<<msv<< endl;
        monhoc::xuat();
    }
    float tinhDHP() {
        return cc * 0.1 + kt * 0.3 + dt * 0.6;
    }
};
int main() {
    sinhvien ds[50];
    int n;
    cout<<"Nhap so luong sinh vien: "; cin>>n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout<<"Sinh vien thu "<<i + 1<<endl;
        ds[i].nhap();
    }
    cout<<"----- Diem hoc phan -----"<<endl;
    for (int i = 0; i < n; i++) {
        ds[i].xuat();
        cout<<"Diem hoc phan: "<< ds[i].tinhDHP()<<endl<<endl;
    }
    cout << "----- Danh sach sinh vien bi cam thi -----"<<endl;
    int soluong = 0;
    for (int i = 0; i < n; i++) {
        if (ds[i].cc < 5 || ds[i].kt == 0) {    //neu chuyen can nho hon 5 hoac kt=0 = cam thi 
            ds[i].xuat();
            cout<<endl;
            soluong=soluong + 1;
        }
    }
    if (soluong == 0) {
        cout<<"Khong co sinh vien nao bi cam thi."<<endl;
    }
    return 0;
}
