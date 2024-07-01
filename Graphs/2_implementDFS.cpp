#include <iostream>
#include <vector>

using namespace std;

void dfs(int curr, vector<int> adj[], vector<int>& vis, vector<int>& ans) {
    ans.push_back(curr);
    vis[curr] = 1;

    for (auto i : adj[curr]) {
        if (!vis[i]) dfs(i, adj, vis, ans);
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    vector<int> ans;

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, ans);
        }
    }
    return ans;
}

int main() {
    int V = 5;
    vector<int> adj[100];

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[2].push_back(0);
    adj[2].push_back(4);
    adj[3].push_back(1);
    adj[4].push_back(2);

    vector<int> result = dfsOfGraph(V, adj);

    cout << "DFS Traversal: ";
    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}
