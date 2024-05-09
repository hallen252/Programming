/*Допустим, имеется лабиринт, такой, как на следующем рисунке, и мы хотим перейти от входа к выходу за наименьшее возможное количество шагов. За один шаг будем считать любой переход из одной комнаты в другую. В нашем лабиринте 11 комнат, и у каждой из них – уникальное имя, например, “A”, “B”, т.д. 
Итак, наша цель – перейти из комнаты “S” в комнату “I”. Алгоритм вычислит и выведет на экран кратчайший путь от входа в лабиринт до выхода из лабиринта. Этот путь имеет длину 4 и выглядит так: “S” -> “B” -> “C” -> “J” -> “I”.*/
#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

// Функция для поиска кратчайшего пути в лабиринте
vector<string> findShortestPath(const unordered_map<string, vector<string>>& graph, const string& start, const string& end) {
    unordered_map<string, string> parent; // Хеш-таблица для хранения родительских комнат
    queue<string> q; // Очередь для обхода в ширину
    q.push(start); // Добавляем начальную комнату в очередь

    while (!q.empty()) 
    {
        string current = q.front();
        q.pop();

        if (current == end) 
        {
            break; 
        }

        for (const string& neighbor : graph.at(current)) 
        {
            if (parent.find(neighbor) == parent.end()) 
            {
                q.push(neighbor); // Добавляем соседнюю комнату в очередь
                parent[neighbor] = current; // Запоминаем родительскую комнату
            }
        }
    }

    // Восстанавливаем кратчайший путь
    vector<string> shortestPath;
    string current = end;
    while (current != start) 
    {
        shortestPath.push_back(current);
        current = parent[current];
    }
    shortestPath.push_back(start);

    reverse(shortestPath.begin(), shortestPath.end());

    return shortestPath;
}

int main() {
    // Создаем граф лабиринта
    unordered_map<string, vector<string>> graph = {
        {"S", {"A", "B", "D", "E"}},
        {"A", {"S"}},
        {"B", {"S", "C", "D"}},
        {"C", {"B", "J"}},
        {"D", {"B", "S", "G"}},
        {"E", {"S", "G"}},
        {"F", {"G", "H"}},
        {"G", {"E", "H", "J", "F", "D"}},
        {"H", {"F", "G", "I"}},
        {"I", {"H", "J"}},
        {"J", {"C", "G", "I"}}
    };

    string start = "S";
    string end = "I";

    vector<string> shortestPath = findShortestPath(graph, start, end);

    cout << "Shortest way: " << endl << "entrance -> ";
    for (const string& room : shortestPath) 
    {
        cout << room << " -> ";
    }
    cout << "exit" << endl;

    return 0;
}