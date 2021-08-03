#ifndef file1
#define file1
#include <iostream>
#include <string>

class person {
private:
	std::string name;
	double height;
	double weight;
public:
	person() {
		name = "ALA";
		height = 190.0;
		weight = 130.0;
	}
	friend std::ostream& operator<<(std::ostream &os, const person &in) {
		os << "name: " << in.name << std::endl << "height: " << in.height
		<< std::endl << "weight: " << in.weight << std::endl;
		return os;
	}
};

#endif 
