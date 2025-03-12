#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Fraction.h"


using namespace std;

int main()
{
    vector <Fraction> lstFrac;
    string filename;
    int n, max = 0, min = 0;
    cin >> filename;
    ifstream file;

    file.open(filename);
    file >> n;
    for (int i = 0; i < n; i++) {
        Fraction* ptr = new Fraction(0, 1);
        file >> *ptr;
        lstFrac.push_back(*ptr);
    }
    
    for (int i = 1; i < lstFrac.size(); i++) {
        if (lstFrac[i] < lstFrac[min]) min = i;
        if (lstFrac[i] > lstFrac[max]) max = i;
    }

    cout << lstFrac[min] << endl;
    cout << lstFrac[max] << endl;

    file.close();

    return 0;
}