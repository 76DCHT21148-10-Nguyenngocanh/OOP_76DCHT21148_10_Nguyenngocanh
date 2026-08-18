void nhap(Nhanvien &nv)
{
    cout<<"Nhap ma nhan vien: ";
    cin>>nv.manv;
    cout<<"Nhap ten nhan vien: ";
    cin.get(); getline(cin, nv.tennv);
    cout<<"Nhap luong co ban: ";
    cin>>nv.luongcoban;
    cout<<"Nhap he so: ";
    cin>>nv.heso;
}
void xuat(Nhanvien nv)
{
    cout<<"Ma nhan vien: "<<nv.manv<< "\n";
    cout<<"Ten nhan vien: "<<nv.tennv<<"\n";
    cout<<"Luong co ban: "<<nv.luongcoban<<"\n";
    cout<<"He so: "<<nv.heso<< "\n";
}
int main()
{
    Nhanvien nv[100];
    int n;
    cout<<"Nhap so luong nhan vien: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"\n  Nhan vien thu " << i+1 << "\n";
        nhap(nv[i]);
    }
    cout<<"\n === DANH SACH NHAN VIEN ===\n";
    for(int i=0; i<n; i++)
    {
        cout<<"\n  Nhan vien thu "<<i+1<< "\n";
        xuat(nv[i]);
    }
    return 0;
}
