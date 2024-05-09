//Написать программу, сортирующую список телефонов по возрастанию и использующую  сортировку выбором. Телефон задан в виде строки. Например, 23-45-67.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Сравнивает две строки, представляющие телефоны, и возвращает true, если первый телефон меньше второго. 
bool comparePhones(const string& phone1, const string& phone2) 
{
  return phone1 < phone2;
}

void selectionSort(vector<string>& phones) 
{
	int n = phones.size();
	for (int i = 0; i < n - 1; i++) 
	{
		int minIndex = i;
		for (int j = i + 1; j < n; j++) 
		{
			if (comparePhones(phones[j], phones[minIndex])) 
			{
				minIndex = j;
			}
		}
		swap(phones[i], phones[minIndex]);
	}
}

int main() {
	vector<string> phones;
	phones.push_back("03-44-14");
	phones.push_back("32-64-25");
	phones.push_back("70-90-10");
	phones.push_back("15-25-35");
	phones.push_back("01-23-43");

	cout << "Исходный список телефонов: ";
	for (const auto& phone : phones) 
	{
			cout << phone << " ";
	}

	selectionSort(phones);

	cout << "\nОтсортированный список телефонов (по возрастанию): ";
	for (const auto& phone : phones) 
	{
			cout << phone << " ";
	}

	return 0;
}