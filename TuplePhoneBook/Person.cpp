#include "Person.h"

void Person::AddPerson(std::string n, std::string s)
{
	Name = n;
	Surname = s;
}
std::ostream& operator<<(std::ostream& out, Person& p)
{
	return out << p.Name << " " << p.Surname;
}