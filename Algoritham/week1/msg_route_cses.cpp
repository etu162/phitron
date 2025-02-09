#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
vector<int> adj_list[MAX_N];
bool vis[MAX_N];
int level[MAX_N], pa[MAX_N];

void bfs(int src) {
    queue<int> q;
    q.push(src);
    level[src] = 1; // Start counting from 1 (including the starting node)
    vis[src] = true;
    pa[src] = -1; // No parent for the source

    while (!q.empty()) {
        int par = q.front();
        q.pop();

        for (int child : adj_list[par]) {
            if (!vis[child]) {
                vis[child] = true;
                level[child] = level[par] + 1;
                pa[child] = par;
                q.push(child);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));

    bfs(1); // Start BFS from node 1

    if (!vis[n]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // Output the shortest distance (number of nodes in the path)
    cout << level[n] << "\n";

    // Reconstruct the path from n to 1
    vector<int> path;
    for (int v = n; v != -1; v = pa[v]) {
        path.push_back(v);
    }

    reverse(path.begin(), path.end());

    // Print the path
    for (int node : path) {
        cout << node << " ";
    }
    cout << "\n";

    return 0;
}
