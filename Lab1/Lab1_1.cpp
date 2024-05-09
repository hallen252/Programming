//Написать программу, сортирующую по возрастанию одномерный массив случайных целых чисел, находящихся в интервале {2,103}. Использовать сортировку выбором. 
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++) 
		{
        int minIndex = i;
        for (int j = i + 1; j < size; j++) 
		{
            if (arr[j] < arr[minIndex]) 
			{
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}


int main() {
    // Установка генератора случайных чисел на основе текущего времени
    srand(static_cast<unsigned int>(time(nullptr)));

    const int size = 10;
    int arr[size]; 

    // Заполнение массива случайными числами в заданном интервале
    for (int i = 0; i < size; i++) 
		{
        arr[i] = rand() % 102 + 2;
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) 
		{
        cout << arr[i] << " ";
    }
    cout << endl;

    selectionSort(arr, size);

    cout << "Отсортированный массив: ";
    for (int i = 0; i < size; i++) 
		{
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}