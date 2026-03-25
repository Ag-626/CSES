#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin>>n>>m;
    vector<vector<int>> courses(n+1);
    vector<int> indeg(n+1, 0);
    vector<int> vis(n+1, 0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        courses[a].push_back(b);
        indeg[b]++;
    }
    queue<int> q;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0)
        q.push(i);
    }
    while(!(q.empty())){
        int course = q.front();
        q.pop();
        if(vis[course]==1)
        continue;
        vis[course]=1;
        ans.push_back(course);
        for(auto &v: courses[course]){
            indeg[v]=indeg[v]-1;
            if(indeg[v]==0)
            q.push(v);
        }
    }
    if(ans.size()<n)
    cout<<"IMPOSSIBLE"<<'\n';
    else{
        for(auto &v: ans){
            cout<<v<<" ";
        }
    }
    return 0;
}