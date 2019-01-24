// This demo program illustrates that struct and class are essentially identical with 
// one major distinction, the default member access. The struct is default to public 
// and class is default to private.

#include <iostream>
using namespace std;

struct Tripple {
private:
    int x=1, y=2, z;
public:
    void setZ(int i) {z = i;};
    void show() { // C++11 stuct is the same as class except access previlege
        cout << "t.show(): [" << x << ", " << y << ", " << z << "]\n";
    };
    void increase() { //;
        x++; y++; z++;
    };
};

// void Tripple::increase() {
//     x++; y++; z++;
// }

int main() {
    Tripple t;
    t.setZ( 3 );
         
    t.show();
    t.increase();
    cout << "t.increase();\n";
    t.show();
}