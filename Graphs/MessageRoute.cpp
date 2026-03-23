#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    vector<int> dist(n+1, 1e9);
    vector<int> par(n+1, 1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dist[1]=1;
    queue<int> q;
    q.push(1);
    while(!(q.empty())){
        int node = q.front();
        q.pop();
        for(auto &v: graph[node]){
            if(dist[v]>(1+dist[node])){
                dist[v]=1+dist[node];
                par[v]=node;
                q.push(v);
            }
        }
    }
    if(dist[n]==1e9){
        cout<<"IMPOSSIBLE"<<'\n';
    }
    else{
        vector<int> route;
        route.push_back(n);
        int node = n;
        while(node != 1){
            route.push_back(par[node]);
            node=par[node];
        }
        reverse(route.begin(), route.end());
        cout<<dist[n]<<'\n';
        for(auto &v: route){
            cout<<v<<' ';
        }
    }

    return 0;
}