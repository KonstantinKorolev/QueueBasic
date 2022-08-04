// lab5zad1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    queue<int> nd_queue;
    int G[4][4] = { {0, 1, 0, 0},
                    {0, 0, 0, 1},
                    {1, 0, 0, 0},
                    {0, 0, 1, 0} };
    int nd[4] = { 0, 0, 0, 0 }; // вершины графа
    // изначально все вершины не посещены
    int start = 0; // стартовая вершина
    int N = 4; // число вершин графа
    nd_queue.push(start); // помещаем в очередь стартовую вершину
    while (!nd_queue.empty())
    {
        int node = nd_queue.front(); // считываем очередную вершину из очереди
        nd_queue.pop(); // удаляем извлеченную вершину
        nd[node] = 2; // отмечаем ее как посещенную
        for (int j = 0; j < N; j++)
        {   // ищем смежные вершины отсутствующие в очереди
            if (G[node][j] == 1 && nd[j] == 0) {
                nd_queue.push(j); // добавляем ее в очередь
                nd[j] = 1; // отмечаем вершину как помещенную в очередь
            }
        }
        cout << node + 1 << endl; // выводим номер вершины
    }

    for (int i = 0; i < sizeof(nd[0]) / sizeof(nd); i++) {
        if (nd[i] == 0) {
            cout << "Граф несвязный" << endl;
            return 0;
        }
    }
    
    cout << "Граф связный" << endl;
    return 0;
}
