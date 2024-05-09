//Написать программу, сортирующую список студентов группы по алфавиту и использующую стандартную сортировку qsort
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

bool compare(const string& a, const string& b) {
  return a < b;
}

int main() {
	const int numStudents = 5; 

	string students[numStudents] {
		"Чулюков Дмитрий",
		"Юргин Даниил",
		"Ипатов Никита",
		"Беляев Владимир",
		"Водопьянова Екатерина"
	};

	cout << "Исходный список студентов:\n";
	for (int i = 0; i < numStudents; i++) 
	{
		cout << students[i] << endl;
	}

	sort(students, students + numStudents, compare);

	cout << "\nОтсортированный список студентов:\n";
	for (int i = 0; i < numStudents; i++) 
	{
		cout << students[i] << endl;
	}

	return 0;
}