#include <iostream>
#include <iomanip>
#include <string>

class Fraction {
private:
    long long wholePart;
     int fractionalPart;

public:
    
    Fraction();
    Fraction(long long whole,  int fractional);

    long long getWholePart() const;
    void setWholePart(long long whole);
     int getFractionalPart() const;
    void setFractionalPart( int fractional);

    void Init();
    void Read();
    void Display() const;
    std::string toString() const;

    Fraction add(const Fraction& other, int operationType) const;

    Fraction multiply(const Fraction& other) const;
};