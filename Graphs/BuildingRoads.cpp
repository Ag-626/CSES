

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;


int findPar(int city, vector<int> &par){
    if(par[city]==city)
    return city;
    return par[city]=findPar(par[city], par);
}

void dfs(int a, int b, vector<int> &sz, vector<int> &par){
    int parA = findPar(a, par);
    int parB = findPar(b, par);
    if(parA==parB)
    return;
    if(sz[parA]<sz[parB]){
        par[parA]=parB;
        sz[parB]+=sz[parA];
    }else{
        par[parB]=parA;
        sz[parA]+=sz[parB]; 
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;
    vector<int> par(n+1);
    vector<int> sz(n+1, 1);
    for(int i=0;i<=n;i++){
        par[i]=i;
    }
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        dfs(a, b, sz, par);
    }
    vector<int> reps;
    for(int i = 1; i <= n; i++){
        if(findPar(i, par) == i){
            reps.push_back(i);
        }
    }

    cout << reps.size() - 1 << '\n';
    for(int i = 0; i + 1 < reps.size(); i++){
        cout << reps[i] << " " << reps[i + 1] << '\n';
    }

}
