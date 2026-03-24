#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<long long>> grid(n+1, vector<long long>(n+1, 1e18));
    for(int i=1;i<=n;i++){
        grid[i][i]=0;
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        grid[a][b]=min(grid[a][b],1LL*c);
        grid[b][a]=min(grid[b][a], 1LL*c);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                grid[i][j]=min(grid[i][j], grid[i][k]+grid[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int a,b;
        cin>>a>>b;
        if(grid[a][b]==1e18)
        cout<<"-1"<<'\n';
        else{
            cout<<grid[a][b]<<'\n';
        }
    }

    return 0;
}