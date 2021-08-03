#include <iostream>
#include "file1.h"
#include <string>

using namespace std;

class sales_data {
private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
public:
	sales_data() {
		cout << "Input data to class sales_data" << endl;
		cout << "bookNo: ";
		cin >> bookNo;
		cout << "units_sold: ";
		cin >> units_sold;
		cout << "revenue: ";
		cin >> revenue;
	}
	friend ostream& operator<<(ostream &os, const sales_data& sa) {
		os << "bookNo: " << sa.bookNo << endl;
		os << "units_sold: " << sa.units_sold << endl;
		os << "revenue: " << sa.revenue << endl;
		return os;
	}
	
};

int main() {
	const sales_data a1;
	cout << a1;	

	const person fmh;
	cout << fmh;

	//for (string str; getline(cin, str, 'a'); cout << str << endl);

	string a2 = "Hello everybody! My name is Ala, I am 12 years old.";
	decltype(a2.size()) punct = 0;
	decltype(a2.size()) letter = 0;
	decltype(a2.size()) digit = 0;
	for (auto &c : a2) {
		if (ispunct(c)) {
			punct++;
		}
		else if (isalpha(c)) {
			letter++;
		}
		else if (isdigit(c)) {
			digit++;
		}
		else {
		}
	}
	cout << "punct: " << punct << " letter: " << letter << " digit: " << digit << endl;

	string a3 = "Don't be a all-known god!";
	for (int i = 0; i < a3.size() && !isspace(a3[i]); i++) {
		a3[i] = toupper(a3.at(i));
	}
	cout << a3 << endl;

	string a4 = "Hello world";
	for (auto &c : a4) { 
		c = 'X';
	}
	cout << a4 << endl;
}
