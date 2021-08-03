#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <deque>
#include <list>
#include <sstream>

using namespace std;

class nodecon {
private:
	int a;
public:
	nodecon(int a) {this->a = a;}
	friend ostream & operator<<(ostream & os, nodecon n) {
		os << n.a;
		return os;
	}
};

int main() {
	list<int> a1 = {1,2,3,4,5};
	//cout << *(a1.begin() + 3) << endl; // Wrong
	auto iter1_a1 = a1.begin();
	iter1_a1++; // iter1_a1 += 3, wrong
	cout << "After iter1_a1++: " << *iter1_a1 << endl; // Success
	vector<int> c(10);
	cout << c[0] << endl;
	vector<nodecon> a(10, 2);
	cout << a[0] << endl;
	list<deque<int>> s;
	
	list<string> g = {"Million", "Shakespeare", "Austen"};
	auto h = g.begin();
	cout << *h << endl;
	auto i = g.cbegin();
	cout << *i << endl;
	//*i = "Waibibabu"; //Wrong
	auto j = g.rbegin(); // list<string>::reverse_iterator j
	j++; // OK
	cout << *(--j) << endl;
	*j = "Allen"; // OK
	cout << *j << endl;
	auto k = g.crbegin();
	cout << *k << endl;
	//*k = "dfdfs"; // Wrong
	
	


	return 0;

	// Find integer by iterator
	int b;
	string str;
	cout << "Input vector: ";
	getline(cin, str);
	istringstream iss(str);
	vector<int> d;
	while (iss >> b) 
		d.push_back(b);

	cout << "Input interal value: ";
	cin >> b;
	vector<int>::iterator iter1 = d.begin();
	vector<int>::iterator iter2 = d.end();
	cout << true << endl;

}
