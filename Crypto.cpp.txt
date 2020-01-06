#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

char getEorD();
char getLetter();
double getNum();
int getPosInt();
vector <char> getLetterCode();
void EorDcrypt(string& data, vector <char>& letterCode, char letter);
void printCrypt(string data);
void printCode(vector <char> code);
void increaseLetterCode(vector <char>& v, int num);

int main() {
	system("TITLE Vignere Cipher");

	char letter;
	string data, crypt, newData;
	vector <char> letterCode;
	int OGsize;

	while (true) {
		cout << "Are you ENCRYPTING(E) or DECODING(D)? ";
		letter = getEorD();

		if (letter == 'E' || letter == 'e')
			crypt = "ENCRYPTED";
		else
			crypt = "DECRYPTED";

		cout << "\nWhat is your code? "
			<< "\nEnter '/' to end code input.\n\n";
		letterCode = getLetterCode();

		cout << "\n  Your code is: ";
		printCode(letterCode);

		cout << "\n  What do you want to be " << crypt << ": ";
		getline(cin >> ws, data);

		OGsize = letterCode.size() - 1;
		letterCode.resize(data.length());

		increaseLetterCode(letterCode, OGsize);

		EorDcrypt(data, letterCode, letter);

		cout << "\n " << crypt << " data: \n ---------------\n ";
		printCrypt(data);

		cout << endl << endl;
		system("PAUSE");
	}
	return 0;
}

char getEorD() {
	char letter;

	cin >> letter;
	cin.ignore(200, '\n');

	while (letter != 'E' && letter != 'e' && letter != 'D' && letter != 'd') {
		cout << "Invalid CHARACTER, enter either 'E' for ENCRYPTING or 'D' for DECRYPTING: ";
		cin >> letter;
		cin.ignore(200, '\n');
	}
	return letter;
}

double getNum() {
	double num;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(200, '\n');

		cout << "This is not a number. Try Again: ";
		cin >> num;
		cin.ignore(200, '\n');
	}
	return num;
}

char getLetter() {
	char letter;

	cin >> letter;
	cin.ignore(200, '\n');

	while (letter != '/' && !(letter >= 'A' && letter <= 'Z') && !(letter >= 'a' && letter <= 'z')) {
		cout << "Invalid CHARACTER, enter a letter between from A - Z or a - z. Try again: ";
		cin >> letter;
		cin.ignore(200, '\n');
	}
	return letter;
}

int getPosInt() {
	double num;

	num = getNum();

	while (num < 0 || (int)num != num) {
		cout << "  Please enter a" << ((int)num != num ? " whole" : "") << (num < 0 ? " positive" : "") << " number. Try again: ";
		num = getNum();
	}
	return (int)num;
}

vector <char> getLetterCode() {
	vector <char> letterCode;
	char flagValue = '/';
	int count = 0;

	for (unsigned int i = 0;; i++) {
		cout <<
			"Enter letter #" << i + 1 << ": ";
		letterCode.push_back(i);

		letterCode[i] = getLetter();

		while (letterCode[0] == flagValue) {
			cout << "This program needs at least one letter to work. Try again: ";
			letterCode[i] = getLetter();
		}
		if (letterCode[i] == flagValue)
			break;
	}
	return letterCode;
}

void increaseLetterCode(vector <char>& v, int num) {
	for (unsigned int i = 0; i < v.size(); i++) {
		for (unsigned int j = 0; j < v.size(); j++) {
			if (i % num == j)
				v[i + num] = v[j];
		}
	}
}

void printCode(vector <char> code) {
	for (unsigned int i = 0; i < code.size() - 1; i++) {
		cout << code[i] << " ";
	}
}

void EorDcrypt(string& data, vector <char>& num, char letter) {
	char upA = 'A', loA = 'a';
	if (letter == 'D' || letter == 'd') {
		upA = -'A';
		loA = -'a';
	}
	for (unsigned int i = 0; i < data.length(); i++) {
		if (data[i] >= 'A' && data[i] <= 'Z' && num[i] >= 'A' && num[i] <= 'Z') {
			num[i] = (letter == 'D' || letter == 'd' ? -num[i] : num[i]);
			data[i] += (num[i] - upA);

			if (data[i] > 'Z' || data[i] < 0)
				data[i] -= 26;
			if (data[i] < 'A')
				data[i] += 26;
		}
		if (data[i] >= 'a' && data[i] <= 'z' && num[i] >= 'A' && num[i] <= 'Z') {
			num[i] = (letter == 'D' || letter == 'd' ? -num[i] : num[i]);
			data[i] += (num[i] - upA);

			if (data[i] > 'z' || data[i] < 0)
				data[i] -= 26;
			if (data[i] < 'a')
				data[i] += 26;
		}
		if (data[i] >= 'A' && data[i] <= 'Z' && num[i] >= 'a' && num[i] <= 'z') {
			num[i] = (letter == 'D' || letter == 'd' ? -num[i] : num[i]);
			data[i] += (num[i] - loA);

			if (data[i] > 'Z' || data[i] < 0)
				data[i] -= 26;
			if (data[i] < 'A')
				data[i] += 26;
		}
		if (data[i] >= 'a' && data[i] <= 'z' && num[i] >= 'a' && num[i] <= 'z') {
			num[i] = (letter == 'D' || letter == 'd' ? -num[i] : num[i]);
			data[i] += (num[i] - loA);

			if (data[i] > 'z' || data[i] < 0)
				data[i] -= 26;
			if (data[i] < 'a')
				data[i] += 26;
		}
	}
}

void printCrypt(string data) {
	for (unsigned int i = 0; i < data.length(); i++) {
		cout << data[i];
	}
}
