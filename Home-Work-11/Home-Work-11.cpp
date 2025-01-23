// Home-Work-11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

// ================================ Task 1 ============================

//class Employee 
//{
//	private:
//		string name, position;
//		double salary;
//		tm date = {};
//		bool onVacation;
//	public:
//		static int count;
//
//		Employee () {
//			onVacation = false;
//			count++;
//		}
//
//		Employee(string name) {
//			this->name = name;
//			position = " ";
//			salary = 0;			
//			onVacation = false;
//			count++;
//		}
//
//		Employee(string name, string position) {
//			this->name = name;
//			this->position = position;
//			salary = 0;
//			onVacation = false;
//			count++;
//		}
//
//		Employee(string name, string position, double salary) {
//			this->name = name;
//			this->position = position;
//			this->salary = salary;
//			onVacation = false;
//			count++;
//		}
//
//		string getName() {
//			return name;
//		}
//
//		string getPosition() {
//			return position;
//		}
//
//		double getSalary() {
//			return salary;
//		}
//
//		void setName(string name) {
//			this->name = name;
//		}
//
//		void setPosition(string position) {
//			this->position = position;
//		}
//
//		void setSalary(double salary) {
//			this->salary = salary;
//		}
//
//		void Info() {
//			cout << "Name: " << name << " Position: " << position << " Salary: " << salary << endl;
//		}
//
//		static void countInfo() {
//			cout << "Counter: " << count << endl;
//		}
//	
//		double salaryIncrease(int percent) {
//			double tmp = percent / 100.0;
//			salary = salary + (salary * tmp);
//			setSalary(salary);
//			return salary;
//		}
//
//		double salaryReduction(int percent) {
//			double tmp = percent / 100.0;
//			salary = salary - (salary * tmp);
//			setSalary(salary);
//			return salary;
//		}
//
//		void setDate(int day, int month, int year) {
//			date.tm_mday = day;
//			date.tm_mon = month - 1;
//			date.tm_year = year - 1900;
//		}
//
//		void setOnVacation(bool onVacation) {
//			this->onVacation = onVacation;
//		}
//
//		int getTenure() const {
//			time_t now = time(0);
//			tm ltm = {};
//			localtime_s(&ltm, &now); 
//
//			int yearNow = 1900 + ltm.tm_year;
//			int monthNow = 1 + ltm.tm_mon;
//			int dayNow = ltm.tm_mday;
//
//			int years = yearNow - (date.tm_year + 1900);
//
//			if (monthNow < (date.tm_mon + 1) || (monthNow == (date.tm_mon + 1) && dayNow < date.tm_mday)) {
//				years--;
//			}
//
//			return years;
//		}
//
//		bool isOnVacation() {
//			return onVacation;
//		}
//};
//
//int Employee::count = 0;


//====================== Task 2 =======================

class Car {
private:
	string model, brand;
	int year, mileage;
public:
	static int count;
	
	Car() {
		count++;
	}
	Car(string model) {
		this->model = model;
		brand = " ";
		year = 0;
		mileage = 0;
		count++;
	}
	Car(string model, string brand) {
		this->model = model;
		this->brand = brand;
		year = 0;
		mileage = 0;
		count++;
	}
	Car(string model, string brand, int year) {
		this->model = model;
		this->brand = brand;
		this->year = year;
		mileage = 0;
		count++;
	}
	Car(string model, string brand, int year, int mileage) {
		this->model = model;
		this->brand = brand;
		this->year = year;
		this->mileage = mileage;
		count++;
	}

	string getModel() {
		return model;
	}

	string getBrand() {
		return brand;
	}

	int getYear() {
		return year;
	}

	int getMileage() {
		return mileage;
	}

	void setModel(string model) {
		this->model = model;
	}

	void setBrand(string brand) {
		this->brand = brand;
	}

	void setYear(int year) {
		this->year = year;
	}

	void setMileage(int mileage) {
		this->mileage = mileage;
	}

	static void countInfoCar() {
		cout << "Counter: " << count << endl;
	}

	void carInfo() const {
		cout << "Model: " << model << " Brand: " << brand << " Year: " << year << " Mileage: " << mileage << endl;
	}

	int incrCarMileage(int mile) {
		mileage += mile;
		setMileage(mileage);
		return mileage;
	}

	int calcCarAge() const {
		time_t now = time(0);
		tm ltm = {};
		localtime_s(&ltm, &now);

		int currYear = 1900 + ltm.tm_year;
		return currYear - year;
	}

	double priceReduction(int price) const {
		
		if (year < 3 || mileage < 20000) {
			double tmp = price - (price / 100.0 * 5.0);
			price = tmp;
			return price;
		}
		if ((year >= 3 && year < 7) || (mileage >= 20000 && mileage < 150000)) {
			double tmp = price - (price / 100.0 * 20.0);
			price = tmp;
			return price;
		}
		if ((year >= 7 && year < 12) || (mileage >= 150000 && mileage < 200000)) {
			double tmp = price - (price / 100.0 * 40.0);
			price = tmp;
			return price;
		}
		if (year >= 12 || mileage >= 200000) {
			double tmp = price - (price / 100.0 * 60.0);
			price = tmp;
			return price;
		}
	}

	void carCondition() const {
		if (year < 3 || mileage < 20000) {
			cout << "Condition of the car is fine." << endl;
		}
		if ((year >= 3 && year < 7) || (mileage >= 20000 && mileage < 150000)) {
			cout << "Condition of the car is good." << endl;
		}
		if ((year >= 7 && year < 12) || (mileage >= 150000 && mileage < 200000)) {
			cout << "Condition of the car is satisfactory." << endl;
		}
		if (year >= 12 || mileage >= 200000) {
			cout << "Condition of the car is bad." << endl;
		}
	}
};

int Car::count = 0;

int main()
{
    //==================== Task 1 ========================

	/*Employee obj1("Igor", "worker");
	Employee obj2("Kolya", "enjinir", 20000);
	Employee obj3("Olya", "buhgalter", 30000);
	obj1.Info();
	obj2.Info();
	cout << "Increase: " << obj2.salaryIncrease(12) << endl;
	obj2.Info();
	cout << "Reduction: " << obj3.salaryReduction(15) << endl;
	obj3.Info();
	Employee::countInfo();*/

	Car obj1("Opel", "Opel", 2015, 100000);
	Car obj2("Mazda", "Mazda", 2019, 90000);
	Car obj3("Volvo", "Volvo", 2021, 20000);
	Car obj4("Mersedes", "Bantcs", 2005, 300000);

	obj1.carInfo();

	cout << "Year: " << obj3.calcCarAge() << endl;
	obj4.carCondition();

	cout << "Price: " << obj2.priceReduction(20000) << endl;
	Car::countInfoCar();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
