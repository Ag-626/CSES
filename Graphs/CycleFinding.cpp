#include <bits/stdc++.h>
using namespace std;


struct edge{
    int u,v;
    long long c;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<long long> dist(n+1, 0);
    vector<int> par(n+1, -1);
    vector<edge> edges(m);
    for(int i=0;i<m;i++){
        cin>>edges[i].u>>edges[i].v>>edges[i].c;
    }
    dist[1]=0;
    int x=-1;
    for(int i=1;i<=n;i++){
        x=-1;
        for(auto &e: edges){
            if(dist[e.u]==1e18)
            continue;
            if((dist[e.u]+e.c)<dist[e.v]){
                dist[e.v]=dist[e.u]+e.c;
                par[e.v]=e.u;
                x=e.v;
            }
        }
    }
    
    if(x!=-1){
        int y = x;
        for(int i=1;i<=n;i++){
            y=par[y];
        }
        vector<int>path;
        int cur=y;
        do{
            path.push_back(cur);
            cur=par[cur];
        }while(cur!=y);
        path.push_back(y);
        reverse(path.begin(), path.end());
        cout<<"YES"<<'\n';
        for(auto &p: path){
            cout<<p<<' ';
        }
    }else{
        cout<<"NO"<<'\n';
    }

    return 0;
}