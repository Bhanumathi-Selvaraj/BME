#include <iostream> 
#include <vector>
#include <string>
using namespace std;

int findLCM(int v1, int v2);
int findFactorial(int num);
int findNcR(int n, int r);
int getPosInt(string item);
int getPosIntLessThanFive(string item);
int getNum();
void resize2DVector(vector <vector <int> > &v1, vector <vector <int> > &v2);
void eraseElementsEqualToZero(vector <int> &v, vector <int> &index);
void printVector(vector <int> v);
void print2DVector(vector <vector <int> > v);
vector <int> primeFactorization(int num);
vector <int> countIndex(vector <int> v);
vector <int> setValToZero(vector <int> v, vector <int> index);
vector <vector <int> > create2DVector(vector <int> v1, vector <int> v2);
vector <vector <int> > findUnionOfPrimes(int val1, int val2);

int main() {
	int num;
	int a[5];

	cout << "How many numbers will you be inputting? ";
	num = getPosIntLessThanFive("This number");

	for (int i = 0; i < num; i++) {
		cout << "Enter number " << i + 1 << ": ";
		a[i] = getPosInt("This value");
	}

	cout << endl;

	for (int i = 0; i < num - 1; i++) {
		for (int j = i + 1; j < num; j++) {
			cout << "LCM(" << a[i] << ", " << a[j] << "): " << findLCM(a[i], a[j]) << endl;
		}
	}

	if (num > 2) {
		cout
			<< "LCM(" << a[0] << ", " << a[1] << ", " << a[2] << "): " << findLCM(findLCM(a[0], a[1]), a[2]) << endl;
	}
	if (num > 3) {	
		cout
			<< "LCM(" << a[0] << ", " << a[1] << ", " << a[3] << "): " << findLCM(findLCM(a[0], a[1]), a[3]) << endl
			<< "LCM(" << a[0] << ", " << a[2] << ", " << a[3] << "): " << findLCM(findLCM(a[0], a[2]), a[3]) << endl
			<< "LCM(" << a[1] << ", " << a[2] << ", " << a[3] << "): " << findLCM(findLCM(a[1], a[2]), a[3]) << endl
			<< "LCM(" << a[0] << ", " << a[1] << ", " << a[2] << ", " << a[3] << "): " << findLCM(findLCM(a[0], a[1]), findLCM(a[2], a[3])) << endl;
	}

	cout << endl;
	system("PAUSE");
	return 0;
}

// This function creates a vector to store each prime factor
vector <int> primeFactorization(int num) {
	vector <int> v;

	for (int i = 2; i <= num / i; i++) {
		while (num % i == 0) {
			num = num / i;
			v.push_back(i);
		}
	}
	if (num > 1) v.push_back(num);

	return v;
}

// This function counts each time a value occurs more than once and stores that into a index vector
vector <int> countIndex(vector <int> v) {
	vector <int> index;
	index.resize(v.size());

	for (unsigned int i = 0; i < v.size(); i++) {
		for (unsigned int j = 0; j < v.size(); j++) {
			if (v[i] == v[j])
				index[i]++;
		}
	}
	return index;
}

// This function sets repetitive values within the vector to zero
vector <int> setValToZero(vector <int> v, vector <int> index) {
	for (unsigned int i = 0; i < v.size() - 1; i++) {
		for (unsigned int j = i + 1; j < v.size(); j++) {
			if (v[i] == v[j] && index[i] == index[j])
				index[j] = 0;
			if (v[i] == v[j] && index[i] > index[j])
				index[j] = 0;
			if (v[i] == v[j] && index[i] < index[j])
				index[i] = 0;
		}
	}
	return index;
}

// This function erases values of the the vector that correspond with zero
void eraseElementsEqualToZero(vector <int> &v, vector <int> &index) {
	vector <int> temp, temp2;

	for (unsigned int i = 0; i < index.size(); i++) {
		if (index[i] != 0) {
			temp.push_back(v[i]);
			temp2.push_back(index[i]);
		}
	}

	v.resize(temp.size());
	index.resize(temp2.size());

	for (unsigned int i = 0; i < temp.size(); i++) {
		v[i] = temp[i];
		index[i] = temp2[i];
	}
}

// This function finds the union of primes
vector <vector <int> > findUnionOfPrimes(int val1, int val2) {
	vector <int> v1 = primeFactorization(val1);
	vector <int> v2 = primeFactorization(val2);
	vector <int> v1Index, v2Index;
	vector <vector <int> > vector;

	v1Index = countIndex(v1);
	v2Index = countIndex(v2);

	v1Index = setValToZero(v1, v1Index);
	v2Index = setValToZero(v2, v2Index);

	eraseElementsEqualToZero(v1, v1Index);
	eraseElementsEqualToZero(v2, v2Index);

	for (unsigned int i = 0; i < v2.size(); i++) {
		v1.push_back(v2[i]);
		v1Index.push_back(v2Index[i]);
	}

	v1Index = setValToZero(v1, v1Index);
	eraseElementsEqualToZero(v1, v1Index);

	vector = create2DVector(v1, v1Index);
	return vector;
}

// This function resizes a 2D array
void resize2DVector(vector <vector <int> > &v1, vector <vector <int> > &v2) {
	for (unsigned int i = v2[0].size(); i < v1[0].size(); i++) {
		v2[0].push_back(0);
		v2[1].push_back(0);
	}
}

// This function finds the LCM
int findLCM(int v1, int v2) {
	vector <vector <int> > v;
	vector <int> temp;
	int lcm = 1;

	v = findUnionOfPrimes(v1, v2);

	for (unsigned int i = 0; i < v[0].size(); i++) {
		temp.push_back(1);
	}

	for (unsigned int i = 0; i < v[0].size(); i++) {
		while (v[1][i] > 0) {
			temp[i] *= v[0][i];
			v[1][i]--;
		}
	}

	for (unsigned int i = 0; i < v[0].size(); i++) {
		lcm *= temp[i];
	}

	return lcm;
}

// Prints a vector, used for testing
void printVector(vector <int> v) {
	for (unsigned int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}

// This function merges 2 vectors into a 2D vector
vector <vector <int> > create2DVector(vector <int> v1, vector <int> v2) {
	vector <vector <int> > v3;

	v3.push_back(v1);
	v3.push_back(v2);

	return v3;
}

// Prints a 2D vector, used for testing
void print2DVector(vector <vector <int> > v) {
	for (unsigned int i = 0; i < v.size(); i++) {
		for (unsigned int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

// This function is used for input validation
int getNum() {
	int num;

	cin >> num;
	cin.ignore(200, '\n');

	while (cin.fail()) {
		cin.clear();
		cin.ignore(120, '\n');

		cout << "This is not a number, re-enter here: ";
		cin >> num;
	}
	return num;
}

// This function is used for input validation
int getPosInt(string item) {
	int num;

	num = getNum();

	while (num < 2) {
		cout << item << " must be greater than 1. Try again: ";
		num = getNum();
	}
	return num;
}

// This function is used for input validation
int getPosIntLessThanFive(string item) {
	int num;

	num = getNum();
	while (num < 2 || num > 4) {
		cout << " must be an integer greater than 2, and less than 5, retry: ";
		num = getNum();
	}
	return num;
}

// Used to calculate a factorial
int findFactorial(int num) {
	int factorial = 1;
	for (int i = 1; i < num + 1; i++) {
		factorial *= i;
	}
	return factorial;
}

// Used to find the number of combinations, ex. 4c3 = 4
int findNcR(int n, int r) {
	int nCr = findFactorial(n) / (findFactorial(r) * findFactorial(n - r));
	return nCr;
}
