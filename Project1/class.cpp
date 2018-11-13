#include<iostream>
using namespace std;

class base
{
public:
	void f()
	{
		cout << "base::f() called" << endl;
	}
};

class derived : public base
{
publi c:
	void f()
	{
		cout << "derived::f()called" << endl;

	}
};

int main()
{
	derived d, *pder;
	pder = &d;
	pder->f();

	base* pbase;
	pbase = pder;
	pbase->f();
}