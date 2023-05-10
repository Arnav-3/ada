#include <bits/stdc++.h>
using namespace std;
#define N 7
#define INF INT_MAX

int msg(int graph[N][N])
{
    int dis[N];
    int path[N];
    dis[N - 1] = 0;
    path[N-1]=N - 1;
    for (int i = N - 2; i >= 0; i--)
    {
        dis[i] = INF;
        for (int j = i; j < N; j++)
        {
            if (graph[i][j] == INF)
                continue;
            else if (dis[i] > graph[i][j] + dis[j])
            {
                dis[i] = graph[i][j] +dis[j];
                path[i] = j;
            }
        }
    }
   int current = 0;
    cout << "Shortest path: ";
    while (current != N - 1)
    {
        cout << current + 1 << " -> ";
        current = path[current];
    }
    cout << N << endl;

    return dis[0];
}

int main()
{

    int graph[N][N] =
        {
            {INF, 5, 3, 1, INF, INF, INF},
            {INF, INF, INF, INF, 9, INF, INF},
            {INF, INF, INF, INF, 1, 10, INF},
            {INF, INF, INF, INF, INF, 10, INF},
            {INF, INF, INF, INF, INF, INF, 3},
            {INF, INF, INF, INF, INF, INF, 2},
            {INF, INF, INF, INF, INF, INF, INF}};

    cout << msg(graph);
    return 0;
}

