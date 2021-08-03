#include <forward_list>
#include <vector>
#include <iostream>

using namespace std;

// Exercise 9.28
void insertAfterStr(forward_list<string> &vstr, const string &str1, const string &str2) {
	auto curr = vstr.begin();
	auto prev = vstr.before_begin();
	while (curr != vstr.end()) {
		if (*curr == str1) {
			vstr.insert_after(curr, str2);
			return;
		} else {
			prev = curr++;
		}
	}
	vstr.insert_after(prev, str2);
}

int main() {
	vector<int> vct = {0,1,2,3,4,5,6,7,8,9};
	vct.erase(vct.begin(), vct.begin() + 3); // Well, vector can use ".begin() + i", but list/forward_list can't, because of data structure. Therefore, vector support subscript and .at, but list do not. // .at provides a overflow warning
	for (int i = 0; i < vct.size(); i++) {
		cout << vct.at(i)  << " ";
	}
	cout << endl;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	// Remove odd values from forward_list
	forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end()) {
		if (*curr % 2) {
			curr = flst.erase_after(prev);
		} else {
			prev = curr++;
		}
	}
	curr = flst.begin();
	cout << "forward_list<int> flst after removing odd values: ";
	while (curr != flst.end()) {
		cout << " " << *curr;
		curr++;
	}
	cout << endl;

	forward_list<string> flst1{"Hello", "world"};
	insertAfterStr(flst1, "Hello", "Wuhu");
	auto iter_flst1 = flst1.begin();
	cout << "forward_list<string> flst1: ";
	while (iter_flst1 != flst1.end()) {
		cout << *iter_flst1 << " ";
		iter_flst1++;
	}
	cout << endl;

	vector<int> vct1(10, 42);
	vct1.resize(50, -1);
	cout << "vector<int> vct1: ";
	for (int i = 0; i < vct1.size(); i++) {
		cout << vct1[i] << " ";
	}
	cout << endl;
	vct1.resize(5, 1);
	cout << "vector<int> vct1: ";
	for (int i = 0; i < vct1.size(); i++) {
		cout << vct1[i] << " ";
	}
	cout << endl;



	
}
