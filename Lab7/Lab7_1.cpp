/*
Дана лекционная аудитория, в которой несколько профессоров хотят прочесть свои лекции. Для составления расписания профессора подали заявки, вида [si,fi) – время начала и конца лекции. Лекция считается открытым полуинтервалом, то есть какая-то лекция может начаться в момент окончания другой, без перерыва. Составьте расписание занятий так, чтобы выполнить максимальное количество заявок.

Входные данные

В первой строке вводится натуральное число N, не более 1000 – общее количество заявок. Затем вводится N строк с описаниями заявок - по два числа в каждом si и fi.

Гарантируется, что si<fi<. Время начала и окончания лекции – натуральное число, не превышает 1440 (в минутах с начала суток :) )

Выходные данные

Выведите одно число – максимальное количество заявок, которые можно выполнить.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool compareLectures(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}
// Функция для определения максимального количества заявок, которые можно выполнить
int maxLectures(vector<pair<int, int>>& lectures) {
    
    sort(lectures.begin(), lectures.end(), compareLectures);
    int count = 1; 
    int currentEnd = lectures[0].second; 
    for (int i = 1; i < lectures.size(); ++i) 
    {
        if (lectures[i].first >= currentEnd) 
        {
            count++; 
            currentEnd = lectures[i].second;  
        }
    }
    return count; 
}


int main() {
    int N;
    cout << "Enter the number of lectures: ";
    cin >> N; 
    vector<pair<int, int>> lectures(N);
    cout << "Enter the start and end time for each lecture in the format \"start_time end_time\":" << endl;
    for (int i = 0; i < N; ++i) 
    {
        cout << "Lecture " << i + 1 << ": ";
        cin >> lectures[i].first >> lectures[i].second; 
    }
    cout << "The maximum number of lectures that can be scheduled: " << maxLectures(lectures) << endl; 
    return 0;
}