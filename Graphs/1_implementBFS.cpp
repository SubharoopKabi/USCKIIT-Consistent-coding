#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<bool> vis(V, false);
    vector<int> ans;
    queue<int> q;
    q.push(0);
    vis[0] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        ans.push_back(curr);

        for (auto j : adj[curr]) {
            if (!vis[j]) {
                q.push(j);
                vis[j] = true;
            }
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

    vector<int> result = bfsOfGraph(V, adj);

    cout << "BFS Traversal: ";
    for (int i : result) {
        cout << i << " ";
    }

    return 0;
}
