#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> topologicalSort(int V, vector<int> adj[]) {
    vector<int> in_degree(V, 0);
    for (int i = 0; i < V; i++) {
        for (int u : adj[i]) {
            in_degree[u]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> top_order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        top_order.push_back(u);

        for (int v : adj[u]) {
            if (--in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    if (top_order.size() != V) {
        cout << "Graph has a cycle!" << endl;
        return {};
    }

    return top_order;
}

int main() {
    int V = 6;
    vector<int> adj[100];

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);
    
    vector<int> result = topologicalSort(V, adj);
    
    cout << "Topological Sort: ";
    for (int i : result) {
        cout << i << " ";
    }
    
    return 0;
}
