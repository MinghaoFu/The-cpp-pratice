#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <bitset>

using namespace std;

constexpr int factorical(int n) {
	return n > 0 ? n * factorical(n - 1) : 1;
}

int main() {
	int a = -1;
	cout << a << endl;

	int a1[] = {1,2,3,4,5,6};
	int *a2 = &a1[2];
	int *a3 = &a2[2];
	cout << *a3 << endl;
	cout << *(a3 - 2) << endl;
	
	const char a4[] = "Hello"; // c-style string
	const char *p = a4;// low-level
	while (*p) {
		cout << *p;
		p++;
	}
	cout << endl;

	int i = factorical(3);
	cout << i << endl;

	cout << *begin(a1) << endl;

	cout << typeid(a3).name() << endl;

	const size_t rowCnt = 3, colCnt = 4;
	int a5[rowCnt][colCnt];
	for (size_t i = 0; i < rowCnt; i++) {
		for (size_t j = 0; j < colCnt; j++) {
			a5[i][j] = (i + 1) * 10 + j + 1;
		}
	}

	for (auto p = a5; p != a5 + rowCnt; ++p) {
		for (auto q = *p; q != *p + colCnt; ++q) {
			cout << *q << " ";
		}
		cout << endl;
	}

	using int_array = int[4];
	typedef int int_array[4];

	int_array a7 = {a5[0][0], a5[0][1], a5[0][2], a5[0][3]};
	cout << typeid(a7).name()  << endl;
	for (auto &ele : a7) 
		cout << ele << " ";
	cout << endl;

	vector<int> a6(10);
	cout << a6[9] << endl; // a[10] overflow
	
	int ival, *ptr;
	//ival = ptr = 0; // Wrong, cannot convert a pointer to integer

	int i1 = 0, j1 = 1;
	if (i1 = j1) 
		cout << "i = j!" << endl;// test assignment result

	//*beg = toupper(*beg++); // Wrong, compiler might evaluate this expression as either

	if (a6[i1++] == a6[i1]) 
		cout << "!" << endl; // error, undefined behavior
	
	string s1 = "Hello world", *p1 = &s1;
	cout << s1.size() << endl;
	cout << p1->size() << endl;

	int grade = 75;
	string finalGrade = (grade > 90) ? "execellent" : (grade > 60) ? "pass" : "fail";
	cout << finalGrade << endl;

	cout << ((grade > 90) ? "excellent" : (grade > 60) ? "pass" : "fail") << endl;

	vector<int> ivec({1,2,3,4,5,6});
	for (auto &i : ivec) {
		cout << ((i & 0x1) ? i * 2 : i) << " ";
	}
	cout << endl;

	unsigned char bits = 0227;
	bits << 8;
	!bits;
	unsigned char bits1 = 0225;
	bits & bits1;
	1 << 27;
	1;
	cout << (1 << 2) << endl;
	cout << hex << (int)bits << endl;
	cout << (int)(bits&bits1) << endl;
	
	cout << sizeof(ulong) << endl;
	cout << sizeof(size_t) << endl;
	cout << sizeof a6 << endl;
	
	constexpr size_t size = sizeof(a5)/sizeof(*a5);
	cout << size << endl;

}

