//Даны два целых числа A и В (каждое в отдельной строке). Выведите все числа от A до B включительно, в порядке возрастания, если A < B, или в порядке убывания в противном случае
#include <iostream>
using namespace std;

void foo(int &a, int &b)
{
	if (a < b)
	{
		if (a < b)
		{
			cout << a << endl;
			a++;
			foo(a, b);
		}
	
	}
	else if (a > b)
	{
		if (a > b)
		{
			cout << a << endl;
			a--;
			foo(a, b);
		}
	}
	else
	{
		cout << a << endl;
	}
	
}

int main(){

	int a = 15;
	int b = 15;
	
	foo(a, b);

	return 0;
}