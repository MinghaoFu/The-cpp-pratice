#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <deque>

using namespace std;

	class test_emplace{
	private:
		int a;
		char b;
	public:
		test_emplace(int a, char b) {
			this->a = a;
			this->b = b;
		}
		friend ostream & operator<<(ostream & os, test_emplace & out) {
			os << "a: " << out.a << " b: " << out.b << endl;
			return os;
		}
	};

int main() {
	vector<int> a1 = {1,3,5,7};
	vector<int> a2 = {1,3,5,7,9,10};
	cout << (a1 > a2? "a1 > a2" : "a1 <= a2") << endl;
	cout << a1.size() << endl;
	cout << (a2.empty()? "true" : "false") << endl;

	string a3;
	vector<string> a4;
	while (cin >> a3) {
		a4.push_back(a3);
		cout << "a4.size(): " << a4.size() << endl;
		if (a3 == "exit") {
			break;
		}
	}

	cout << *a4.begin() << endl;

	string a5 = "Hello ";
	for (int i = 0; i < 5; i++) {
		a5.push_back('h');
	}
	cout << "a5: " << a5 << endl;

	list<int> a6;
	for (size_t i = 0; i < 5; i++) {
		a6.push_front(i);
	}

	cout << *a6.begin() << endl;
	string a7 = "Hello";
	string::iterator iter = a7.end();
	a7.insert(iter, 'W');
	cout << a7 << endl;

	vector<string> a8;
	a8.push_back("Hello");
	a8.push_back("world");
	vector<string>::const_iterator iter1 = a8.begin();
	iter1++;
	iter1 = a8.insert(iter1, "We");
	cout << *iter1 << endl;

	vector<string> a9 = {"str1", "str2", "str3"};
	a9.insert(a9.begin(), a8.begin(), a8.end());
	cout << "a9.size():" << a9.size() << endl;
	cout << "a9.begin():" << *a9.begin() << endl;
	cout << "a9.begin() + 3:" << *(a9.begin() + 3) << endl;
	cout << "a9.end() - 1:" << *(a9.end() - 1) << endl;  // Well, great! list can not

	list<string>a10;
	string str10;
	auto iter10 = a10.begin();
	while (cin >> str10) {
		if (str10 == "exit") {
			break;
		}
		iter10 = a10.insert(iter10, str10);
	}
	cout << "list<string> a10:";
	auto iter10_reverse = a10.rbegin();
	while (iter10_reverse != a10.rend()) {
		cout << " " << *iter10_reverse;
		iter10_reverse++;
	}
	cout << endl;


	vector<test_emplace> a11;
	a11.emplace_back(1, 'a');
	//a11.push_back(1, 'a'); //Wrong
	cout << *a11.begin();

	vector<int> a12 = {1,2,3,4,5};
	vector<int>::iterator iter12 = a12.begin();
	int i12;
	cin >> i12;
	while (iter12 != a12.end()) {
		if (*iter12 == i12) {
			iter12 = a12.insert(iter12, 2 * i12);
			iter12++;
		}
		iter12++;
	}
	cout << "vector<int> a12: ";
	iter12 = a12.begin();
	while (iter12 != a12.end()) {
		cout << *iter12 << " ";
		iter12++;
	}
	cout << endl;

	iter12 = a12.begin();
	iter12 = a12.erase(iter12);
	cout << "a12.at(0): " << a12.at(0) << endl;
	cout << "a12 first element: " << a12.front() << endl;
	cout << "a12 last element: " << a12.back() << endl;

	// a12.pop_front(); // pop_front not valid for vector and string
	// pop_back() not valid for forward_list
	a12.pop_back();
	cout << "a12 last element after pop_back: " << a12.back() << endl;

	a12.clear();
	a12.erase(a12.begin(), a12.end()); // equivalent
	cout << (a12.empty() ? "a12 is empty." : "a12 is not empty.") << endl;


	list<int> a13 = {1,2,3,4,5};
	a13.erase(a13.begin(), ++a13.begin());
	cout << "a13.size(): " << a13.size() << endl;

	// Exercise 9.26
	int ia[] = {0,1,2,3,5,8,13,21,55,89};
	vector<int> iav(begin(ia), end(ia));
	list<int>ial(begin(ia), end(ia));

	auto iav_iter = iav.begin();
	while (iav_iter != iav.end()) {
		if (*iav_iter % 2) {
			iav_iter = iav.erase(iav_iter);
			continue;        // Not a good method 
		}
		iav_iter++;
	}
	cout << "After removing odd values iav: ";
	for (int i = 0; i < iav.size(); i++) {
		cout << iav.at(i) << " ";
	}
	cout << endl;

	auto ial_iter = ial.begin();
	while (ial_iter != ial.end()) {
		if (!(*ial_iter % 2)) {
			ial_iter = ial.erase(ial_iter);
			
		} else {
		ial_iter++;
		}
	}
	cout << "After removing even values ial: ";
	ial_iter = ial.begin();
	while (ial_iter != ial.end()) {
		cout << *ial_iter << " ";
		ial_iter++;
	}
	cout << endl;
}
