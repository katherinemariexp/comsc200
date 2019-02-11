// Chapter 14, Programming Challenge 1: Numbers Class
#include <iostream>
#include <string>
using namespace std;

// Declaration of Numbers class
class Numbers {
	int deposit;
	int number;	 // To hold a number
public:
	// Static arrays to hold words
	static string lessThan20[20];
	static string tens[10];
	static string hundred;
	static string thousand;
	 
	// Constructor
	Numbers(int x){ number = x;}
	
	// getter
	int getNumber() { return number; }
	// Function to print the words for the number
	void print();
	
	void add(int deposit) {
		int sum = number + deposit;
		// Make sure the number is within range.
		if (deposit < 0) 
			cout << "\nYou are not eligible to withdraw yet!\n";
		else if( 10000 < deposit )
			cout << "\nSorry, this machine can only process upto ten thousands.\n";
		else if(20000 < sum) 
			cout << "\nSorry, account balance must be kept under 20000!\n";
		else number = sum;
	}
};

// Static member variables must be defined
// outside of the class 
string Numbers::lessThan20[20] = 
			 { "zero", "one", "two", "three", "four", "five",
				"six", "seven ", "eight", "nine", "ten", 
				"eleven", "twelve", "thirteen", "fourteen", 
				"fifteen", "sixteen", "seventeen", "eighteen",
				"nineteen", 
			 };

string Numbers::tens[10] = 
			{ "nothing", "ten", "twenty", "thirty", "forty",
			  "fifty", "sixty", "seventy", "eighty", "ninety"
			};


string Numbers::hundred = "hundred";
string Numbers::thousand = "thousand";

// *********************************************
// The print fucntion prints the English words *
// for the number										*
// *********************************************

void Numbers::print()
{
	// Remainder holds what remains to be printed.
	int remainder = number;
	
	if (number == 0)
		cout << " zero";

	// Take care of thousands, if any.
	int n_thousands = remainder / 1000;
	remainder %= 1000;

	if (0 < n_thousands )
		cout << " " << lessThan20[n_thousands]
			 << " " << thousand;
	if ( 1 < n_thousands ) cout << 's';

	// Take care of hundreds, if any.
	int n_hundreds = remainder / 100;
	remainder %= 100;

	if (n_hundreds > 0) 
		cout << " " << lessThan20[n_hundreds]
			 << " " << hundred;
	if ( 1 < n_hundreds ) cout << 's';

	// Take care numbers less than a 100.
	if ( 20 <= remainder ) {
		int n_tens = remainder / 10;
		remainder %= 10;

		if (n_tens > 0)
			cout << " " << tens[n_tens];
	}

	// Take care of anything less than 20
	if (remainder > 0) 
		cout << " " << lessThan20[remainder];
	
	cout << endl;
}

// Demo program
int main() {
	int number;
	cout << "This program translates whole dollar amounts\n"
		 << "in the range 0 through 20000 into an English\n"
		 << "description of the number.\n\n";
	Numbers balance(0);
	
	while(1) {
		cout << "How much to deposit: ";
		int amount;
		cin >> amount;
		
		Numbers deposit(amount);
		cout << "New deposit: $" << amount << "  ";
		deposit.print();

		balance.add(amount);
		cout << "Account balance: $" << balance.getNumber();
		balance.print();
		cout << "\n----------------------------\n";
	}
}