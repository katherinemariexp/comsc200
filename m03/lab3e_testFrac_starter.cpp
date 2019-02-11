#include <iostream>

using namespace std;

class Frac;
ostream &operator<< (ostream &stm, Frac &rhs);

class Frac {
    long num;
    long den;
public:
    // Frac() { num=0; den=1; }
    Frac() : num(0), den(1) {}
    Frac(long n, long d) {num=n; den=d;}
    Frac(const Frac &obj) {*this = obj;}
    void operator=(const Frac &rhs) {
        num = rhs.num;  den = rhs.den;
    }   // Frac a = b;
    
    // math operators
    Frac operator+(const Frac &rhs) {
        Frac temp;
        temp.num = num*rhs.den + rhs.num*den;
        temp.den = den*rhs.den;
        // lower term by / gcd
        return temp;
    }
    // math operator -
    // increment pre and postfix operator ++
    // comparators <, ==, >
    
    // Object type conversion to int and double
    
    
    friend ostream &operator<< (ostream &stm, Frac &rhs) {
        stm << rhs.num << "/" << rhs.den;
    }
};

int main() {
    Frac x(3,4);
    Frac y(1,2);
    cout << "\nCreated Frac x(3,4) as " << x;
    cout << "\nCreated Frac y(1,2) as " << y;
    
    Frac z(x);
    cout << "\nCopy constructed z as x: " << z;
    
    Frac v = x + y;
    cout << "\nx + y is: " << v;
    // cout << "\nx + y is: " << (x+y);
    
    
    
    // Frac v = x + y;

    //...
    
    // 
}