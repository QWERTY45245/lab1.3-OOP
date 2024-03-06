#include <iostream>
#include "Fraction.h"
using namespace std;
int main() {
    int a, b, c, d;
    cout << "a="; cin >> a;
    cout << "b="; cin >> b;
    cout << "c="; cin >> c;
    cout << "d="; cin >> d;

    Fraction fraction1(a, b);
    Fraction fraction2(c, d);

    cout << "Fraction 1: "; fraction1.Display(); cout << endl;
    cout << "Fraction 2: "; fraction2.Display(); cout << endl;

    Fraction sum = fraction1.add(fraction2);
    cout << "Sum: "; sum.Display(); cout << endl;

    Fraction product = fraction1.multiply(fraction2);
    cout << "Product: "; product.Display(); cout << endl;

    return 0;
}