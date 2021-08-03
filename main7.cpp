#include <iostream>

using namespace std;

using integer = int;

struct Foo {
	
};

int main() {

	integer a1(1.1f);

	cout << a1 << endl;

	const int a = 10;
	auto a2 = a; // auto ignores top-level const
	auto a3 = &a; // a3 is a pointer which points to a const int, const is kept
	cout << "a2: " << a2 << endl;
	cout << "a3: " << *a3 << endl;

	a2 = 11; // Success
	//*a3 = 11; // Wrong
	
	const auto a4 = &a; // deduced type has a top-level const
	cout << "a4: " << *a4 << endl;

	// a4 = &a2; *a4 = 11; // Wrong

	const int a5 = 10;
	auto a6 = &a5;
	a6 = a4;

	auto &a8 = a6;

	decltype(a6) a7;
	//decltype(a8) a9; // Wrong
	
	decltype((a6)) a10 = a6; // parenthesized variable is always a reference, a10 is a reference of low-level const int *
	cout << "a10: " << *a10 << endl;

}
