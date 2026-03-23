

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

bool isValid(int x, int y, int n, int m, vector<vector<char>> &grid){
    if(x>=0 && x<n && y>=0 && y<m && grid[x][y]!='#'){
        return true;
    }
    return false;
}

void dfs(int x, int y, int n, int m, vector<vector<char>> &grid, vector<vector<int>> &vis){
    if(isValid(x, y, n, m, grid)==false)
    return;
    if(vis[x][y]==1)
    return;
    vis[x][y]=1;
    dfs(x+1, y, n, m, grid, vis);
    dfs(x, y-1, n, m, grid, vis);
    dfs(x-1, y, n, m, grid, vis);
    dfs(x, y+1, n, m, grid, vis);

}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]!='#'){
                if(vis[i][j]==0){
                    ans++;
                    dfs(i, j, n, m, grid, vis);
                }
            }
        }
    }
    cout<<ans<<'\n';
}
