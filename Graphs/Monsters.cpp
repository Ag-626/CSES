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
    vector<pair<int, int>> mons;
    pair<int,int> start;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='M')
            mons.push_back(make_pair(i, j));
            else if(grid[i][j]=='A')
            start = make_pair(i, j);
        }
    }
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    int dir[4] = {'U', 'R', 'D', 'L'};
    vector<vector<int>> dis1(n, vector<int>(m, 1e9));
    queue<pair<int,int>> q;
    for(auto &v: mons){
        dis1[v.first][v.second]=0;
        q.push(v);
    }
    while(!(q.empty())){
        pair <int,int> cell = q.front();
        int x = cell.first;
        int y = cell.second;
        q.pop();
        if(!(isValid(x, y, n, m, grid)))
        continue;
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(isValid(nx, ny, n, m, grid)){
                if(dis1[nx][ny]>(1+dis1[x][y])){
                    dis1[nx][ny]=1+dis1[x][y];
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    vector<vector<int>> dis2(n, vector<int>(m, 1e9));
    vector<vector<char>> path(n, vector<char>(m, ' '));
    dis2[start.first][start.second]=0;
    q.push(start);
    while(!(q.empty())){
        pair<int, int> cell = q.front();
        int x = cell.first;
        int y = cell.second;
        q.pop();
        if(!(isValid(x, y, n, m, grid)))
        continue;
        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(isValid(nx, ny, n, m, grid)){
                if(dis2[nx][ny]>(1+dis2[x][y])){
                    dis2[nx][ny]=1+dis2[x][y];
                    path[nx][ny]=dir[i];
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        if(grid[0][i]!='#'){
            if(dis2[0][i]<dis1[0][i]){
                cout<<"YES"<<'\n';
                cout<<dis2[0][i]<<'\n';
                string ans="";
                int x = 0;
                int y=i;
                while(!((x==start.first) && (y==start.second))){
                    if(path[x][y]=='U'){
                        ans.push_back('D');
                        x=x-1;
                    }else if((path[x][y]=='R')){
                        ans.push_back('L');
                        y=y+1;
                    }else if(path[x][y]=='D'){
                        ans.push_back('U');
                        x=x+1;
                    }else if(path[x][y]=='L'){
                        ans.push_back('R');
                        y=y-1;
                    }
                }
                reverse(ans.begin(), ans.end());
                cout<<ans<<'\n';
                return 0;
            }
        }
    }

    for(int i=0;i<m;i++){
        if(grid[n-1][i]!='#'){
            if(dis2[n-1][i]<dis1[n-1][i]){
                cout<<"YES"<<'\n';
                cout<<dis2[n-1][i]<<'\n';
                string ans="";
                int x = n-1;
                int y=i;
                while(!((x==start.first) && (y==start.second))){
                    if(path[x][y]=='U'){
                        ans.push_back('D');
                        x=x-1;
                    }else if((path[x][y]=='R')){
                        ans.push_back('L');
                        y=y+1;
                    }else if(path[x][y]=='D'){
                        ans.push_back('U');
                        x=x+1;
                    }else if(path[x][y]=='L'){
                        ans.push_back('R');
                        y=y-1;
                    }
                }
                reverse(ans.begin(), ans.end());
                cout<<ans<<'\n';
                return 0;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(grid[i][0]!='#'){
            if(dis2[i][0]<dis1[i][0]){
                cout<<"YES"<<'\n';
                cout<<dis2[i][0]<<'\n';
                string ans="";
                int x = i;
                int y=0;
                while(!((x==start.first) && (y==start.second))){
                    if(path[x][y]=='U'){
                        ans.push_back('D');
                        x=x-1;
                    }else if((path[x][y]=='R')){
                        ans.push_back('L');
                        y=y+1;
                    }else if(path[x][y]=='D'){
                        ans.push_back('U');
                        x=x+1;
                    }else if(path[x][y]=='L'){
                        ans.push_back('R');
                        y=y-1;
                    }
                }
                reverse(ans.begin(), ans.end());
                cout<<ans<<'\n';
                return 0;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(grid[i][m-1]!='#'){
            if(dis2[i][m-1]<dis1[i][m-1]){
                cout<<"YES"<<'\n';
                cout<<dis2[i][m-1]<<'\n';
                string ans="";
                int x = i;
                int y=m-1;
                while(!((x==start.first) && (y==start.second))){
                    if(path[x][y]=='U'){
                        ans.push_back('D');
                        x=x-1;
                    }else if((path[x][y]=='R')){
                        ans.push_back('L');
                        y=y+1;
                    }else if(path[x][y]=='D'){
                        ans.push_back('U');
                        x=x+1;
                    }else if(path[x][y]=='L'){
                        ans.push_back('R');
                        y=y-1;
                    }
                }
                reverse(ans.begin(), ans.end());
                cout<<ans<<'\n';
                return 0;
            }
        }
    }
    cout<<"NO"<<'\n';

    return 0;
}