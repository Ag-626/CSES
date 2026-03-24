#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis, par;
vector<int> cycle;

bool dfs(int node, int parent) {
    vis[node] = 1;
    par[node] = parent;
    for (int nei : adj[node]) {
        // if (nei == parent) continue;

        if (vis[nei]==0) {
            // par[nei]=node;
            if (dfs(nei, node)) return true;
        } else if(vis[nei]==1){
            // cycle found: node -> nei
            cycle.push_back(nei);
            int cur = node;
            while (cur != nei) {
                cycle.push_back(cur);
                cur = par[cur];
            }
            cycle.push_back(nei);
            reverse(cycle.begin(), cycle.end());
            return true;
        }
    }
    vis[node]=2;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    adj.assign(n + 1, {});
    vis.assign(n + 1, 0);
    par.assign(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        // adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i]==0) {
            if (dfs(i, -1)) {
                cout << cycle.size() << '\n';
                for (int city : cycle) {
                    cout << city << " ";
                }
                cout << '\n';
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}