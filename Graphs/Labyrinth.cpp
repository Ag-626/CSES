#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int n, int m, vector<vector<char>> &grid){
    return x>=0 && x<n && y>=0 && y<m && grid[x][y]!='#';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;

    vector<vector<char>> grid(n, vector<char>(m));
    pair<int,int> start, endd;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='A') start={i,j};
            else if(grid[i][j]=='B') endd={i,j};
        }
    }

    vector<vector<int>> dis(n, vector<int>(m, -1));
    vector<vector<char>> path(n, vector<char>(m, ' '));
    vector<vector<int>> vis(n, vector<int>(m, 0));

    queue<pair<int,int>> q;
    q.push(start);
    vis[start.first][start.second] = 1;
    dis[start.first][start.second] = 0;

    while(!q.empty()){
        auto cell = q.front();
        q.pop();

        int x = cell.first;
        int y = cell.second;

        if(isValid(x+1, y, n, m, grid) && !vis[x+1][y]){
            vis[x+1][y] = 1;
            dis[x+1][y] = dis[x][y] + 1;
            path[x+1][y] = 'U';
            q.push({x+1, y});
        }

        if(isValid(x, y-1, n, m, grid) && !vis[x][y-1]){
            vis[x][y-1] = 1;
            dis[x][y-1] = dis[x][y] + 1;
            path[x][y-1] = 'R';
            q.push({x, y-1});
        }

        if(isValid(x-1, y, n, m, grid) && !vis[x-1][y]){
            vis[x-1][y] = 1;
            dis[x-1][y] = dis[x][y] + 1;
            path[x-1][y] = 'D';
            q.push({x-1, y});
        }

        if(isValid(x, y+1, n, m, grid) && !vis[x][y+1]){
            vis[x][y+1] = 1;
            dis[x][y+1] = dis[x][y] + 1;
            path[x][y+1] = 'L';
            q.push({x, y+1});
        }
    }

    if(dis[endd.first][endd.second] == -1){
        cout<<"NO\n";
        return 0;
    }

    string ans = "";
    int x = endd.first;
    int y = endd.second;

    while(!(x == start.first && y == start.second)){
        if(path[x][y] == 'R'){
            ans.push_back('L');
            y = y + 1;
        }
        else if(path[x][y] == 'U'){
            ans.push_back('D');
            x = x - 1;
        }
        else if(path[x][y] == 'L'){
            ans.push_back('R');
            y = y - 1;
        }
        else if(path[x][y] == 'D'){
            ans.push_back('U');
            x = x + 1;
        }
        else{
            break;
        }
    }

    reverse(ans.begin(), ans.end());

    cout<<"YES\n";
    cout<<ans.size()<<"\n";
    cout<<ans<<"\n";

    return 0;
}