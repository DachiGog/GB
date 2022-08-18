#pragma once
#include <iostream>
#include <string>
#include <ostream>
#include <tuple>

class PhoneNumber
{
private:
	int Code, Number;
public:
	PhoneNumber() = default;
	PhoneNumber(int code, int number): Code(code), Number(number) {}
	PhoneNumber(std::tuple<int, int>& phn) { std::tie(Code, Number) = phn; }
		
	void Display();
	void Addname(int n, int s);
	
	friend std::ostream& operator<<(std::ostream& out, const PhoneNumber& p);
};

