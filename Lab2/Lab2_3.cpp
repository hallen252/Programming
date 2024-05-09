//Дано натуральное число N. Вычислите сумму его цифр. При решении этой задачи нельзя использовать строки, списки, массивы (ну и циклы, разумеется).
#include <iostream>
using namespace std;

int sum = 0;

void foo(int &n)
{

	if (n > 0)
	{
		sum = sum + n%10;
		n = n / 10;
		foo(n);
	}
	else
	{
		cout << sum << endl;
	}
	
}

int main(){
	
	int n_num = 8;
	foo(n_num);

	return 0;
}