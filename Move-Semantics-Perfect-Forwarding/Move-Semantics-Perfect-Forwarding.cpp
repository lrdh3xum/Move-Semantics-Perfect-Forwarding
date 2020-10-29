/*
	rvalues

		An expression is an rvalue if it results in a temporary object.

			int x;
			int getVal() { return x; }
			getVal();

		getVal() is an rvalue - the value being returned is not a reference
		to x, its just a temporary value. Not a fixed location.

		rvalue references

			Allows the binding of mutable references to an rvalue, but not an
			lvalue. rvalue references should be used to detect if a value is
			a temporary object or not. They also allow for mutable references.

	lvalues
		
		An expression whose address can be taken, provides a
		semi-permanent piece of memory. Assignments can be
		made to lvalues.

			int a;		
			a = 1	// a is an lvalue.

		lvalues do not have to be variables.

			int x;
			int& getRef() { return x; }
			getRef() = 4;

		getRef returns a reference to a global variable, returning
		a value that is stored in a permanent location.
*/

/*
	Move semantics avoid copying data from temp obejcts by
	taking the memory location where the object is stored.

	They allo an object to take ownership of some other
	object's external resources.
*/

#include <iostream>
#include <string>

/*
	Mutable references cannot be used to bind the return because it is
	a temporary object (rvalue). A non-mutable reference must be used
	because the return will fall off. Modifying an object that is about
	to disappear is dangerous.
*/
std::string getName() { return "Foo"; }

/*
	lvalue reference will accept any argument that it is given.
	rvalue reference will not except mutable rvalue references.
*/
std::string printRefL(const std::string& str) { std::cout << str; }
std::string printRefR(std::string&& str) { std::cout << str; }


int main()
{
	// lvalue reference to bind temporary object.
	const std::string& name = getName();
	// std::string& name = getName();		Will not work; must be const.
	std::cout << name << "\n\n";
	
	// C++ 11 rvalue reference
	// const std::string&& rname = getName();	Works same as lvalue &
	// rvalue allows mutable references;
	// the below will now work.
	std::string&& rname = getName();
	// Change the value of the return.
	rname = "Bar";
	std::cout << rname << "\n\n";



}