#include <iostream>
using namespace std;

class FeetInches {
	int feet;		// To hold a number of feet
	int inches;		 // To hold a number of inches
	void simplify();// header only Definition below
public:
	// argument constructor
	FeetInches(int f = 0, int i = 0) 
		{ feet = f; inches = i; simplify(); }
	// copy constructor - must 1. pass ref var.
	FeetInches (const FeetInches &fi) 
		{ feet = fi.feet; inches = fi.inches; simplify(); }
	// assignment operator
	FeetInches operator= (const FeetInches &right)
		{ feet = right.feet; inches = right.inches; simplify(); }
	// Mutator
	void setFeet(int f) { feet = f; }
	void setInches(int i) { inches = i; simplify(); }
	// Accessor 
	int getFeet() const { return feet; }
	int getInches() const { return inches; }
	// Overloaded operator functions
	FeetInches operator + (const FeetInches &);	// Overloaded +
	FeetInches operator - (const FeetInches &);	// Overloaded -
	FeetInches operator ++ ();					// Prefix ++
	FeetInches operator ++ (int);				// Postfix ++
	bool operator > (const FeetInches &);		// Overloaded >
	bool operator < (const FeetInches &);		// Overloaded <
	bool operator == (const FeetInches &);		// Overloaded ==
};

void FeetInches::simplify(){
	if (inches >= 12) {
		feet += (inches / 12);
		inches = inches % 12; }
	else if (inches < 0) {
		feet -= ((abs(inches) / 12) + 1);	// quotion for feets
		inches = 12 - (abs(inches) % 12); }	// remainder for inches
	if( feet < 0 && inches >0 ) { feet += 1; inches -= 12; }
}

//*********************************************************
// Overloaded binary + and - operator.		
//*********************************************************

FeetInches FeetInches::operator + (const FeetInches &right) {
	FeetInches temp;
	temp.inches = inches + right.inches;
	temp.feet = feet + right.feet;
	temp.simplify();
	return temp;
}

FeetInches FeetInches::operator - (const FeetInches &right) {
	FeetInches temp;
	temp.inches = inches - right.inches;
	temp.feet = feet - right.feet;
	temp.simplify();  
	return temp;
} 

//**********************************************************
// Overloaded binary pre and postfix ++ operator.		
//**********************************************************
FeetInches FeetInches::operator++() { // prefix increment
	++inches;
	simplify();
	return *this;
}

FeetInches FeetInches::operator++(int) { // postfix increment
	FeetInches temp(feet, inches);
	inches++;
	simplify();
	return temp;
}

//************************************************************
// Overloaded comparator operator.  
//************************************************************

bool FeetInches::operator > (const FeetInches &right) {
	bool status;
	if (feet > right.feet)
		status = true;
	else if (feet == right.feet && inches > right.inches)
		status = true;
	else
		status = false;
}


bool FeetInches::operator < (const FeetInches &right) {
	bool status;
	if (feet < right.feet)
		status = true;
	else if (feet == right.feet && inches < right.inches)
		status = true;
	else
		status = false;
}

bool FeetInches::operator == (const FeetInches &right) {
	bool status;
	if (feet == right.feet && inches == right.inches)
		status = true;
	else
		status = false;
}


int main() {
	int feet, inches;
	FeetInches first, second, third;

	cout << "Enter a distance in feet and inches: ";
	cin >> feet >> inches;

	// Store the distance in the first object.
	first.setFeet(feet);
	first.setInches(inches);
	
	// copy construct
	FeetInches copyCon(first);

	// Get another distance from the user.
	cout << "Enter another distance in feet and inches: ";
	cin >> feet >> inches;

	// Store the distance in second.
	second.setFeet(feet);
	second.setInches(inches);

	// Assign first + second to third.
	third = first + second;

	// Display the result.
	// Compare the two objects.
	if (first == second)
		cout << "first is equal to second.\n";
	if (first > second)
		cout << "first is greater than second.\n";
	if (first < second)
		cout << "first is less than second.\n";
		
	// Display the result.
	cout << "first + second = ";
	cout << third.getFeet() << " feet, ";
	cout << third.getInches() << " inches.\n";

	// Assign first - second to third.
	third = first - second;

	// Display the result.
	cout << "first - second = ";
	cout << third.getFeet() << " feet, ";
	cout << third.getInches() << " inches.\n";
	
	// Use the prefix ++ operator.
	cout << "Demonstrating prefix ++ operator.\n";
	for (int count = 0; count < 4; count++) {
		first = ++second;
		cout << "first: " << first.getFeet() << " feet, ";
		cout << first.getInches() << " inches. ";
		cout << "second: " << second.getFeet() << " feet, ";
		cout << second.getInches() << " inches.\n";
	}

	// Use the postfix ++ operator.
	cout << "\nDemonstrating postfix ++ operator.\n";
	for (int count = 0; count < 4; count++) {
		first = second++;
		cout << "first: " << first.getFeet() << " feet, ";
		cout << first.getInches() << " inches. ";
		cout << "second: " << second.getFeet() << " feet, ";
		cout << second.getInches() << " inches.\n";
	}
}