#include "GCharacter.h"

using namespace std;

GCharacter::GCharacter(std::string name, int capacity)
{
	this->name = name;
	this->capacity = capacity;
	used = 0;
	toolHolder = new string[capacity];
}

GCharacter::GCharacter(const GCharacter & source)
{
	cout << "Copy constructor called. " << endl;
	this->name = source.name;
	this->capacity= source.capacity;
	used = source.used;
	toolHolder = new string[source.capacity]; //creating a string array and passing it to tool holder to avoid shallow copying
	//copy function from standard template library
	copy(source.toolHolder, source.toolHolder + used, toolHolder);

	/*for (int i = 0; i < used; i++)
	{
		toolHolder[i] = source.toolHolder[i];
	}*/
}

//Overloaded assignment operator
GCharacter & GCharacter::operator=(const GCharacter & source)
{
	cout << "Overloaded assignment called. " << endl;
	//check for self assignment: gc1=gc1
	if (this == &source) //check if what is on RHS==LHS
	{
		return *this; //here, it returns GCharacter object 
	}
	this->name = name;
	this->capacity = capacity;
	used = source.used;
	toolHolder = new string[source.capacity];

	copy(source.toolHolder, source.toolHolder + used, toolHolder);

	return *this;

}

//destructor
GCharacter::~GCharacter()
{
	cout << "Destructor called for " << this->name
		<< " @this memory location " << this << endl;

	delete [] toolHolder;
}


//for inserting new tool to toolHolder
void GCharacter::insert(const std::string & toolName)
{
	if (used == capacity)
	{
		cout << "Tool is full. cannot add any additional tools " << endl;
	}
	else
	{
		toolHolder[used] = toolName;
		used++;
	}
}


std::ostream& operator<<(std::ostream& os, const GCharacter& gc)
{
	os << "Game character " << gc.name
		<< "\n has the following tools: " << std::endl << "| ";
	for (int i = 0; i < gc.used; i++)
	{
		os << gc.toolHolder[i] + "| ";

	}
	return os << std::endl; //return ostream object specified by os
}