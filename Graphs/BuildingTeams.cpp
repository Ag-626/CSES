

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

bool dfs(int node, int par, int c, vector<vector<int>> &g, vector<int> &vis, vector<int> &color){
    color[node]=c;
    vis[node]=1;
    bool ans=true;
    for(auto &v: g[node]){
        if(v==par)
        continue;
        if(vis[v]==0){
            ans = (ans && dfs(v, node, (c+1)%2, g, vis, color));
        }else if(vis[v]==1){
            if(color[v]==((c+1)%2))
            ans=(ans && true);
            else
            ans=(ans && false);
        }
    }
    vis[node]=2;
    return ans;
}





int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int>vis(n+1, 0);
    vector<int> color(n+1, -1);
    bool ans=true;
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            ans=(ans && dfs(i, -1, 0, g, vis, color));
        }
    }
    if(ans){
        for(int i=1;i<=n;i++){
            if(color[i]==0)
            cout<<"1"<<" ";
            else
            cout<<"2"<<" ";
        }
    }
    else{
        cout<<"IMPOSSIBLE"<<'\n';
    }
}
