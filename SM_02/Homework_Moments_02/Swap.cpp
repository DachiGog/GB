#include <iostream>
#include <string>

template<typename T>
void swap(T* a, T* b)
{
	std::string c = *b;
	*b = *a;
	*a = c;
}

int main()
{		
	std::string* swapA = new std::string("A");
	std::string* swapB = new std::string("B");
	std::cout << *swapA << " " << *swapB <<std::endl;
	swap(swapA, swapB);
	std::cout << *swapA << " " << *swapB << std::endl;
}