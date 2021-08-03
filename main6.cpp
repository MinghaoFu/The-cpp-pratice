#include <iostream>
#include <vector>

using namespace std;

//extern int i = 100;// extern define canont define within function.

constexpr int size() {
	return 2;
}

int main() {
	vector<int> a1 = {1,2,3,4,5,6};
	auto a1_begin = a1.begin(),
		a1_end = a1.end();
	// while (a1_begin() != a1_end)   a1.insert...   Wrong!Insert will invalidate a1_end
	
	vector<int> a2(10, 100);
	cout << a2[0] << endl;
	a2[101] = 11;
	cout << "Initialize a2(10, 100), evaluate a2[101], default a2[100] = 0. ";
	cout << "a2[100]: " << a2[100] << endl;;
	
	/*int a3;
	while (cin >> a3) {
		cout << a3 << endl;
	}*/
	long double a4 = 3.1415926;
	int a5(a4);
	const float a6{1.1};
	cout << "a5: " << a5 << endl; // truncate
	cout << "a6: " << a6 << endl; // curly brace initialize
	//int a6{a4}; // narrowing conversion, compiler will not let loss information with curly brace.

	//extern int i = 1; // error
	
	int *pp = nullptr;

	int a = 1;
	double b = 1.1;
	void *p = &a;
	void *q = &b; // deal memory with memory 
	cout << "p: " << p << " size: " << sizeof(a) << endl;
	cout << "q: " << q << " size: " << sizeof(b) << endl;
	cout << (p > q? "p > q" : "p <= q") << endl;

	//int &r = 0;// 0 is a rvalue, cannot bind non-const lvalue reference to it.
	const int &r = 0;// Success
	cout << "r: " << r << endl;

	constexpr double i = 1.3;
	cout << i << endl;
	constexpr int j = size();
	cout << j << endl;

	const int *p1 = nullptr; // point to a constant integer
	constexpr int *q1 = nullptr; // constant pointer

	cout << "constexpr int *q1 = nullptr: " << q1 << endl; 


	string a111 = nullptr;
	cout << a111;
	int a222 = nullptr;
	cout << a222;

	
}
