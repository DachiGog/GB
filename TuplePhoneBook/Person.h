#pragma once
#include <iostream>
#include <string>
#include <ostream>
#include <tuple>


class Person
{
private:
	std::string Name, Surname;
public:
	Person(std::string name="", std::string surname="") : Name(name), Surname(surname){}
	Person(std::tuple<std::string, std::string>& pers) { tie(Name, Surname) = pers; }

	void AddPerson(std::string n, std::string s);
	friend std::ostream& operator<<(std::ostream& out, Person& p);
};

