#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <functional>
#include <optional>
#include <vector>

using namespace std;

class Person
{
private:
protected:
public:
	std::string Surname, Name;
	optional<string> fathersName;
	Person(string name = "", string surname = "", optional<string>fathersname = "") : Name(name), Surname(surname), fathersName(fathersname) {}
	Person(tuple<string, string, string>& psn) { tie(Name, Surname, fathersName) = psn; }

	friend std::ostream& operator <<(std::ostream& out, const Person& p);
};
std::ostream& operator <<(std::ostream& out, const Person& p)
{
	out.setf(ios::left);
	if(p.fathersName != nullopt)
		out << p.Name << " " << p.Surname << " " << *p.fathersName << "\t";
	else
		out << p.Name << " " << p.Surname << "\t";
	return out;
}

class PhoneNumber
{
private:
protected:
public:
	int CountryCode, TownCode;
	string Number;
	optional<int> AddNumber;
	PhoneNumber(int c_code=0, int t_code=0, string number="", optional<int> add_n=0) : CountryCode(c_code), TownCode(t_code), Number(number), AddNumber(add_n) {}
	PhoneNumber(tuple<int, int, string, optional<int>>& phn) { tie(CountryCode, TownCode, Number, AddNumber) = phn; }

	friend std::ostream& operator <<(std::ostream& out, const PhoneNumber& pn);
};
std::ostream& operator <<(std::ostream& out, const PhoneNumber& pn)
{
	if (pn.AddNumber != nullopt)
		out << "+" << pn.CountryCode << "(" << pn.TownCode << ")" << pn.Number << " " << *pn.AddNumber << endl;
	else
		out << "+" << pn.CountryCode << "(" << pn.TownCode << ")" << pn.Number << endl;
	return out;
}

class PhoneBook 
{
private:	
	vector<pair<Person, PhoneNumber>> phone_base;
public:
	PhoneBook(ifstream& PB) 
	{ 
		if (PB.is_open())
		{			
			string str;
			Person p;
			PhoneNumber pn;
			while (!PB.eof())
			{
				getline(PB, str);
				size_t pos = 0;
				size_t count = 0;
				count = str.find(" ", pos);
				p.Name = str.substr(pos, count);
				pos = count + 1;
				count = str.find(" ", pos);
				p.Surname = str.substr(pos, count - pos);
				pos = count + 1;
				count = str.find(" ", pos);
				if (str.substr(pos, count - pos) != "-")
					p.fathersName = str.substr(pos, count - pos);
				else
					p.fathersName = nullopt;
				pos = count + 1;
				count = str.find(" ", pos);
				pn.CountryCode = stoi(str.substr(pos, count - pos));
				pos = count + 1;
				count = str.find(" ", pos);
				pn.TownCode = stoi(str.substr(pos, count - pos));
				pos = count + 1;
				count = str.find(" ", pos);
				pn.Number = str.substr(pos, count - pos);
				pos = count + 1;
				
				if (str.substr(pos) != "-")
					pn.AddNumber = stoi(str.substr(pos));
				else
					pn.AddNumber = nullopt;

				pair<Person, PhoneNumber> pushing(p, pn);
				phone_base.push_back(pushing);
			}
		}
		else
		cout << "File cant be open\n";
		PB.close();
	};
	friend ostream& operator <<(ostream& out, const PhoneBook& pb);
};
ostream& operator <<(ostream& out, const PhoneBook& pb)
{
	for (auto& pnb : pb.phone_base)
	{
		out << pnb.first << pnb.second;
	}
	return out;
}

int main()
{
	ifstream file("PhoneBook.txt"); 
	PhoneBook book(file);

	cout << book;
	//cout << "------SortByPhone-------" << endl;
	//book.SortByPhone();
	//cout << book;
	//cout << "------SortByName--------" << endl;
	//book.SortByName();
	//cout << book;
	//cout << "-----GetPhoneNumber-----" << endl;

	/*	auto print_phone_number = [&book](const string& surname)
	{
		cout << surname << "\t";
		auto answer = book.GetPhoneNumber(surname);
		if (get<0>(answer).empty())
			cout << get<1>(answer);
		else
			cout << get<0>(answer);
		cout << endl;
	};

	print_phone_number("Ivanov");
	print_phone_number("Petrov");
	cout << "----ChangePhoneNumber----" << endl;
	book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" },
		PhoneNumber{ 7, 123, "15344458", nullopt });
	book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" },
		PhoneNumber{ 16, 465, "9155448", 13 });
	cout << book;*/
}