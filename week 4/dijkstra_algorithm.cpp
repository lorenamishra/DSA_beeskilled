
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void dijkstra(int n, vector<pair<int, int>> adj[], int src) {

    vector<int> dist(n, INT_MAX);

    priority_queue<pair<int, int>,
                   vector<pair<int, int>>,
                   greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {

        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (d > dist[node])
            continue;

        for (auto edge : adj[node]) {

            int neighbour = edge.first;
            int weight = edge.second;

            if (dist[node] + weight < dist[neighbour]) {

                dist[neighbour] = dist[node] + weight;

                pq.push({dist[neighbour], neighbour});
            }
        }
    }

    cout << "\nShortest distances from source " << src << ":\n";

    for (int i = 0; i < n; i++) {

        cout << "Vertex " << i << " : ";

        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }
}

int main() {

    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    vector<pair<int, int>> adj[n];

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < e; i++) {

        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int src;

    cout << "Enter source vertex: ";
    cin >> src;

    dijkstra(n, adj, src);

    return 0;
}
