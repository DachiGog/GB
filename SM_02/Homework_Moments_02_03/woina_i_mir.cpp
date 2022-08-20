#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <algorithm>  
using namespace std;
bool vowels(const char ch) {
    constexpr int Size = 34;
    char arrVowels[Size] = { 'а', 'А', 'у', 'У', 'о', 'О', 'ы', 'Ы', 'и', 'И', 'э', 'Э', 'я', 'Я', 'ю', 'Ю',
        'ё', 'Ё', 'е', 'Е', 'a', 'A', 'e', 'E', 'i', 'I', 'u', 'U', 'y', 'Y', 'o', 'O', 'j', 'J' };
    for (int i = 0; i < Size; i++) {
        if (ch == arrVowels[i])
            return true;
    }
    return false;
}

int IsUpper(std::ifstream &book)
{
	return 0;
}
int count_if_and_find(const string& path) {
    ifstream fin(path, ios::in);
    size_t count = 0;
    if (fin.is_open()) {
        string str;
        string vowels = "аАуУоОыЫиИэЭяЯюЮёЁеЕaAeEiIuUyYoOjJ";
        while (!fin.eof()) {
            getline(fin, str);
            count += count_if(str.begin(), str.end(),
                [vowels](char ch) { return find(vowels.begin(), vowels.end(), ch) != vowels.end(); });
        }
    }
    else {
        cout << "file " << path << " don't open!\n";
    }
    fin.close();
    return count;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	std::string openedFile("voina-i-mir.txt");
    std::cout << count_if_and_find(openedFile);
	
}