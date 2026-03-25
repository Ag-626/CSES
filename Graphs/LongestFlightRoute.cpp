#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<vector<int>> flights(n+1);
    vector<int> indeg(n+1, 0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        indeg[b]++;
        flights[a].push_back(b);
    }
    queue <int> q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0)
        q.push(i);
    }
    vector<int> topo;
    while(!(q.empty())){
        int flight = q.front();
        q.pop();
        topo.push_back(flight);
        for(auto &v: flights[flight]){
            indeg[v]--;
            if(indeg[v]==0)
            q.push(v);
        }
    }
    vector<int> dp(n+1, -1e9);
    vector<int> par(n+1, -1);
    dp[1]=1;
    for(auto &v: topo){
        if(dp[v]==-1e9)
        continue;
        for(auto &u: flights[v]){
            if((dp[v]+1)>(dp[u])){
                dp[u]=dp[v]+1;
                par[u]=v;
            }
        }
    }
    if(dp[n]==(-1e9)){
        cout<<"IMPOSSIBLE";
    }else{
        cout<<dp[n]<<'\n';
        vector<int> ans;
        int cur=n;
        while(cur!=-1){
            ans.push_back(cur);
            cur=par[cur];
        }
        reverse(ans.begin(), ans.end());
        for(auto &v: ans){
            cout<<v<<' ';
        }
    }
    return 0;
}