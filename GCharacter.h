#ifndef GCHARACTER
#define GCHARACTER
#include<iostream>
#include<string>


class GCharacter
{
	friend std::ostream& operator<<(std::ostream& os, const GCharacter& gc);

public:
	static const int DEFAULT_CAPACITY = 5;
	//constructor
	GCharacter(std::string name="John", int capacity=DEFAULT_CAPACITY);
	//Copy constructor
	GCharacter(const GCharacter& source); //constructing Gcharacter object by passing GCharacter by constant reference

	//overloaded assignment 
	//returns a references to GCharacter object 
	GCharacter& operator=(const GCharacter& sources);

	//destructor 
	~GCharacter();

	//insert a new tool into the tool holder
	void insert(const std::string& toolName);

private:
	//data members
	std::string name;
	int capacity;
	int used;
	std::string* toolHolder;

};

#endif // !GCHARACTER

