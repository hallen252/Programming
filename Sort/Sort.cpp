#include <iostream>
#include <cstdlib>

using namespace std;

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n, arr[100];
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements in the array:\n";
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 102 + 2; 
        cout << arr[i] << " ";
    }
    cout << "\n";
    selectionSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}