#include <iostream>
using namespace std;

//// Least Common Multiples ///////

const int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
const int PNUMS = (sizeof(primes) / sizeof(*primes));
const int MAX = 5;
int numCount;

// Function finds primes factors of given number
void primeFactors(int num, int pCount[])
{
	while (num % 2 == 0)
	{
		pCount[0]++;
		num = num / 2;
	}

	for (int i = 1; i < PNUMS; i++)
	{ 
		while (num % primes[i] == 0)
		{
			pCount[i]++;
			num = num / primes[i];
		}
	}

	if (num > 2)
	{
		for (int i = 1; i < PNUMS; i++)
		{
			if (num == primes[i])
				pCount[i]++;
		}
	}
}

// Function populates array pCount with prime factor information for given nums
void findPrimeFactors(int nums[], int pCount[MAX + 1][PNUMS])
{
	for (int i = 0; i < numCount; i++)
	{
		primeFactors(nums[i], pCount[i]);
	}
}

// Function resets given row of pCount values to 0
void resetMaxOccurences(int primeMax[])
{
	for (int i = 0; i < PNUMS; i++)
	{
		primeMax[i] = 0;
	}
}

// Function finds max occurence of prime factors in pCount array
void findMaxOccurences(int pCount[MAX + 1][PNUMS], bool check[])
{
	for (int j = 0; j < PNUMS; j++)
	{
		for (int i = 0; i <= MAX; i++)
		{
			if (check[i] == true)
			{
				if (pCount[i][j] > pCount[MAX][j])
					pCount[MAX][j] = pCount[i][j];
			}
		}
	}
}

// Function finds least common multiple using max occurences in pCount array
double findLcm(int primeMax[])
{
	double lcm = 1;
	for (int i = 0; i <= PNUMS; i++)
	{
		if (primeMax[i] > 0)
			lcm *= pow(primes[i], primeMax[i]);
	}
	return lcm;
}

// Function finds a prints least common multiple of all subsets of given array nums
void printLcm(int nums[], int pCount[MAX + 1][PNUMS], int x, int start, int currLen, bool check[])
{
	if (currLen == x)
	{
		resetMaxOccurences(pCount[MAX]);

		cout << "LCM { ";
		for (int i = 0; i < numCount; i++)
		{
			if (check[i] == true)
			{
				cout << nums[i] << " ";
			}
		}
		findMaxOccurences(pCount, check);

		cout << "} : " << findLcm(pCount[MAX]) << endl;
		return;
	}
	if (start == numCount)
	{
		resetMaxOccurences(pCount[MAX]);
		findMaxOccurences(pCount, check);
		return;
	}
	
	check[start] = true;
	printLcm(nums, pCount, x, start + 1, currLen + 1, check);
	
	check[start] = false;
	printLcm(nums, pCount, x, start + 1, currLen, check);
}

// Function allows user to enter numbers
void enterNums(int nums[])
{
	int numIn;

	while (numCount < MAX)
	{
		cout << "Enter number #" << (numCount + 1) << ", or 0 to finish:" << endl;
		cin >> numIn;
		while (!cin || numIn < 2 || numIn > 100)
		{
			cout << "Invalid number entered. Enter number #" << (numCount + 1) << ", or 0 to finish:" << endl;
			cin >> numIn;
		}
		if (numIn == 0)
		{
			if (numCount >= 2)
				break;
			else
				cout << "Must enter at least two numbers." << endl;
		}
		else
		{
			nums[numCount] = numIn;
			numCount++;
		}
	}
}

// Main function allows user to enter a set of numbers, and finds the least common multiple of all subsets using prime factorization
int main()
{
	int nums[MAX];
	bool check[MAX];
	int pCount[MAX + 1][PNUMS] = { 0 };

	cout << "This program finds the least common multiple of a set of numbers: " << endl;

	enterNums(nums);

	findPrimeFactors(nums, pCount);

	cout << " ------------  LCM of all subsets  ------------ " << endl;

	for (int x = 2; x <= numCount; x++)
	{
		printLcm(nums, pCount, x, 0, 0, check);
	}

	return 0;
}