
///// Employee Management /////

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int employeeCount = 0;

int curYear = 2019;
int curMonth = 11;
int curDay = 19;

// Checks if given string is in valid date format
bool validateDate(string check)
{
	bool valid = true;
	if (check.length() < 10 || check[2] != '/' || check[5] != '/')
		valid = false;
	else
	{
		for (int i = 0; i < check.length(); i++)
		{
			if (!isdigit(check[i]) && check[i] != '/')
				valid = false;
		}
	}
	return valid;
}

// Checks if given string is in valid phone number format
bool validatePhone(string check)
{
	bool valid = true;
	if (check.length() != 12 || check[3] != '-' || check[7] != '-')
		valid = false;
	else
	{
		for (int i = 0; i < check.length(); i++)
		{
			if (!isdigit(check[i]) && check[i] != '-')
				valid = false;
		}
	}
	return valid;
}

// Structure for recording addresses
struct addr
{
	int stNum = 0;
	string street, city, state;

	// Displays address data
	void displayAddress()
	{
		cout << stNum << " " << street << " " << endl;
		cout << city << ", " << state << endl;
	}

	// Allows user to set address and validates entries
	void setAddress()
	{
		cout << "Enter employee Street Number:" << endl;
		cin >> stNum;
		while (!cin || stNum < 1 || stNum > 10000)
		{
			cout << "Invalid entry. Enter a valid employee Street Number:" << endl;
			cin >> stNum;
		}

		cout << "Enter employee Street Name:" << endl;
		cin >> street;
		while (street.length() < 1 || street.length() > 30)
		{
			cout << "Invalid entry. Enter a valid employee Street Name:" << endl;
			cin >> street;
		}

		cout << "Enter employee City:" << endl;
		cin >> city;
		while (city.length() < 1 || city.length() > 30)
		{
			cout << "Invalid entry. Enter a valid employee City:" << endl;
			cin >> city;
		}

		cout << "Enter employee State:" << endl;
		cin >> state;
		while (state.length() < 1 || state.length() > 30)
		{
			cout << "Invalid entry. Enter a valid employee State:" << endl;
			cin >> state;
		}
	}
};

// Structure for recording employee data
struct employeeData
{
	addr address;
	string name, birthDate, phoneNum, email, dept, hireDate;
	int id = 0, salary = 0;

	// Displays all employee data
	void displayData()
	{
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Birth Date: " << birthDate << endl;
		cout << "Address: ";
		address.displayAddress();
		cout << "Phone Number: " << phoneNum << endl;
		cout << "Email: " << email << endl;
		cout << "Department: " << dept << endl;
		cout << "Hire Date: " << hireDate << endl;
		cout << "Salary: " << salary << endl;
	}

	// Allows user to set all employee data and validates entries
	void setData()
	{
		string input = "";
		int inputInt;

		cout << "Enter a 6-Digit employee ID:" << endl;
		cin >> inputInt;
		while (!cin || inputInt < 99999 || inputInt > 1000000)
		{
			cout << "Invalid entry. Enter a valid 6-Digit employee ID:" << endl;
			cin >> inputInt;
		}
		id = inputInt;

		cout << "Enter employee Name:" << endl;
		cin >> input;
		while (input.length() < 3 || input.length() > 30)
		{
			cout << "Invalid entry. Enter a valid employee Name:" << endl;
			cin >> input;
		}
		name = input;

		cout << "Enter employee Birth Date (MM/DD/YYYY):" << endl;
		cin >> input;
		while (!validateDate(input))
		{
			cout << "Invalid entry. Enter a valid employee Birth Date (MM/DD/YYYY):" << endl;
			cin >> input;
		}
		birthDate = input;

		address.setAddress();

		cout << "Enter employee Mobile Number (000-000-0000):" << endl;
		cin >> input;
		while (input.length() != 12 || input[3] != '-' || input[7] != '-')
		{
			cout << "Invalid entry. Enter a valid employee Mobile Number (000-000-0000):" << endl;
			cin >> input;
		}
		phoneNum = input;

		cout << "Enter employee Email:" << endl;
		cin >> input;
		while (input.length() < 1 || input.length() > 30)
		{
			cout << "Invalid entry. Enter a valid employee Email:" << endl;
			cin >> input;
		}
		email = input;

		cout << "Enter employee Department:" << endl;
		cin >> input;
		while (input.length() < 1 || input.length() > 30)
		{
			cout << "Invalid entry. Enter a valid employee Department:" << endl;
			cin >> input;
		}
		dept = input;

		cout << "Enter employee Hire Date (MM/DD/YYYY):" << endl;
		cin >> input;
		
		while (!validateDate(input))
		{
			cout << "Invalid entry. Enter a valid employee Hire Date (MM/DD/YYYY):" << endl;
			cin >> input;
		}
		hireDate = input;

		cout << "Enter employee Salary:" << endl;
		cin >> inputInt;
		while (!cin || inputInt < 1)
		{
			cout << "Invalid entry. Enter a valid employee Salary:" << endl;
			cin >> inputInt;
		}
		salary = inputInt;
	}
	// Increments salary of employee based on hire date
	int updateSalary()
	{
		int raise;
		int year = stoi(hireDate.substr(6, 4));
		int month = stoi(hireDate.substr(0, 2));
		int day = stoi(hireDate.substr(3, 2));
		int exp = curYear - year;

		if (month > curMonth)
			year--;
		else if (month == curMonth && day > curDay)
			year--;
		if (exp < 5)
			raise = 3000;
		else if (exp <= 10)
			raise = 6000;
		else
			raise = 10000;
		salary += raise;

		return raise;
	}
};

///// Main Employee List /////
employeeData employeeList[25];

// Finds employee ID and returns index location in employee list
int searchById(int id)
{
	int index = -1;

	for (int i = 0; i < employeeCount; i++)
	{
		if (id == employeeList[i].id)
		{
			index = i;
		}
	}
	return index;
}

// Finds employee Name and returns index location in employee list
int searchByName(string name)
{
	int index = -1;

	for (int i = 0; i < employeeCount; i++)
	{
		if (name == employeeList[i].name)
		{
			index = i;
		}
	}
	return index;
}

// Finds employee Phone Number and returns index location in employee list
int searchByPhone(string phone)
{
	int index = -1;

	for (int i = 0; i < employeeCount; i++)
	{
		if (phone == employeeList[i].phoneNum)
		{
			index = i;
		}
	}
	return index;
}

// Reads employee file and builds array of employeeData
void readEmployeeFile()
{
	string lineIn, nameIn, birthDateIn, phoneNumIn, emailIn, deptIn, hireDateIn, streetIn, cityIn, stateIn;
	int idIn, salaryIn, stNumIn;

	employeeCount = 0;

	ifstream inFile("employee.txt");
	if (inFile.is_open())
	{
		while (true)
		{
			inFile >> idIn;
			inFile >> nameIn;
			inFile >> birthDateIn;
			inFile >> stNumIn;
			inFile >> streetIn;
			inFile >> cityIn;
			inFile >> stateIn;
			inFile >> phoneNumIn;
			inFile >> emailIn;
			inFile >> deptIn;
			inFile >> hireDateIn;
			inFile >> salaryIn;

			if (inFile.eof())
				break;
			else
			{
				employeeList[employeeCount].id = idIn;
				employeeList[employeeCount].name = nameIn;
				employeeList[employeeCount].birthDate = birthDateIn;
				employeeList[employeeCount].address.stNum = stNumIn;
				employeeList[employeeCount].address.street = streetIn;
				employeeList[employeeCount].address.city = cityIn;
				employeeList[employeeCount].address.state = stateIn;
				employeeList[employeeCount].phoneNum = phoneNumIn;
				employeeList[employeeCount].email = emailIn;
				employeeList[employeeCount].dept = deptIn;
				employeeList[employeeCount].hireDate = hireDateIn;
				employeeList[employeeCount].salary = salaryIn;
				employeeCount++;
			}
		}
		inFile.close();
	}
	else
		cout << "No employee records found, please add new record(s) before continuing." << endl;
}

// Writes array of employeeData from employeeList to file
void writeEmployeeFile()
{
	ofstream outFile("employee.txt");
	if (outFile.is_open())
	{
		for (int i = 0; i < employeeCount; i++)
		{
			outFile << employeeList[i].id << endl;
			outFile << employeeList[i].name << endl;
			outFile << employeeList[i].birthDate << endl;
			outFile << employeeList[i].address.stNum << endl;
			outFile << employeeList[i].address.street << endl;
			outFile << employeeList[i].address.city << endl;
			outFile << employeeList[i].address.state << endl;
			outFile << employeeList[i].phoneNum << endl;
			outFile << employeeList[i].email << endl;
			outFile << employeeList[i].dept << endl;
			outFile << employeeList[i].hireDate << endl;
			outFile << employeeList[i].salary << endl;
		}
		outFile.close();
	}
	else
	{
		cout << "Unable to open file. Program will now close." << endl;
		exit(0);
	}
}

// Adds new employee record to list and appends data to file
void addRecord()
{
	employeeData newEmployee;

	newEmployee.setData();
	employeeList[employeeCount] = newEmployee;
	employeeCount++;

	fstream appFile;

	appFile.open("employee.txt", ios::app);

	appFile << newEmployee.id << endl;
	appFile << newEmployee.name << endl;
	appFile << newEmployee.birthDate << endl;
	appFile << newEmployee.address.stNum << endl;
	appFile << newEmployee.address.street << endl;
	appFile << newEmployee.address.city << endl;
	appFile << newEmployee.address.state << endl;
	appFile << newEmployee.phoneNum << endl;
	appFile << newEmployee.email << endl;
	appFile << newEmployee.dept << endl;
	appFile << newEmployee.hireDate << endl;
	appFile << newEmployee.salary << endl;
}

// Deletes given employee from all records by phone number
void deleteRecord()
{
	string phone;
	int index;

	cout << "Enter employee phone number to find and delete (000-000-0000):" << endl;
	cin >> phone;
	while (phone.length() != 12 || phone[3] != '-' || phone[7] != '-')
	{
		cout << "Invalid entry. Enter a valid employee phone number to find and delete (000-000-0000):" << endl;
		cin >> phone;
	}
	index = searchByPhone(phone);

	if (index < 0)
		cout << "No phone number found in records. Returning to menu." << endl;
	else
	{
		for (int i = index; i < (employeeCount - 1); i++)
		{
			employeeList[i] = employeeList[i + 1];
		}
		employeeCount--;
	}

	writeEmployeeFile();
}

// Lists all employees in records in order of hire date
void listByHire()
{
	employeeData temp;
	int year, month, day, nextYear, nextMonth, nextDay;
	int pairs;
	int x = 0;
	int y = 0;
	pairs = (employeeCount - 1);
	while (y < employeeCount)
	{
		x = 0;
		while (x < pairs)
		{
			year = stoi(employeeList[x].hireDate.substr(6, 4));
			month = stoi(employeeList[x].hireDate.substr(0, 2));
			day = stoi(employeeList[x].hireDate.substr(3, 2));

			nextYear = stoi(employeeList[x+1].hireDate.substr(6, 4));
			nextMonth = stoi(employeeList[x+1].hireDate.substr(0, 2));
			nextDay = stoi(employeeList[x+1].hireDate.substr(3, 2));
			if (year > nextYear)
			{
				temp = employeeList[x];
				employeeList[x] = employeeList[x + 1];
				employeeList[x + 1] = temp;
			}
			else if (year == nextYear)
			{
				if (month > nextMonth)
				{
					temp = employeeList[x];
					employeeList[x] = employeeList[x + 1];
					employeeList[x + 1] = temp;
				}
				else if (month == nextMonth && day > nextDay)
				{
					temp = employeeList[x];
					employeeList[x] = employeeList[x + 1];
					employeeList[x + 1] = temp;
				}
			}
			x++;
		}
		y++;
		pairs--;
	}
	for (int i = 0; i < employeeCount; i++)
	{
		cout << "--- Employee #" << (i + 1) << " ---" << endl;
		employeeList[i].displayData();
	}
	readEmployeeFile();
}

// Allows user to search employee records using given phone number
void findPhone()
{
	string phone;
	int index;

	cout << "Enter employee phone number to find record (000-000-0000):" << endl;
		cin >> phone;
	while (phone.length() != 12 || phone[3] != '-' || phone[7] != '-')
	{
		cout << "Invalid entry. Enter a valid employee phone number to find record (000-000-0000):" << endl;
		cin >> phone;
	}
	index = searchByPhone(phone);

	if (index < 0)
		cout << "Phone number " << phone << " not found in records. Returning to menu." << endl;
	else
		employeeList[index].displayData();
}

// Finds all employees with over 5 years from hire date and prints result
void findAll()
{
	int year, month, day, exp;
	bool found = false;

	for (int i = 0; i < employeeCount; i++)
	{
		year = stoi(employeeList[i].hireDate.substr(6, 4));
		month = stoi(employeeList[i].hireDate.substr(0, 2));
		day = stoi(employeeList[i].hireDate.substr(3, 2));
		exp = curYear - year;

		if (month > curMonth)
			year--;
		else if (month == curMonth && day > curDay)
			year--;
		if (exp >= 5)
		{
			if (found == false)
			{
				cout << "Employees with over 5 years of experience..." << endl;
				found = true;
			}
			cout << employeeList[i].name << ", ";
		}
	}
	if (found == true)
		cout << endl;
	else
		cout << "No employees with over 5 years of experience found." << endl;
}

// Allows user to update phone number of employee in records
void updatePhone()
{
	string name, phone;
	int index;

	cout << "Enter employee name to update phone number:" << endl;
	cin >> name;
	while (name.length() < 3 || name.length() > 30)
	{
		cout << "Invalid entry. Enter a valid employee name to update phone number:" << endl;
		cin >> name;
	}

	index = searchByName(name);

	if (index < 0)
		cout << "No employee with name, " << name << " found in records. Returning to menu." << endl;
	else
	{
		cout << "Enter new phone number for " << name << ":" << endl;
		cin >> phone;
		while (phone.length() != 12 || phone[3] != '-' || phone[7] != '-')
		{
			cout << "Invalid entry. Enter a valid employee phone number for " << name << " (000-000-0000):" << endl;
			cin >> phone;
		}
		cout << "Employee " << name << "'s phone number changed from " << employeeList[index].phoneNum << " to " << phone << endl;
		employeeList[index].phoneNum = phone;

		writeEmployeeFile();
	}
}

// Allows user to increment employee salary based on experience using given name
void updateSal()
{
	string name, sal;
	int index = 0, raise = 0;

	cout << "Enter employee name to update salary:" << endl;
	cin >> name;

	while (name.length() < 3 || name.length() > 30)
	{
		cout << "Invalid entry. Enter a valid employee name to update salary:" << endl;
		cin >> name;
	}

	index = searchByName(name);

	if (index < 0)
		cout << "No employee with name, " << name << " found in records. Returning to menu." << endl;
	else
	{
		raise = employeeList[index].updateSalary();
		cout << "Employee " << name << " salary raised by $" << raise << ".\nNew total salary: $" << employeeList[index].salary << endl;

		writeEmployeeFile();
	}
}

// Calculated total payroll for all employees
void totalPayroll()
{
	double total = 0;

	for (int i = 0; i < employeeCount; i++)
	{
		total += employeeList[i].salary;
	}
	cout << "Monthly Payroll: " << (total / 12) << endl;
	cout << "Yearly Payroll: " << total << endl;
}

// Displays all employee records in order of entry
void displayRecords()
{
	for (int i = 0; i < employeeCount; i++)
	{
		cout << "--- Employee #" << (i + 1) << " ---" << endl;
		employeeList[i].displayData();
	}
}

// Allows user to quit program
bool checkQuit()
{
	string input;
	bool quitOpt = false;

	cout << "Are you sure you want to quit? (Y/N)" << endl;
	cin >> input;
	while (input.length() != 1 || (tolower(input[0]) != 'y' && tolower(input[0]) != 'n'))
	{
		cout << "Invalid entry. Are you sure you want to quit? (Y/N)" << endl;
		cin >> input;
	}
	if (tolower(input[0]) == 'y')
		quitOpt = true;

	return quitOpt;
}

// Displays main menu and returns entered option
int displayMenu()
{
	int menuIn;

	cout << "--- Main Menu ---\n";
	cout << "1 - List by hire date.\n";
	cout << "2 - Add new record.\n";
	cout << "3 - Delete record.\n";
	cout << "4 - Search employee mobile number.\n";
	cout << "5 - Find employees over 5 years.\n";
	cout << "6 - Update telephone number.\n";
	cout << "7 - Update salary.\n";
	cout << "8 - Write total payroll of company.\n";
	cout << "9 - Display all records.\n";
	cout << "10 - Exit.\n";

	cin >> menuIn;
	while (!cin || menuIn < 1 || menuIn > 10)
	{
		cout << "Invalid entry. Please select a valid menu option" << endl;
		cin >> menuIn;
	}

	return menuIn;
}

// Main function allows user to enter and update records of employees until 10 is entered to quit
int main()
{
	int menuOpt;
	bool quit = false;

	readEmployeeFile();

	do
	{
		menuOpt = displayMenu();
		
		switch (menuOpt)
		{
			case 1:
				listByHire();
				break;
			case 2:
				addRecord();
				break;
			case 3:
				deleteRecord();
				break;
			case 4:
				findPhone();
				break;
			case 5:
				findAll();
				break;
			case 6:
				updatePhone();
				break;
			case 7:
				updateSal();
				break;
			case 8:
				totalPayroll();
				break;
			case 9:
				displayRecords();
				break;
			case 10:
				quit = checkQuit();
				break;
		}
	} while (!quit);
}