//Написать программу, сортирующую по возрастанию одномерный массив случайных целых чисел, находящихся в интервале {50,100}. Использовать быструю сортировку

#include <iostream>
using namespace std;

// Функция для обмена двух элементов
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

// Функция для разделения массива и возврата индекса опорного элемента
int partition(int arr[], int low, int high) {

	int pivot = arr[high];  // Опорный элемент
	int i = (low - 1);  // Индекс меньшего элемента

	for (int j = low; j <= high - 1; j++) 
	{
		if (arr[j] <= pivot) 
		{
			i++;
			swap(arr[i], arr[j]);
		}	
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}


// Функция быстрой сортировки
void quickSort(int arr[], int low, int high) {
	
	if (low < high) 
	{
		// Получаем индекс опорного элемента
		int pi = partition(arr, low, high);

		// Рекурсивно сортируем элементы перед опорным и после него
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}

}

int main() {
	
	int arr[10];

	for (int i = 0; i < 10; i++) 
	{
		arr[i] = rand() % 51 + 50;
	}

	quickSort(arr, 0, 9);

	for (int i = 0; i < 10; i++) 
	{
		cout << arr[i] << " ";
	}

	return 0;
}