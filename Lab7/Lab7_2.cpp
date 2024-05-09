/*
У Васи в комнате очень много коробок, которые валяются в разных местах. Васина мама хочет, чтобы он прибрался. Свободного места в комнате мало и поэтому Вася решил собрать все коробки и составить их одну на другую.

К сожалению, это может быть невозможно. Например, если на картонную коробку с елочными украшениями положить что-то железное и тяжелое, то вероятно следующий Новый год придется встречать с новыми игрушками.

Вася взвесил каждую коробку и оценил максимальный вес который она может выдержать. Помогите ему определить какое наибольшее количество коробок m он сможет составить одну на другую так, чтобы для каждой коробки было верно, что суммарный вес коробок сверху не превышает максимальный вес, который она может выдержать.

Входные данные

Первая строка входного файла содержит целое число n (1≤n≤105) - количество коробок в комнате. Каждая следующая из n строк содержит два целых числа wi и ci (1≤wi≤105,1≤ci≤109), где wi −− это вес коробки с номером i, а ci −− это вес который она может выдержать.

Выходные данные

В выходной файл выведите одно число −− ответ на задачу.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Функция для сравнения коробок по максимальному весу
bool compareBoxes(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}

int main() {
    int n;
    cout << "Enter the number of boxes: ";
    cin >> n;

    vector<pair<int, int>> boxes(n);
    for (int i = 0; i < n; ++i) {
        int weight, maxWeight;
        cout << "Enter the weight and maximum weight the box " << i + 1 << " can hold: ";
        cin >> weight >> maxWeight;
        boxes[i] = make_pair(weight, maxWeight);
    }

    sort(boxes.begin(), boxes.end(), compareBoxes);

    int currentWeight = 0;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (currentWeight + boxes[i].first <= boxes[i].second) {
            currentWeight += boxes[i].first;
            count++;
        }
    }

    cout << "The maximum number of boxes that can be stacked: " << count << endl;

    return 0;
}