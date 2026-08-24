#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class NhanVien
{
private:
    string hoten;
    string manv;
    string ngaysinh;
    string diachi;
public:
    NhanVien(string manv, string hoten, string ngaysinh, string diachi)   // Constructor co doi
    {
        this->manv = manv;
        this->hoten = hoten;
        this->ngaysinh = ngaysinh;
        this->diachi = diachi;
    }
    void xuat()
    {
        cout << setw(10) << left << manv;
        cout << setw(20) << left << hoten;
        cout << setw(15) << left << ngaysinh;
        cout << setw(25) << left << diachi << endl;
    }
};
void tieude()
{
    cout << setw(10) << left << "Ma NV";
    cout << setw(20) << left << "Ho ten";
    cout << setw(15) << left << "Ngay sinh";
    cout << setw(25) << left << "Dia chi" << endl;
}
int main()
{
    int n;
    cout << "Nhap so luong nhan vien: "; 
    cin >> n;
    fflush(stdin);
    NhanVien **dsnv = new NhanVien*[n];
    for (int i = 0; i < n; i++) 
    { 
        string manv, hoten, ngaysinh, diachi;
        cout << "\n NHAP THONG TIN NHAN VIEN THU " << (i + 1) << endl;
        cout << "Nhap ma nhan vien: "; getline(cin, manv);
        cout << "Nhap ho ten: "; getline(cin, hoten);
        cout << "Nhap ngay sinh: "; getline(cin, ngaysinh);
        cout << "Nhap dia chi: "; getline(cin, diachi);
        dsnv[i] = new NhanVien(manv, hoten, ngaysinh, diachi);
    }
    cout << "\n     DANH SACH NHAN VIEN" << endl;
    tieude();
    for (int i = 0; i < n; i++)
    {
        dsnv[i]->xuat();
    }
    for (int i = 0; i < n; i++)
    {
        delete dsnv[i];
    }
    delete[] dsnv;
    return 0;
}
