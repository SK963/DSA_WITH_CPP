

#include <iostream>
using namespace  std;

class Base 
{
public:
	virtual void someFunction() 
	{
		cout<<"Base::somefunction() called"<<endl;
	}

	static Base* createObject(int type);
};

class Derived1 : public Base 
{
public:
	void someFunction() 
	{
		cout<<"Derived1::somefunction() called"<<endl;
		// Derived1 class implementation
	}
};

class Derived2 : public Base 
{
public:
	void someFunction() 
	{
		cout<<"Derived2::somefunction() called"<<endl;
		// Derived2 class implementation
	}
};

Base* Base::createObject(int type) 
{
	if (type == 1)
		return new Derived1();
	else if (type == 2)
		return new Derived2();
	else if(type == 3)
		return new Base();
	return nullptr;
}


int main()
{
	Base* obj1 = Base::createObject(1);
	Base* obj2 = Base::createObject(2);
	Base* obj3 = Base::createObject(3);
	
	obj1->someFunction();
	obj2->someFunction();
	obj3->someFunction();

}