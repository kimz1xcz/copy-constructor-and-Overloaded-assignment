
#include"GCharacter.h"

using namespace std;

GCharacter exCopyConstructor(GCharacter tempGC)
{
	cout << "Copy constructor called twice. " << endl;
	cout << "Once for the formal parameter being passed by value" << endl;
	cout << "Once for the return value. " << endl;

	return tempGC;
}

int main()
{
	
	GCharacter gc1;
	gc1.insert("potion");
	gc1.insert("crossbow");
	gc1.insert("candle");
	gc1.insert("cloak");
	gc1.insert("sword"); 
	

	cout << gc1 << endl;

	GCharacter gc2("Bob", 5);

	gc2.insert("axe");


	exCopyConstructor(gc2);

	//copy constructor
	GCharacter gc3 = gc2;

	//Overloaded assignment 
	gc2 = gc1;

	cout << endl;
	cout << "gc2: " << gc2 << endl;
	cout << "gc1: " << gc1 << endl;
	cout << "gc3: " << gc3 << endl;

	cin.get();
	return 0;
}