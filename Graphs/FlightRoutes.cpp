#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin>>n>>m>>k;

    vector<vector<pair<int, long long>>> flights(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        flights[a].push_back(make_pair(b, c));
    }
    vector<multiset<long long>> cost(n+1);
    cost[1].insert(0);
    for(int i=1;i<k;i++)
    cost[1].insert(1e18);
    for(int i=2;i<=n;i++){
        for(int j=0;j<k;j++)
        cost[i].insert(1e18);
    }
    priority_queue<pair<long long, int>> pq;
    pq.push(make_pair(0, 1));
    while(!(pq.empty())){
        pair<long long, int> node = pq.top();
        pq.pop();
        int city = node.second;
        long long price = -node.first;

        auto it2=cost[city].end();
        it2--;
        if(cost[city].size() == k && (price > *it2))
        continue;
        
        for(auto &v: flights[city]){
            long long weight = v.second;
            int city2 = v.first;
            auto it = cost[city2].end();
            it--;
            long long newPrice = price+weight;
            if(*it>(newPrice)){
                cost[city2].erase(it);
                if(cost[city2].find(newPrice)==cost[city2].end()){
                    cost[city2].insert(newPrice);
                    pq.push(make_pair(-newPrice, city2));
                }else{
                     cost[city2].insert(newPrice);
                     pq.push(make_pair(-newPrice, city2));
                }
            }
        }
    }
    for(auto &v: cost[n])
    cout<<v<<' ';
    return 0;
}