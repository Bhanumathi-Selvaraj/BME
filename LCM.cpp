/*
	Purpose: This program finds the least common multiple of two to four integer
values with their combinations using prime factorization and GCD methods. Input will be taken from the user and the output will be will be printed on the console. 
*/

#include <iostream>
#include <cmath>

using namespace std;

void LCM(int, int, int&, int&);
void LCM(int, int, int, int&, int&);
void LCM(int, int, int, int, int&, int&);
void Primes(int, int, int&);
void display(int, int, int, int);
void display(int, int, int, int, int);
void display(int, int, int, int, int, int);
int GCD(int, int);

int main() {
	int Nums[4];
	int counter = 0, prime, gcd;

	cout << "Least Common Multiple.\n"		// Header
		<< "-----------------------\n"
		<< "Enter two or more integer numbers (Up to 4) and find the LCM of the numbers. Enter -1 if you are done entering numbers.\n\n";

	for (int i = 0; i < 4; i++) {	// A for loop
		cout << "Enter integer " << i + 1 << ": ";	// Asks the user to enter an integer
		cin >> Nums[i];

		if (Nums[i] == -1 && counter >= 2)	// If the integer entered is -1 and two integers are entered break out of the loop
			break;

		while (Nums[i] < 2) {	
			cout << "Please enter an integer greater than 1.\n";	// Error message. Can only enter a number above 2
			cout << "Enter integer " << i + 1 << ": ";
			cin >> Nums[i];
		}

		while (Nums[i] == -1 && counter == 0) {
			cout << "You must enter at least two integers.\n";	// Error message. Must enter at least two integers
			cout << "Enter integer " << i + 1 << ": ";
			cin >> Nums[i];
		}

		while (Nums[i] == -1 && counter == 1) {
			cout << "You must enter at least two integers.\n";	// Error message. Must enter at least two integers
			cout << "Enter integer " << i + 1 << ": ";
			cin >> Nums[i];
		}
		
		counter++;
	}

	if (counter == 2) {		
		LCM(Nums[0], Nums[1], prime, gcd); // Calculates the LCM for 2 integers
		display(Nums[0],Nums[1], prime, gcd);	// Displays the LCM for 2 integers
	}
	else if (counter == 3) {	
		LCM(Nums[0], Nums[1], prime, gcd);		// Calculates the LCM for 3 integers
		display(Nums[0], Nums[1], prime, gcd);	// Displays the LCM for 3 integers
		
		LCM(Nums[0], Nums[2], prime, gcd);
		display(Nums[0], Nums[2], prime, gcd);

		LCM(Nums[1], Nums[2], prime, gcd);
		display(Nums[1], Nums[2], prime, gcd);

		LCM(Nums[0], Nums[1], Nums[2], prime, gcd);
		display(Nums[0], Nums[1], Nums[2], prime, gcd);
	}
	else if (counter == 4) {
		LCM(Nums[0], Nums[1], prime, gcd);	// Calculates the LCM for 4 integers
		display(Nums[0], Nums[1], prime, gcd);	// Displays the LCM from 4 integers

		LCM(Nums[0], Nums[2], prime, gcd);
		display(Nums[0], Nums[2], prime, gcd);

		LCM(Nums[0], Nums[3], prime, gcd);
		display(Nums[0], Nums[3], prime, gcd);

		LCM(Nums[1], Nums[2], prime, gcd);
		display(Nums[1], Nums[2], prime, gcd);

		LCM(Nums[1], Nums[3], prime, gcd);
		display(Nums[1], Nums[3], prime, gcd);

		LCM(Nums[2], Nums[3], prime, gcd);
		display(Nums[2], Nums[3], prime, gcd);

		LCM(Nums[0], Nums[1], Nums[2], prime, gcd);
		display(Nums[0], Nums[1], Nums[2], prime, gcd);

		LCM(Nums[0], Nums[1], Nums[3], prime, gcd);
		display(Nums[0], Nums[1], Nums[3], prime, gcd);

		LCM(Nums[1], Nums[2], Nums[3], prime, gcd);
		display(Nums[1], Nums[2], Nums[3], prime, gcd);

		LCM(Nums[0], Nums[1], Nums[2], Nums[3], prime, gcd);
		display(Nums[0], Nums[1], Nums[2], Nums[3], prime, gcd);
	}

	system("pause");
	return 0;
}

void LCM(int num1, int num2, int& prime, int& gcd) {	// A Function that takes two integers and two reference values

	Primes(num1, num2, prime);	// Calculates the LCM by prime
	
	gcd = GCD(num1, num2);	// Calcules the LCM by GCD
}

void LCM(int num1, int num2, int num3, int& prime, int& gcd) {	// A function that takes three integers and two reference values
	
	Primes(num1, num2, prime);	// Calculates the LCM by prime
	Primes(prime, num3, prime);

	gcd = GCD(num1, num2);	// Calculates the LCM by GCD
	gcd = GCD(gcd, num3);
}

void LCM(int num1, int num2, int num3, int num4, int& prime, int& gcd) {	// A function that takes four integers and two reference values

	Primes(num1, num2, prime);	// Calculates the LCM by prime
	Primes(prime, num3, prime);
	Primes(prime, num4, prime);
	
	gcd = GCD(num1, num2);	// Calculates the LCM by GCD
	gcd = GCD(gcd, num3);
	gcd = GCD(gcd, num4);

}


void Primes(int num1, int num2, int& prime) {	// The Prime function
	
	prime = 1;
	int y = 2;

	while (y <= num1 || y <= num2) {	// A condition that will loop until the larger integer is reached
		if (num1 % y == 0 && num2 % y == 0) {	// If both integers can be divided by y with no remainder,
			num1 /= y;		//  divide both by y and multiply prime by y.
			num2 /= y;
			prime *= y;
		}
		else if (num1 % y == 0) {	// If the first integer can be divided by y with no remainder, 
			num1 /= y;		// divide the first number by y and multiply prime by y
			prime *= y;
		}
		else if (num2 % y == 0) {	// If the second number can be divded by y with no remainder,
			num2 /= y;		// divide the second number by y and multiply prime by y
			prime *= y;
		}
		else
			y++;
	}
}

int GCD(int num1, int num2) {	// The GCD function
	int lcm, gcd = 1;

	for (int x = 1; x <= num1 && x <= num2; x++) {	// Checks if both numbers are larger than x
		if (num1 % x == 0 && num2 % x == 0)	// if both values can be divided by x with no remainder 
			gcd = x;			// GCD becomes x
	}

	return lcm = (num1 * num2) / gcd;	// The LCM equation
}

void display(int n1, int n2, int prime, int gcd) {		// Display function that compares two integers
	cout << "Numbers: " <<n1<< "," <<n2 << ": \n";
	cout << "LCM by prime: " << prime << endl;
	cout << "LCM by GCD: " << gcd << endl << endl;
}

void display(int n1, int n2, int n3, int prime, int gcd) {	// Display function that comapres three integers
	cout << "Numbers: " << n1<<"," <<n2 <<","<<n3<< ": \n";
	cout << "LCM by prime: " << prime << endl;
	cout << "LCM by GCD: " << gcd << endl << endl;
}

void display(int n1, int n2, int n3, int n4, int prime, int gcd) {	// Display function that compares four integers
	cout << "Numbers: " << n1 <<"," << n2 << "," <<n3<<","<<n4<<": \n";
	cout << "LCM by prime: " << prime << endl;
	cout << "LCM by GCD: " << gcd << endl << endl;
}



