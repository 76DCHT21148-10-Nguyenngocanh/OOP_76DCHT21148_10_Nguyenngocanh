#include <iostream>
#include <string> 
using namespace std;
struct Nhanvien
{
	string manv;
	string tennv;
	float luongcoban;
	float heso;
};
int main()
{
	Nhanvien nv[100]; 
	int n;
	cout << "Nhap so luong nhan vien: "; 
	cin >> n;
	cout<< "So luong nhan vien la:"<<n<<"\n";
	return 0;
}

