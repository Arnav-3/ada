#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int INF = 1e9;
struct Node
{
    int id, dist;
};
void dijkstra(int start, vector<pair<int, int>> *graph, int n, int *dist)
{
    bool *visited = new bool[n];
    memset(visited, false, n * sizeof(bool));
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
    }
    dist[start] = 0;
    Node startNode = {start, 0};
    Node *pq = new Node[n];
    pq[0] = startNode;
    int size = 1;
    while (size > 0)
    {
        int minDist = INF, minIndex = -1;
        for (int i = 0; i < size; i++)
        {
            if (pq[i].dist < minDist)
            {
                minDist = pq[i].dist;
                minIndex = i;
            }
        }
        Node curr = pq[minIndex];
        pq[minIndex] = pq[--size];
       if (visited[curr.id])
        {
            continue;
        }
        visited[curr.id] = true;
        for (int i = 0; i < graph[curr.id].size(); i++)
        {
            int v = graph[curr.id][i].first;
            int w = graph[curr.id][i].second;
            if (!visited[v] && dist[curr.id] + w < dist[v])
            {
                dist[v] = dist[curr.id] + w;
                Node nextNode = {v, dist[v]};
                pq[size++] = nextNode;
            }
        }
    }
    delete[] visited;
    delete[] pq;
}
int main()
{
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;
    vector<pair<int, int>> *graph = new vector<pair<int, int>>[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cout << "Enter the source, destination, and weight of edge " << i + 1 << ": ";
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    int start;
    cout << "Enter the start node: ";
    cin >> start;
    int *dist = new int[n];
    dijkstra(start, graph, n, dist);
    for (int i = 0; i < n; i++)
    {
        cout << "Shortest distance from " << start << " to " << i << " is " << dist[i] << endl;
    }
    delete[] graph;
    delete[] dist;
    return 0;
}