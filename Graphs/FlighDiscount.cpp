#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<vector<pair<int, long long>>> g(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        g[a].push_back(make_pair(b, c));
    }
    vector<vector<long long>> cost(n+1, vector<long long>(2, 1e18));
    vector<vector<int>> vis(n+1, vector<int>(2, 0));
    cost[1][0]=0;
    cost[1][1]=0;
    priority_queue<pair<long long, pair<int, int>>> pq;
    pq.push(make_pair(0, make_pair(1, 0)));
    pq.push(make_pair(0, make_pair(1, 1)));

    while(!(pq.empty())){
        pair<long long, pair<int, int>> node = pq.top();
        pq.pop();
        int city = node.second.first;
        int left = node.second.second;
        if(vis[city][left]==1)
        continue;
        vis[city][left]=1;
        for(auto &v: g[city]){
            int city2=v.first;
            long long price = v.second;
            if(left==1){
                if(cost[city2][left]>(price+cost[city][left])){
                    cost[city2][left]=price+cost[city][left];
                    pq.push(make_pair(-cost[city2][left], make_pair(city2, left)));
                }
                if(cost[city2][0]>(price/2+cost[city][left])){
                    cost[city2][0]=price/2+cost[city][left];
                    pq.push(make_pair(-cost[city2][0], make_pair(city2, 0)));
                }
            }else{
                if(cost[city2][left]>(price+cost[city][left])){
                    cost[city2][left]=price+cost[city][left];
                    pq.push(make_pair(-cost[city2][left], make_pair(city2, left)));
                }
            }
        }
    }

    cout<<min(cost[n][0], cost[n][1])<<'\n';

    return 0;
}