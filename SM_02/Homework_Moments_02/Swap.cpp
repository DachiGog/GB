#include <iostream>
#include <string>

template<typename T>
void swap(T** a, T** b)
{
	std::string c = *b;
	*b = *a;
	*a = c;
}

int main()
{		
	std::string A = "A";
	std::string B = "B";

	std::string* swapA = new std::string();
	std::string* swapB = new std::string();

	swapA = &A;
	swapB = &B;

	std::cout << "Before Swap" << std::endl;
	std::cout << swapA << " " << A << std::endl;
	std::cout << swapB << " " << B << std::endl;
	std::cout << std::endl;

	swap(swapA, swapB);

	std::cout << "After Swap" << std::endl;
	std::cout << swapA << " " << A << std::endl;
	std::cout << swapB << " " << B << std::endl;
	std::cout << std::endl;
}