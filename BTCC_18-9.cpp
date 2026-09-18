#include <iostream>
#include <string>
using namespace std;
class nguoi {
protected:
    string hoten;
    int ns;
public:
    void nhap() {
        cout << "Nhap hoten: ";
        getline(cin, hoten);
        cout<<"Nhap ns: ";
        cin>>ns;
        cin.ignore();
    }
    void xuat() {
        cout<<"Hoten: " <<hoten<<endl;
        cout << "ns: " <<ns<<endl;
    }
    string getHoten() {
        return hoten;
    }
};
class sinhvien : public nguoi {
private:
    string msv;
    float dtb;

public:
    void nhap() {
        nguoi::nhap();
        cout<<"Nhap msv: "; getline(cin, msv);
        cout<<"Nhap dtb: "; cin>>dtb;
        cin.ignore();
    }
    void xuat() {
        nguoi::xuat();
        cout<<"msv: "<<msv<<endl;
        cout<<"dtb: "<< dtb<<endl;
    }
    string getMsv() {
        return msv;
    }
};
int timKiem(sinhvien ds[], int n, string tk) {
    for (int i = 0; i < n; i++) {
        if (ds[i].getMsv() == tk || ds[i].getHoten() == tk)    // kiem tra sinh vien nay co ma trung voi tk khong
		{
            return i;             // neu trung thi bao cho main biet la sinh vien nay o vi tri i
        }
    }
}
int main() {
    sinhvien ds[50];
    int n;
    cout<<"Nhap so luong sinh vien: ";
    cin>>n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "\nSinh vien thu " << i + 1 << endl;
        ds[i].nhap();
    }
    string tk;
    cout<<"\nNhap ma sv hoac ho ten can tim: ";
    getline(cin, tk);
    int vitri = timKiem(ds, n, tk);     // goi ham timKiem, ket qua tra ve la vi tri tim thay (hoac -1 neu khong co)
    if (vitri == -1) {              // neu vitri = -1 la khong tim thay SV 
        cout<<"\nKhong tim thay sinh vien!"<<endl;
    } else {                                    // nguoc lai khac -1 thi tim thay va in thong tin day du cua sinh vien do
        cout<<"\nDa tim thay:"<<endl;    
        ds[vitri].xuat();
    }
    return 0;
}
