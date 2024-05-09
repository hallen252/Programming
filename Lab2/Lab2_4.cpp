//Дано натуральное число n>1. Выведите все простые делители этого числа в порядке возрастания. Алгоритм должен иметь сложность О(sqrt(n))
#include <iostream>
using namespace std;


void foo(int n, int div) {
	if (n <= 1) 
	{
		return;
	}

	if (n % div == 0) 
	{
		cout << div << " ";
		foo(n / div, div);
	} 
	else 
	{
		foo(n, div + 1);
	}
}

int main() {

	int number = 521;

	foo(number, 2);

	return 0;
}