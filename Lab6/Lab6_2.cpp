/*
Задача №2. Заправки

В стране N городов, некоторые из которых соединены между собой дорогами. Для того, чтобы проехать по одной дороге, требуется один бак бензина. В каждом городе бак бензина имеет разную стоимость. Вам требуется добраться из первого города в N-ый, потратив как можно меньшее денег. Покупать бензин впрок нельзя.

Входные данные

В первой строке вводится число N (1≤N≤100), в следующей строке идет N чисел, i-ое из которых задает стоимость бензина в i-ом городе (всё это целые числа из диапазона от 0 до 100). Затем идет число M – количество дорог в стране, далее идет описание самих дорог. Каждая дорога задается двумя числами – номерами городов, которые она соединяет. Все дороги двухсторонние (то есть по ним можно ездить как в одну, так и в другую сторону), между двумя городами всегда существует не более одной дороги, не существует дорог, ведущих из города в себя.

Выходные данные

Требуется вывести одно число – суммарную стоимость маршрута или -1, если добраться невозможно.


*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of cities (N): ";
    cin >> n; // Считываем количество городов

    vector<int> cost(n);
    cout << "Enter the cost of fuel in each city: ";
    for (int i = 0; i < n; ++i) 
    {
        cin >> cost[i]; // Считываем стоимость бензина в каждом городе
    }

    int m;
    cout << "Enter the number of roads (M): ";
    cin >> m; // Считываем количество дорог

    // Создаем граф смежности для представления связей между городами
    vector<vector<int>> graph(n);
    cout << "Enter the numbers of cities connected by roads:" << endl;
    for (int i = 0; i < m; ++i) 
    {
        int u, v;
        cin >> u >> v; // Считываем номера городов, соединенных дорогой
        graph[u - 1].push_back(v - 1); // Добавляем связь между городами (уменьшаем на 1, так как индексация с 0)
        graph[v - 1].push_back(u - 1); // Добавляем обратную связь (дороги двусторонние)
    }

    // Инициализируем массив минимальных стоимостей бензина для каждого города
    vector<int> minCost(n, INT_MAX);
    minCost[0] = 0; // Стоимость начального города равна 0

    // Используем алгоритм поиска в ширину (BFS) для нахождения кратчайшего пути
    queue<int> q;
    q.push(0); // Добавляем начальный город в очередь

    while (!q.empty()) 
    {
        int u = q.front();
        q.pop();

        // Обходим все города, соединенные с текущим
        for (int v : graph[u]) 
        {
            // Если найден более дешевый путь до города v
            if (minCost[v] > cost[v] + minCost[u]) 
            {
                minCost[v] = cost[v] + minCost[u]; // Обновляем стоимость пути до города v
                q.push(v); // Добавляем город v в очередь для дальнейшего исследования
            }
        }
    }

    // Выводим минимальную стоимость маршрута или -1, если добраться невозможно
    if (minCost[n - 1] == INT_MAX) 
    {
        cout << "Minimum route cost: -1" << endl;
    }
    else 
    {
        cout << "Minimum route cost: " << minCost[n - 1] << endl;
    }

    return 0;
}