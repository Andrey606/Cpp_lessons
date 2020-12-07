// constexpr.cpp
// Compile with: cl /EHsc /W4 constexpr.cpp
#include <iostream>

using namespace std;

class obg
{
public:
	obg(){cout << "constructor obj" << endl;}
	virtual ~obg(){cout << "destructor obj" << endl;}
};

class next_obg: public obg
{
public:
	next_obg(){cout << "constructor next_obg" << endl;}
	~next_obg() override {cout << "destructor next_obg" << endl;}
};

int main()
{
	obg *tmpObj = new next_obg();

	delete tmpObj;

	return 0;
}