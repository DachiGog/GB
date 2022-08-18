#include "Book.h"

void Book::CreateAddres(Person& ps, PhoneNumber& pn)
{	
		std::pair<Person, PhoneNumber> pushing(ps, pn);
		theBook.push_back(pushing);
		//std::cout << pushing.first << pushing.second << std::endl;

}
std::ostream& operator<<(std::ostream& out, Book& book)
{
	for (auto x : book.theBook)
	{
		 out << x.first << " : " << x.second << std:: endl;
		
	}
	return out;
}