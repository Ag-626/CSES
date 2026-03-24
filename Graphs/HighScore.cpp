#include <bits/stdc++.h>
using namespace std;

#define int long long
const long long INF = (1LL << 60);

struct Edge {
    int a, b, w;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    vector<vector<int>> revAdj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b, x;
        cin >> a >> b >> x;

        edges.push_back({a, b, -x}); // negate weight
        revAdj[b].push_back(a);      // reverse graph for reachability to n
    }

    // Find which nodes can reach n
    vector<int> canReachN(n + 1, 0);
    queue<int> q;
    q.push(n);
    canReachN[n] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int prev : revAdj[node]) {
            if (!canReachN[prev]) {
                canReachN[prev] = 1;
                q.push(prev);
            }
        }
    }

    // Standard Bellman-Ford for shortest path
    vector<long long> dist(n + 1, INF);
    dist[1] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (auto &e : edges) {
            if (dist[e.a] == INF) continue;

            if (dist[e.a] + e.w < dist[e.b]) {
                dist[e.b] = dist[e.a] + e.w;
            }
        }
    }

    // nth relaxation: detect negative cycle affecting answer
    for (auto &e : edges) {
        if (dist[e.a] == INF) continue;

        if (dist[e.a] + e.w < dist[e.b] && canReachN[e.b]) {
            cout << -1 << '\n';
            return 0;
        }
    }

    cout << -dist[n] << '\n';
    return 0;
}