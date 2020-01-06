///***Car Rental***///
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

void Eco();
void Lux();
void Sport();
void suv();
void Truck();
void check_birthdate();
bool check_date();
int rent_days(string);
string pickup();
bool display(string, double, string, int);
void cust_Info();
void writeData(string, double, string, int);

struct birth {
	int month;
	int day;
	int year;
};

struct location {
	string bb = "Back Bay";
	string ss = "South Station";
	string ns = "North Station";
	string ct = "Chinatown";
};

struct customer_info {
	string first;
	string last;
	birth birthday;
	string SSN;
	int license;
	string phone;
	location pickup_loc;
};

class Economy {
private:
	string
		model;
	double
		price;

public:

	Economy(string model, double price)
	{
		this->model = model;                          //Constructor to build the objects
		this->price = price;
	}

	string getModel()
	{
		return model;
	}

	double getPrice()
	{
		return price;
	}

};

class Luxury {
private:
	string car_model;
	double cost;
	string L1 = "Audi A8", L2 = "Lexus LC", L3 = "BMW 740i";
	double rent1 = 125.0, rent2 = 100.0, rent3 = 150.0;

public:
	Luxury() { };
	Luxury(int num) {
		if (num == 1) {
			car_model = L1;
			cost = rent1;
		}
		else if (num == 2) {
			car_model = L2;
			cost = rent2;
		}
		else if (num == 3) {
			car_model = L3;
			cost = rent3;
		}
	}
	void luxCars() {
		cout << endl;
		cout << "Here are your car options\n"
			<< "1. " << L1 << "\t Rental price: $" << rent1 << endl
			<< "2. " << L2 << "\t Rental price: $" << rent2 << endl
			<< "3. " << L3 << "\t Rental price: $" << rent3 << endl
			<< "Choose the car you would like to rent. Enter a number between 1-3: ";
	}
	string getCar() {
		return car_model;
	}
	double getCost() {
		return cost;
	}
};

class SportCars {
private:
	int userChoice;
	double price;
	string model;
public:
	void displayChoices() {
		cout << "Available Cars: \tCost Per Day:\n"
			<< "1. BMW i8        \t$100\n"
			<< "2. Audi R8 V10   \t$120\n"
			<< "3. McLaren 570S  \t$150\n";
	}

	void getChoice() {
		int carOption;

		cout << "\nEnter your car of choice: ";
		cin >> carOption;

		while (carOption > 3 || carOption < 1) {
			cout << "Invalid input! Try again: ";
			cin >> carOption;
		}
		userChoice = carOption;
	}

	void displayCarDetails() {
		cout << "\n\nCar Details: ";
		if (userChoice == 1) {
			cout << "\nModel: 2017 \nHorsepower: 357 hp \nFuel tank capacity: 11.1 gal \nMiles: 9,000 \nCost Per Day: $100\n";
			model = "BMW i8";
		}
		else
			if (userChoice == 2) {
				cout << "Model: 2018 \nHorsepower: 540 hp \nFuel tank capacity: 11.4 gal \nMiles: 6,000 \nCost Per Day: $120\n";
				model = "Audi R8 V10";
			}
			else {
				cout << "Model: 2019 \nHorsepower: 562 hp \nFuel tank capacity: 19 gal \nMiles: 7,000 \nCost Per Day: $150\n";
				model = "McLaren 570S";
			}
	}

	void setPrice() {
		char buyCar;

		cout << "\nWould you like to rent this car?(y/n) ";
		cin >> buyCar;

		buyCar = toupper(buyCar);

		while (buyCar != 'Y' && buyCar != 'N') {
			cout << "Invalid input! Enter Y or N: ";
			cin >> buyCar;

			buyCar = toupper(buyCar);
		}

		if (buyCar == 'Y') {
			price = (userChoice == 1 ? 100 : userChoice == 2 ? 120 : 150);
		}
		else {
			displayChoices();
			getChoice();
			displayCarDetails();
			setPrice();
		}
	}
	string getCar() {
		return model;
	}
	double getCost() {
		return price;
	}
};

class SUV
{
private:
	string model;
	double price;
	int year;
public:

	void setCar(string x, double y)
	{
		model = x;
		price = y;
	}
	string getModel() {
		return model;

	}
	double getPrice() {
		return price;
	}

};

class truck {
private:
	string style1 = "Dodge Ram",
		style2 = "Chevy Silverado",
		style3 = "Toyota Tacoma";
	string model;
	double price1 = 90, price2 = 120.55, price3 = 53.25;

	void setStyle1(string style, double price) {
		this->style1 = style;
		this->price1 = price;

	}

	void setStyle2(string style, double price) {
		this->style2 = style;
		this->price2 = price;

	}

	void setStyle3(string style, double price) {
		this->style3 = style;
		this->price3 = price;

	}

public:
	void getStyle1() {
		setStyle1(style1, price1);
		cout << "The style is " << style1 << " and the price to rent per day is " << price1 << ".\n"
			<< "It has a automatic tranmission and a V8 engine. It is red in color\n";
	}

	void getStyle2() {
		setStyle1(style2, price2);
		cout << "The style is " << style2 << " and the price to rent per day is " << price2 << ".\n"
			<< "It has a automatic tranmission and 285 horsepower and 305 pounds - feet of torque.It is silver in color\n";
	}

	void getStyle3() {
		setStyle1(style3, price3);
		cout << "The style is " << style3 << " and the price to rent per day is " << price3 << ".\n"
			<< "It has a manual tranmission and has four wheel drive. It is blue in color\n";
	}

	double getPrice1() {
		return price1;
	}

	double getPrice2() {
		return price2;
	}
	double getPrice3() {
		return price3;
	}

	string getCar(int num) {
		if (num == 1)
			return style1;
		else if (num == 2)
			return style2;
		else if (num == 3)
			return style3;
	}

};

customer_info customer;
static double yFee = 25.0;

int main() {
	
	check_birthdate();

	while (1) {
		int choice;
		
		cout << endl;
		cout << "Rental Car System\n"
			<< "-------------------\n"
			<< "1. Economy\n"
			<< "2. Luxury\n"
			<< "3. Sport\n"
			<< "4. SUV\n"
			<< "5. Truck\n"
			<< "6. Exit Program\n";
		cout << "Enter a option between 1-5 and 6 to exit the program\n";
		cin >> choice;

		switch (choice) {
		case 1: cout << "You have chosen Economy\n";
			Eco();
			break;
		case 2: cout << "You have chosen Luxury\n";
			Lux();
			break;
		case 3: cout << "You have chosen Sport\n";
			Sport();
			break;
		case 4: cout << "You have chosen SUV\n";
			suv();
			break;
		case 5: cout << "You have chosen Truck\n";
			Truck();
			break;
		case 6: exit(0);
			break;
		default: cout << "Sorry I did not get that. Please enter a number between 1-6.\n";
			break;
		}
	}

	system("pause");
	return 0;
}

void Eco() {
	int choice, days;
	double chosenCarPrice;
	string chosenCar, chosenLocation;
	bool condition;

	Economy car1("Toyota Camry", 75);
	Economy car2("Hyundai Accent", 60);              // Create three objects
	Economy car3("Honda Accord", 90);

	cout << endl;
	cout << "Please choose a car to rent from the cars below\n\n";

	cout
		<< "1." << car1.getModel() << "\t\t Price: $" << car1.getPrice() << "\n"
		<< "2." << car2.getModel() << "\t Price: $" << car2.getPrice() << "\n"
		<< "3." << car3.getModel() << "\t\t Price: $" << car3.getPrice() << "\n";
	cin >> choice;

	switch (choice)
	{
	case 1:
		chosenCar = car1.getModel();
		chosenCarPrice = car1.getPrice();
		break;
	case 2:
		chosenCar = car2.getModel();
		chosenCarPrice = car2.getPrice();
		break;
	case 3:
		chosenCar = car3.getModel();
		chosenCarPrice = car3.getPrice();
		break;
	}

	cout << "You have chosen " << chosenCar << ".\n"
		<< "Rental price: $" << chosenCarPrice << " per day.\n";

	chosenLocation = pickup();
	days = rent_days(chosenCar);
	condition = display(chosenCar, chosenCarPrice, chosenLocation, days);

	if (condition == true)
		cust_Info();
	else if (condition == false)
		return;

	writeData(chosenCar, chosenCarPrice, chosenLocation, days);
}

void Lux() {
	int choice, days;
	string location;
	bool condition;
	Luxury options;
	options.luxCars();
	
	cin >> choice;
	Luxury Lux(choice);

	cout << endl;
	cout << "You have chosen " << Lux.getCar() << ".\n"
		<< "Rental price: $" << Lux.getCost() << " per day.\n";
	
	location = pickup();
	days = rent_days(Lux.getCar());
	condition = display(Lux.getCar(), Lux.getCost(), location, days);

	if (condition == true)
		cust_Info();
	else if (condition == false)
		return;

	writeData(Lux.getCar(), Lux.getCost(), location, days);
}

void Sport() {
	int days;
	double price;
	bool condition;
	string location, model;
	SportCars sport;

	sport.displayChoices();
	sport.getChoice();
	sport.displayCarDetails();
	sport.setPrice();

	model = sport.getCar();
	price = sport.getCost();

	location = pickup();
	days = rent_days(model);
	condition = display(model, price, location, days);

	if (condition == true)
		cust_Info();
	else if (condition == false)
		return;

	writeData(model, price, location, days);
}

void suv() {
	SUV Honda;
	SUV Jeep;
	SUV Jaguar;
	string model, location;
	int days;
	double price;
	bool condition;

	Honda.setCar("Honda CRV", 49.99);
	Jeep.setCar("Jeep Wrangler", 79.99);
	Jaguar.setCar("Jaguar F-PACE", 119.99);

	cout << endl;
	cout << "Please choose a SUV to rent from the selection below\n";
	char n;
	cout << "We have 3 kinds of SUVs.\n";
	cout << "A: Car model: " << Honda.getModel() << " Daily price: " << Honda.getPrice() << endl;
	cout << "B: Car model: " << Jeep.getModel() << " Daily price: " << Jeep.getPrice() << endl;
	cout << "C: Car model: " << Jaguar.getModel() << " Daily price: " << Jaguar.getPrice() << endl;
	cout << "Please enter your selection: ";
	cin >> n;

	switch (n)
	{
	case 'A': case'a':
		model = Honda.getModel();
		price = Honda.getPrice();
		break;
	case 'B': case'b':
		model = Jeep.getModel();
		price = Jeep.getPrice();
		break;
	case 'C': case'c':
		model = Jaguar.getModel();
		price = Jaguar.getPrice();
		break;
	default:
		cout << "Please input valid selection.";
	}

	cout << endl;
	cout << "You have chosen " << model << endl
		<< "Rental price: " << price << " per day.\n";

	location = pickup();
	days = rent_days(model);
	condition = display(model, price, location, days);

	if (condition == true)
		cust_Info();
	else if (condition == false)
		return;

	writeData(model, price, location, days);
}

void Truck() {
	truck truck1;
	string model, location;
	double price;
	int userInput, days;
	bool condition;

	cout << "What truck do you want to rent?\n";
	cout << "1. ";
	truck1.getStyle1();
	cout << "2. ";
	truck1.getStyle2();
	cout << "3. ";
	truck1.getStyle3();
	
	cin >> userInput;

	switch (userInput) {
	case 1: cout << "\nYour rented truck info: "; truck1.getStyle1();
		cout << "\nThe cost is " << truck1.getPrice1() << endl;
		model = truck1.getCar(1);
		price = truck1.getPrice1();
		break;
	case 2: cout << "\nYour rented truck info: "; truck1.getStyle2();
		cout << "\nThe cost is " << truck1.getPrice2() << endl;
		model = truck1.getCar(2);
		price = truck1.getPrice2();
		break;
	case 3: cout << "\nYour rented truck info: "; truck1.getStyle3();
		cout << "\nThe cost is " << truck1.getPrice3() << endl;
		model = truck1.getCar(3);
		price = truck1.getPrice3();
		break;
	default: cout << "Invalid choice";
	}

	location = pickup();
	days = rent_days(model);
	condition = display(model, price, location, days);

	if (condition == true)
		cust_Info();
	else if (condition == false)
		return;

	writeData(model, price, location, days);
}

void check_birthdate() {
	bool condition = true;

	while (condition) {
		cout << "Enter your birthdate (MM DD YYYY, ex: 02 14 1995): ";
		cin >> customer.birthday.month >> customer.birthday.day >> customer.birthday.year;
		condition = check_date();

		if (condition == false) {
			if (customer.birthday.year > 1998) {
				cout << "You must be over the age of 21 to rent a car.\n";
				system("pause");
				exit(0);
			}
			else if (customer.birthday.year >= 1994 && customer.birthday.year <= 1998) {
				cout << "You are under the age of 25, a young driver fee of $25 will be applied to the bill.\n";
			}
		}
	}
}

bool check_date() {
	bool condition;

	if (customer.birthday.month < 1 || customer.birthday.month > 12) {
		cout << "Cannot have a month " << customer.birthday.month << ".\n";
		condition = true;
	}
	else {
		if (customer.birthday.month == 1 || customer.birthday.month == 3 || customer.birthday.month == 5 || customer.birthday.month == 7 
			|| customer.birthday.month == 8 || customer.birthday.month == 10 || customer.birthday.month == 12) {
			if (customer.birthday.day < 1 || customer.birthday.day > 31) {
				cout << "Cannot have " << customer.birthday.day << " days in month " << customer.birthday.month << ".\n";
				condition = true;
			}
			else
				condition = false;
		}
		else if (customer.birthday.month == 4 || customer.birthday.month == 6 || customer.birthday.month == customer.birthday.month == 9 || customer.birthday.month == 11) {
			if (customer.birthday.day < 1 || customer.birthday.day > 30) {
				cout << "Cannot have " << customer.birthday.day << " days in month " << customer.birthday.month << ".\n";
				condition = true;
			}
			else
				condition = false;
		}
		else if (customer.birthday.month == 2) {
			if (customer.birthday.day < 1 || customer.birthday.day > 28) {
				cout << "Cannot have " << customer.birthday.day << "days in month " << customer.birthday.month << ".\n";
				condition = true;
			}
			else
				condition = false;
		}
	}

	if (customer.birthday.year < 1900 || customer.birthday.year > 2019) {
		cout << "Did you enter your birth year correctly?\n";
		condition = true;
	}

	return condition;
}

int rent_days(string car) {
	int days;

	while (1) {
		cout << endl;
		cout << "How many days would you like to rent the " << car << " for? ";
		cin >> days;

		if (days < 1)
			cout << "Cannot have zero or negative days.\n";
		else if (days > 30)
			cout << "The maximum amount of days you can rent is 30.\n";
		else
			break;
	}
	
	return days;
}

string pickup() {
	int choice;
	string location;
	
	cout << "Choose a pickup location\n";
	cout << "1. " << customer.pickup_loc.bb << endl
		<< "2. " << customer.pickup_loc.ct << endl
		<< "3. " << customer.pickup_loc.ns << endl
		<< "4. " << customer.pickup_loc.ss << endl;

	cin >> choice;

	switch (choice) {
	case 1: cout << "You have chosen " << customer.pickup_loc.bb << endl;
		location = customer.pickup_loc.bb;
		break;
	case 2: cout << "You have chosen " << customer.pickup_loc.ct << endl;
		location = customer.pickup_loc.ct;
		break;
	case 3: cout << "You have chosen " << customer.pickup_loc.ns << endl;
		location = customer.pickup_loc.ns;
		break;
	case 4: cout << "You have chosen " << customer.pickup_loc.ss << endl;
		location = customer.pickup_loc.ss;
		break;
	}
	
	return location;
}

bool display(string car, double cost, string location, int days) {
	char choice;

	cout << endl;
	cout << "Here are the options that you have chosen: \n";
	cout << "Car: " << car << endl
		<< "Rental Cost (per day): $" << cost << endl
		<< "Pickup location: " << location << endl
		<< "Rental time (in days): " << days << endl;
	if (customer.birthday.year >= 1994 && customer.birthday.year <= 1998) {
		cout << "Young Driver Fee: $" << yFee << endl;
		cout << "Total Cost: $" << (cost * days) + yFee << endl;
	}
	else
		cout << "Total Cost: $" << cost * days << endl;

	
	while (1) {
		cout << endl;
		cout << "Is this infomation correct? (Enter 'y' for Yes and 'n' for No)\n"
			<< "Note: Entering No will return you to the main menu. \n";
		cin >> choice;
		if (choice == 'y') {
			return true;
			break;
		}
		else if (choice == 'n') {
			return false;
			break;
		}
		else
			cout << "Sorry I did not get that.\n";
	}
}

void cust_Info() {
	cout << endl;
	cout << "Enter your first name: ";
	cin >> customer.first;
	cout << "Enter your last name: ";
	cin >> customer.last;
	cout << "Enter your license number: ";
	cin >> customer.license;
	cout << "Enter your Social Security Number: ";
	cin >> customer.SSN;
	cout << "Etner your phone number: ";
	cin >> customer.phone;
}

void writeData(string car, double rent, string location, int days) {
	ofstream file;
	
	file.open("rental_info.txt");

	file << "First Name: " << customer.first << endl;
	file << "Last Name: " << customer.last << endl;
	file << "Birthday: " << customer.birthday.month << " ";
	file << customer.birthday.day << " ";
	file << customer.birthday.year << endl;
	file << "License number: " << customer.license << endl;
	file << "Social Security Number: " << customer.SSN << endl;
	file << "Phone number: " << customer.phone << endl;
	file << "Car Model: " << car << endl;
	file << "Rental Price: " << rent << endl;
	file << "Pickup Location: " << location << endl;
	file << "Rental Day(s): " << days << endl;
	if (customer.birthday.year >= 1994 && customer.birthday.year <= 1998) {
		file << "Young Driver Fee: $" << yFee << endl;
		file << "Total Cost: $" << (rent * days) + yFee << endl;
	}
	else
		file << "Total Cost: $" << rent * days << endl;

	file.close();

	cout << "Data has been successfully recorded.\n";
}
