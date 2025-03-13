#include <iostream>
#include "Fraction.h"


using namespace std;

int main()
{
    cout << endl << "Hồ Văn Phát || 064206001095" << endl << endl;
    Fraction f1, f2;

    cout << "Nhap phan so 1: ";
    cin >> f1;
    cout << "Nhap phan so 2: ";
    cin >> f2;

    cout << f1 << " + " << f2 << " = " << f1 + f2;
    return 0;
}