//Дано натуральное число n. Выведите все числа от 1 до n.
#include <iostream>
using namespace std;

void foo(int &n)
{
	if (n > 0)
	{
		cout << n << endl;
		--n;
		foo(n);
	}

}

int main(){

	int num = 8;
	foo(num);

	return 0;
}