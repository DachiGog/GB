#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <ostream>
#include <tuple>
#include "Person.h"
#include "PhoneNumber.h"

class Book
{
private:
	std::vector<std::pair<Person, PhoneNumber>> theBook;
public:
	void CreateAddres(Person& ps, PhoneNumber& pn);
	friend std::ostream& operator<<(std::ostream& out, Book& book);
};

