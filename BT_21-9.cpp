#include <iostream>
#include <cmath>
using namespace std;
class SP1 {
protected:
    double thuc; 
    double ao;   
public:
    void nhap() {
        cout << "Nhap phan thuc: ";
        cin >> thuc;
        cout << "Nhap phan ao: ";
        cin >> ao;
    }
    void in() {
        if (ao >= 0)
            cout << thuc << "+" << ao << "i";            // Neu phan ao >= 0 thi in dung "a+b i"
        else                                           // Neu phan ao < 0 thi in dung "a-b i"
            cout << thuc << ao << "i"; // neu ao am thi tu hien dau tru
    }
    // Tinh module: |z| = sqrt(thuc^2 + ao^2)
    float mod() {
        return sqrt(thuc * thuc + ao * ao);    
    }
};
class SP2 : public SP1 {
public:
    void operator=(SP2 b) {
        thuc = b.thuc;
        ao = b.ao;
    }
    bool operator>(SP2 b) {   
        return mod() > b.mod();
    }
};
int main() {
    SP2 a[10]; 
    int n;
    do {
        cout << "Nhap so luong so phuc: ";
        cin >> n;
    } while (n < 1 || n > 10);
    cout << "\nNhap danh sach:\n";
    for (int i = 0; i < n; i++) {
        cout << "So phuc thu " << i + 1 << ":\n";
        a[i].nhap();
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Neu module[j] > module[i] thi doi cho
            if (a[j] > a[i]) {
                SP2 m;         // m bien tam da hoan doi
                m = a[i];
                a[i] = a[j];
                a[j] = m;
            }
        }
    }
    cout << "\nDanh sach sau khi sap xep giam dan:\n";
    for (int i = 0; i < n; i++) {
        a[i].in(); 
        cout << "  | z | = " << a[i].mod() << endl; // in module
    }
    return 0;
}

