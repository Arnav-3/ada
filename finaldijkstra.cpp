#include <iostream>
#include <vector>
#include <list>
#include <utility>
using namespace std;

const int INF = 1e9;
const int MAX = 1e5;

struct destination_weight {
    int destination;
    int weight;
};
struct priority_queue 
{
    destination_weight arr[MAX];
    int size;
    
    priority_queue() 
    {
        size = 0;
    }
    
    void push(destination_weight x)
     {
        arr[size++] = x;
        int i = size - 1;
        while (i > 0 && arr[i].weight < arr[(i-1)/2].weight)
         {
            swap(arr[i], arr[(i-1)/2]);
            i = (i-1)/2;
        }
    }
    
    void pop() 
    {
        if (size == 0)
         return;
        arr[0] = arr[--size];
        int i = 0;
        while (2*i+1 < size) 
        {
            int j = 2*i+1;
            if (j+1 < size && arr[j+1].weight < arr[j].weight) 
                j++;
            if (arr[i].weight > arr[j].weight)
             {
                swap(arr[i], arr[j]);
                i = j;
             }
            else break;
        }
    }
    
    destination_weight top()
     {
        return arr[0];
    }
    
    bool empty() 
    {
        return size == 0;
    }
};

void dijkstra(int src, vector<list<destination_weight>> &adj)
{
    priority_queue pq;
    vector<int> dist(adj.size(), INF);
    pq.push({src, 0});
    dist[src] = 0;
    while (!pq.empty()) {
        int u = pq.top().destination;
        pq.pop();
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) 
        {
            int v = i->destination;
            int weight = i->weight;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({v, dist[v]});
            }
        }
    }
    for (int i = 0; i < dist.size(); ++i) {
        cout << "Distance from " << src << " to " << i << " is " << dist[i] << "\n";
    }
}

int main()
{
    int V, E;
    cout<<"ENTER NUMBER OF VERTICES AND EDGES\n";
    cin >> V >> E;
    vector<list<destination_weight>> adj(V);
    for (int i = 0; i < E; ++i)
    {
        cout<<"ENTER VALUES[source,destination,weight]\n";
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    dijkstra(0, adj);
    return 0;
}
