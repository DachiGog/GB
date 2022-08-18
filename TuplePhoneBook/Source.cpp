#include "PhoneNumber.h"
#include "Person.h"
#include "Book.h"

int main()
{
	Person psn;
	PhoneNumber pn;
	Book bk;

	psn.AddPerson("Jack", "Muslus");
	pn.Addname(34, 800900);
	bk.CreateAddres(psn, pn);

	psn.AddPerson("Fart", "bart");	
	pn.Addname(45, 566255);
	bk.CreateAddres(psn, pn);

	psn.AddPerson("sus", "among");
	pn.Addname(45, 7878787);
	bk.CreateAddres(psn, pn);
	
	std::cout << bk;
}