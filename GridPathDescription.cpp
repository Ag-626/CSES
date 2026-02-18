#include <bits/stdc++.h>
using namespace std;

string s;
bool vis[7][7];
int ans = 0;

bool inside(int x, int y) {
    return x >= 0 && x < 7 && y >= 0 && y < 7;
}

bool blocked(int x, int y) {
    return !inside(x, y) || vis[x][y];
}

void dfs(int i, int x, int y) {
    if (x == 6 && y == 0) {
        if (i == 48) ans++;
        return;
    }
    if (i == 48) return;

    if (vis[x][y]) return;
    vis[x][y] = true;

    // --- Strong pruning: avoid splitting the grid into 2 parts ---
    // If left and right are blocked but up and down are free => forced vertical corridor
    if (blocked(x, y-1) && blocked(x, y+1) && !blocked(x-1, y) && !blocked(x+1, y)) {
        vis[x][y] = false;
        return;
    }
    // If up and down are blocked but left and right are free => forced horizontal corridor
    if (blocked(x-1, y) && blocked(x+1, y) && !blocked(x, y-1) && !blocked(x, y+1)) {
        vis[x][y] = false;
        return;
    }

    auto go = [&](int nx, int ny) {
        if (!blocked(nx, ny)) dfs(i+1, nx, ny);
    };

    char c = s[i];
    if (c == '?') {
        go(x+1, y); // D
        go(x-1, y); // U
        go(x, y+1); // R
        go(x, y-1); // L
    } else if (c == 'D') go(x+1, y);
    else if (c == 'U') go(x-1, y);
    else if (c == 'R') go(x, y+1);
    else if (c == 'L') go(x, y-1);

    vis[x][y] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    memset(vis, 0, sizeof(vis));
    dfs(0, 0, 0);
    cout << ans << "\n";
}
