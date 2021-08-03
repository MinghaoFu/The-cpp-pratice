#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <array>

using namespace std;

int main() 
{
	list<string> a = {"Ala", "Fell", "Shakespeare"};
	list<const char *> b = {"John", "Sid", "Les"};

	vector<string> c(b.begin(), --b.end());
	cout << *(--c.end()) << endl;

	array<int, 10> d{1,24,4,4};
	auto e = d.begin();
	for (int i = 0; i < 3; i++)
		e++;
	cout << *e << endl;

	vector<int> f{1,2,3,4,5};
	list<double> g{5,4,3,2,1};

	array<int,10> digits = {1,2,3,4,56,7,8,9,0};
	array<int, 10> copy = digits;
	array<int, 10> digits1 = {23,3};
	digits1.swap(digits); // Must be the same type: array<int, 10>
	cout << *digits.begin() << endl;
	cout << *digits1.begin() << endl;
	digits1 = {1,23,3}; // Wrong
	array<const char *, 10> digits3 = {"hello"};
	digits3 = {"World"};
	cout << *digits3.begin() << endl;

	vector<int> h(10);
	h.assign(f.begin(), f.end());
	cout << *h.begin() << endl;

	array<int, 10> test = {0};
	test = {0}; // Wrong




}
