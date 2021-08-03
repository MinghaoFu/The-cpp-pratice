#include <iostream>	
#include <vector>
#include <memory>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class test {
private:
	int a;
	string b;
public:
	test(int a, string b) {
		this->a = a;
		this->b = b;
	}
	test operator=(test in) {
		this->a = in.a;
		this->b = in.b;
		return *this;
	}
	test operator+(test in) {
		return test(a + in.a, b + in.b);
	}
	friend ostream &operator<<(ostream &os, test in) {
		os << "a = " << in.a << " b = " << in.b;
		return os;
	}
	friend istream &operator>>(istream &is, test & out) {
		if (is)
			is >> out.a >> out.b;
		else 
			cout << "istream wrong." << endl;
		return is;
	}
	bool operator==(const test &in) {
		return a == in.a && b == in.b;
	}
	bool operator!=(const test &in) {
		return !(*this == in);
	}
	const char operator[](size_t n) {
		return b[n];
	}
	test& operator++() {
		++a;
		return *this;
	}
	test& operator--() {
		--a;
		b.erase(b.end() - 1);
		return *this;
	}
	test operator++(int) {
		test ret = *this;
		++*this;
		return ret;
	}
	test operator--(int) {
		test ret = *this;
		--*this;
		return ret;
	}
	bool operator>(test &in) const {
		return a > in.a && b > in.b;
	}
	bool operator<(test &in) const {
		return a < in.a && b < in.b;
	}
	bool operator()(test f, test s) {
		return f.a > s.a && f.b > s.b;
	}
	void func1() {
		cout << "Base" << endl;
	}
	virtual void func2() {
		cout << "Base" << endl;
	}
	virtual ~test() = default;
};

class derivedTest : public test {
private:
	char derived;
public:
	derivedTest(int a, string str, char c): test(a, str) {derived = c;};
	void func2() {
		cout << "Binding in runtime, in accordance with the content of pointer, Derived" << endl;
	}
	void func1() {
		cout << "Binding in compile time, in accordance with the type of pointer, Derived" << endl;
	}
};

void printVector(vector<int> v) 
{
	for_each(v.begin(), v.end(), [](int i) {
		cout << i << " ";
	});
	cout << endl;
} // lambda

class Smallint {
private:
	size_t val;
public:
	Smallint(int i = 0): val(i) {
		if (i < 0 || i > 255) {
			throw out_of_range("Bad Smallint value");
		}
	}
	explicit operator int () const {
		return val;
	}
	int operator()() const  {
		return val;
	}
};




int main()
{
	test a(10, "Hello");
	test b(a);
	cin >> a;
	cout << a << endl;
	b = a;
	cout << b << endl;
	cout << b[1] << endl;
	test c = b--;
	cout << b(a, c) << endl;
	vector<int> d = {1,2,323,2};
	printVector(d);
	auto mod = [](int i, int j) {return i % j;};
	auto add = [](int i, int j) {return i + j;};
	function<int(int, int)> f1 = add;
	function<int(int, int)> f2 = [](int i, int j) {return i * j;};
	cout << f1(2,3) << endl;
	cout << f2(3,534) << endl;
	map<string, function<int(int, int)>> binops = {
		{"+", f1},{"*", f2},{"%", mod} 
	};
	cout << binops["+"](10, 5) << endl;
	Smallint g;
	//Smallint h(300);
	cout << g() << endl;
	cout << static_cast<int>(g) + 5 << endl;
	float ab = 1.2;
	int cd = static_cast<int>(ab);
	
	test abc(12, "fsefd");
	derivedTest cde(100, "world", 'a');
	abc = cde;

	test base(100, "wqeaewq");
	derivedTest derived(200, "aswde", 'b');
	test *zxc = &derived;
	zxc->func1();
	zxc->func2();

	test *p =  new test(12, "e231");
	delete p;
	p = new derivedTest(121, "sa", 'a');
	delete p;

	return 0;
}
