#include <iostream>
#include <iomanip>

using namespace std;

class SavingAccount {
    static double anualInterestRate; // class variable
    double savingBalance; // instance variable
    
public:
    SavingAccount( double b ) { // 1-arg constructor
        savingBalance = ((b>=0) ? b: 0.0);
    }
    
    void addMonthlyInterest() {
        savingBalance += savingBalance *( anualInterestRate/12.0);
    }

    static void modifyInterestRate( double n ) {
        anualInterestRate = (0.0 <= n && n <= 1.0 ) ? n : anualInterestRate;
    }
    
    void printBalance() const {
        cout << fixed << '$' << setprecision(2) << savingBalance;
    }

};

double SavingAccount::anualInterestRate = 0.02;

int main() {
    cout << "The bank set interest to 2%\n";
    SavingAccount saver1(2000.0);
    SavingAccount saver2(3000.0);
    cout << "Initial balance:\nSaver 1: ";
    saver1.printBalance();
    cout << "\nSaver 2: ";
    saver2.printBalance();
    
    cout << "\n\nBalance after 1 month:\nSaver 1: ";
    saver1.addMonthlyInterest(); // end of month 2
    saver2.addMonthlyInterest();
    saver1.printBalance();
    cout << "\nSaver 2: ";
    saver2.printBalance();

    cout << "\n\nBalance after 2 month:\nSaver 1: ";
    saver1.addMonthlyInterest(); // end of month 2
    saver2.addMonthlyInterest();
    saver1.printBalance();
    cout << "\nSaver 2: ";
    saver2.printBalance();

    
    cout << "\nThe bank has just raised interest to 50%\n";
    SavingAccount::modifyInterestRate(0.5);
    
    cout << "\n\nBalance after 3 month:\nSaver 1: ";
    saver1.addMonthlyInterest(); // end of month 3
    saver2.addMonthlyInterest();
    saver1.printBalance();
    cout << "\nSaver 2: ";
    saver2.printBalance();
}
