#include "PhoneNumber.h"

std::ostream& operator<<(std::ostream& out,const PhoneNumber& p)
{
	out << p.Code << " " << p.Number;
	return out;
}
void PhoneNumber::Addname(int n, int s)
{
	Code = n;
	Number = s;
}
