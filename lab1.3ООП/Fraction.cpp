#include "Fraction.h"
using namespace std;
Fraction::Fraction() : wholePart(0), fractionalPart(0) {}

Fraction::Fraction(long long whole,  int fractional) : wholePart(whole), fractionalPart(fractional) {}

long long Fraction::getWholePart() const {
    return wholePart;
}

void Fraction::setWholePart(long long whole) {
    wholePart = whole;
}

 int Fraction::getFractionalPart() const {
    return fractionalPart;
}

void Fraction::setFractionalPart( int fractional) {
    fractionalPart = fractional;
}

void Fraction::Init() {
    wholePart = 0;
    fractionalPart = 0;
}

void Fraction::Read() {
    cout << "Enter the whole part: ";
    cin >> wholePart;
    cout << "Enter the fractional part: ";
    cin >> fractionalPart;
}

void Fraction::Display() const {
    cout << wholePart << "." << fractionalPart;
}

string Fraction::toString() const {
    return to_string(wholePart) + "." + to_string(fractionalPart);
}

Fraction Fraction::add(const Fraction& other, int operationType) const {
    long long resultWhole = wholePart + other.wholePart;
    unsigned short int resultFractional;

    switch (operationType) {
    case 1:
        if (fractionalPart + other.fractionalPart >= 100 && fractionalPart < 100 && other.fractionalPart < 100) {
            resultWhole++;
            resultFractional = (fractionalPart + other.fractionalPart) - 100;
        }
        else {
            resultFractional = fractionalPart + other.fractionalPart;
        }
        break;

    case 2:
        if (fractionalPart + other.fractionalPart >= 1000 && fractionalPart >= 100 && other.fractionalPart < 100) {
            resultWhole++;
            resultFractional = (fractionalPart + other.fractionalPart) - 1000;
        }
        else {
            resultFractional = fractionalPart + other.fractionalPart;
        }
        break;

    case 3:
        if (fractionalPart + other.fractionalPart >= 1000 && fractionalPart < 100 && other.fractionalPart >= 100) {
            resultWhole++;
            resultFractional = (fractionalPart + other.fractionalPart) - 1000;
        }
        else {
            resultFractional = fractionalPart + other.fractionalPart;
        }
        break;

    default:
        break;
    }

    return Fraction(resultWhole, resultFractional);
}


Fraction Fraction::multiply(const Fraction& other) const {
    if (fractionalPart < 100 && other.fractionalPart < 100) {
        long double result1 = wholePart + (static_cast<long double>(fractionalPart) / 100);
        long double result2 = other.wholePart + (static_cast<long double>(other.fractionalPart) / 100);
        long double fractionResult = result1 * result2;
        long long intPart = (fractionResult);
        unsigned short int fracPart =((fractionResult - intPart) * 10000);
        return Fraction(intPart, fracPart);
    }
    else if (fractionalPart >= 100 && other.fractionalPart < 100) {
        long double result3 = wholePart + (static_cast<long double>(fractionalPart) / 1000);
        long double result4 = other.wholePart + (static_cast<long double>(other.fractionalPart) / 100);
        long double fractionResult2 = result3 * result4;
        long long intPart2 = (fractionResult2);
        unsigned short int fracPart2 = ((fractionResult2 - intPart2) * 100000);
        return Fraction(intPart2, fracPart2);
    }
    else {
        long double result5 = wholePart + (static_cast<long double>(fractionalPart) / 100);
        long double result6 = other.wholePart + (static_cast<long double>(other.fractionalPart) / 1000);
        long double fractionResult3 = result5 * result6;
        long long intPart3 = (fractionResult3);
        unsigned short int fracPart3 = ((fractionResult3 - intPart3) * 100000);
        return Fraction(intPart3, fracPart3);
    }
}
