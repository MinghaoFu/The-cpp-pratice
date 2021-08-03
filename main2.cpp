#include <iostream>

using namespace std;


class Sales_data
{
private:
	string bookNo = "UNKNOWN";
	int units_sold = 0;
	double revenue = 0;
public:
	Sales_data() {}
	Sales_data(string bookNo, int a, double revenue) { 
		this->bookNo = bookNo;
		units_sold = a;
		this->revenue = revenue;
	}
	Sales_data(const Sales_data &orgi): bookNo(orgi.bookNo), units_sold(orgi.units_sold), revenue(orgi.revenue) {}
	~Sales_data() {}
};

class X 
{
public:
	X() {cout << "X()" << endl;}
	X(const X &) {cout << "X(const &)" << endl;}
	X& operator=(const X &a) {
		cout << "operator=" << endl;
		return *this;
	}
};

int main(int argc, char * argv[]) 
{
	Sales_data a;
	Sales_data b(a);

	Sales_data *e = &a;
	Sales_data *f = new Sales_data(a);
	Sales_data *g = new Sales_data;
	Sales_data c[4] = {*e, *f, *g, a};

	X h;
	X i(h);

	X k;
	X j;
	cout << sizeof(X) << endl;;
	j = k;

	
	



	delete f, g;
	return 0;	
}
