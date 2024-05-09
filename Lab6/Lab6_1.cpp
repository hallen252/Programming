/*
Задача №1. Дейкстра

Дан ориентированный взвешенный граф. Найдите кратчайшее расстояние от одной заданной вершины до другой.

Входные данные

В первой строке содержатся три числа: N, S и F (1≤ N≤ 100, 1≤ S, F≤ N), где N – количество вершин графа, S – начальная вершина, а F – конечная. В следующих N строках вводится по N чисел, не превосходящих 100, – матрица смежности графа, где -1 означает отсутствие ребра между вершинами, а любое неотрицательное число – присутствие ребра данного веса. На главной диагонали матрицы записаны нули.

Выходные данные

Требуется вывести искомое расстояние или -1, если пути между указанными вершинами не существует.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

// Функция для нахождения кратчайшего расстояния
int shortestDistance(vector<vector<int> >& graph, int start, int end) {
    int n = graph.size();
    vector<int> distance(n, INT_MAX); // Инициализация расстояний как бесконечность
    distance[start] = 0; // Расстояние от начальной вершины до самой себя равно 0

    // Создание очереди с приоритетом для обработки вершин
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) 
    {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        // Если достигнута конечная вершина, возвращаем расстояние
        if (u == end) 
        {
            return dist;
        }

        // Перебираем соседние вершины
        for (int v = 0; v < n; v++) 
        {
            // Если есть ребро между u и v
            if (graph[u][v] != -1) 
            {
                int newDist = dist + graph[u][v];
                // Если новое расстояние меньше текущего расстояния до v, обновляем его
                if (newDist < distance[v]) 
                {
                    distance[v] = newDist;
                    pq.push(make_pair(newDist, v));
                }
            }
        }
    }

    // Если пути между указанными вершинами не существует, возвращаем -1
    return -1;
}

int main() {
    int N = 0;
    cout << "Amount of graph's vertexes ";
    cin >> N;
    
    int S = 0;
    cout << "Vertex Start ";
    cin >> S;
    
    int F = 0;
    cout << "Vertex Finish ";
    cin >> F;
  
    vector<vector<int> > graph(N, vector<int>(N));
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            cin >> graph[i][j];
        }
		cout << endl;
    }

    int shortestDist = shortestDistance(graph, S - 1, F - 1);
    cout << shortestDist << endl;

    return 0;
}