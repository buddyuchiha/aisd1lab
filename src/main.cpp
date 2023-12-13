#include <iostream>
#include <string>
#include "..\mymainset\mainset.h"
using namespace std;
using namespace mainset;

int main() {

    float farray1[] = { 1.12, 2.33, 1.45, 5.76, 2.33, 2.33, 9.875 };//7
    float farray2[] = { 1.34, 3.23, 1.45, 5.76, 8.34 };//5
    float farray3[] = { 1.12, 2.33, 1.45 };//3
    float farray4[] = { 1.12, 2.33, 1.45, 5.76, 8.34 };//5
    Set<float> set1(farray1, 7);
    Set<float> set2(farray2, 5);
    Set<float> uniqueelements = set1.FindUniqueElements(set2);
    uniqueelements.PrintSet();
    Set<float> set3(farray3, 3);
    Set<float> set4(farray4, 5);
    Set<float> allelements = set3.AllElementsInSet(set4);
    allelements.PrintSet();
    string sarray1[] = { "python", "aisd", "laptop", "python" };
    string sarray2[] = { "python", "aisd", "laptop", "python", "bebra", "laptop" };
    Set<string> set5(sarray1, 4);
    Set<string> set6(sarray2, 6);
    Set<string> qwe = set5.FindUniqueElements(set6);
    Set<string> asd = set5.AllElementsInSet(set6);
    qwe.PrintSet();
    asd.PrintSet();
    Set<string> zxc = set6.RepeatElementsInSet();
    zxc.PrintSet();
    if (set5.IsSubset(set6)) {
        cout << "+" << endl;
    }
    else {
        cout << "-" << endl;
    }
    if (set4.IsSuperset(set3)) {
        cout << "+" << endl;
    }
    else {
        cout << "-" << endl;
    }
}