#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<vector<pair<int, long long>>> g(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back(make_pair(b, c));
    }
    vector<long long> dis(n+1, 1e18);
    priority_queue <pair<long long, int>> pq;
    dis[1]=0;
    pq.push(make_pair(0, 1));
    while(!(pq.empty())){
        pair<long long, int> node=pq.top();
        pq.pop();
        long long cost = -1LL*node.first;
        int city = node.second;
        if(dis[city]<cost)
        continue;
        for(auto &v: g[city]){
            int city2=v.first;
            long long cost2=v.second;
            if(dis[city2]>(cost2+dis[city])){
                dis[city2]=cost2+dis[city];
                pq.push(make_pair(-dis[city2], city2));
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<' ';
    }

    return 0;
}