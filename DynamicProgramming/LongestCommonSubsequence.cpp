#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 1e9+7;

int rec(int i, int j, int n, int m, vector<int> &a, vector<int> &b, vector<vector<int>> &dp, vector<vector<pair<int, int>>> &gen){
    if(i==n || j==m)
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int ans=0;
    if(a[i]==b[j]){
        ans=1+rec(i+1, j+1, n, m, a, b, dp, gen);
        gen[i][j]=make_pair(i+1, j+1);
    }else{
        ans=max(ans, rec(i+1, j, n, m, a, b, dp, gen));
        ans=max(ans, rec(i, j+1, n, m, a, b, dp, gen));
        if(ans==rec(i+1, j, n, m, a, b, dp, gen))
        gen[i][j]=make_pair(i+1, j);
        else
        gen[i][j]=make_pair(i, j+1);
    }
    dp[i][j]=ans;
    return ans;
}

void generation(int i, int j, int n, int m, vector <int> &a, vector < int> &b, vector<vector<pair<int, int>>> &gen, vector < int > &ans){
    if(i==n || j==m)
    return;
    int ni = gen[i][j].first;
    int nj = gen[i][j].second;
    if(((ni-i)==1) && ((nj-j)==1)){
        ans.push_back(a[i]);
        generation(ni, nj, n, m, a, b, gen, ans);
    }else{
        generation(ni, nj, n, m, a, b, gen, ans);
    }
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector < int > a(n);
    vector < int > b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    vector<vector<int>> dp(n, vector<int>(m, -1));
    vector<vector<pair<int, int>>> gen(n, vector<pair<int, int>>(m));
    int anslen=rec(0, 0, n, m, a, b, dp, gen);
    vector<int> ans;
    generation(0, 0, n, m, a, b, gen, ans);
    cout<<anslen<<'\n';
    for(auto &v: ans){
        cout<<v<<' ';
    }
    cout<<'\n';
}

int main() {
    solve();
    return 0;
}
