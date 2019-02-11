#include <iostream>
#include <vector>
#include <sstream>
#include "Frac.h"

using namespace std;

int main() {
    cout << "\ntest with some hard-wired data sets!\n";
 
    // string input for list, delimiter, ...  with overloaded istream extraction operator >>
    vector<string> input = {"1/2", "2/3", "3/2", "3/4", "4/3", "3/5"};
    
    // initialize and display the tester list
    vector<Frac> list;
    for (auto item:input )  list.push_back(item);
    for (auto item:list ) cout << "  " << item ;
    
    Frac sum("0/1");
    cout << "\nadding the list one by one \n\t  sum \n\t  " << sum << endl;
    for (auto item:list ) {
        sum = sum + item;
        cout << "  + " << item << " = " << sum << endl; }
    
    cout << "Why the following two lines are not the same?\n";
    Frac f1("5/6");
    cout << "  " << f1 << " " << f1-- << " "  << f1 << " "
         << f1++ << " " << f1-- << " " << f1++ << endl;
    cout << "  " << f1 ; 
    cout << " " << f1-- ; 
    cout << " " << f1 ;
    cout << " " << f1++; 
    cout << " " << f1--;
    cout << " " << f1++;
    
    cout << "\ndouble( " << f1 << " ) is " << double( f1 ) << endl;
    
    Frac f2("2/3");
    cout << f1 << " is " << ((f1 > f2) ? "":"not")
         << " greater than "<< f2;
}