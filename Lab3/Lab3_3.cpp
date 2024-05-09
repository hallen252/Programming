//Написать программу, сортирующую по возрастанию первый столбец двумерного массива целых чисел. Использовать быструю сортировку Массив создать из случайных чисел, расположенных в интервале {5,61}
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Функция быстрой сортировки
void quickSort(int arr[][2], int left, int right) {
    int i = left;
    int j = right;
    int pivot = arr[(left + right) / 2][0]; // Опорная точка (первый столбец)

    // Разделение массива на две части
    while (i <= j) 
    {
        while (arr[i][0] < pivot) 
        {
            i++;
        }
        while (arr[j][0] > pivot) 
        {
            j--;
        }
        if (i <= j) 
        {
            // Обмен элементов
            int temp1 = arr[i][0];
            int temp2 = arr[i][1];
            arr[i][0] = arr[j][0];
            arr[i][1] = arr[j][1];
            arr[j][0] = temp1;
            arr[j][1] = temp2;
            i++;
            j--;
        }
    }

    // Рекурсивный вызов для левой и правой части массива
    if (left < j) 
    {
        quickSort(arr, left, j);
    }
    if (i < right) 
    {
        quickSort(arr, i, right);
    }
}

int main() {
    const int rows = 10; 
    const int cols = 2; 

    int arr[rows][cols]; 

    // Инициализация генератора случайных чисел
    srand(time(0));

    // Заполнение массива случайными числами в интервале от 5 до 61
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            arr[i][j] = rand() % 57 + 5;
        }
    }

    // Вывод исходного массива
    cout << "Исходный массив:\n";
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Сортировка первого столбца массива по возрастанию
    quickSort(arr, 0, rows - 1);

    // Вывод отсортированного массива
    cout << "\nОтсортированный массив:\n";
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}