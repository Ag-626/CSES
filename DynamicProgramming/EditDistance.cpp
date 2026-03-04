#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 1e9+7;

int rec(int i, int j, string &s1, string &s2, vector < vector < int > > &dp){

    if(i<0 && j<0)
    return 0;
    if(i<0){
        return j+1;
    }
    if(j<0){
        return i+1;
    }
    if(dp[i][j]!=-1)
    return dp[i][j];
    int ans=1e9;
    if(s1[i]==s2[j]){
        ans=min(ans, rec(i-1, j-1, s1, s2, dp));
    }else{
        ans=min(ans, 1+rec(i-1, j-1, s1, s2, dp));
        ans=min(ans, 1+rec(i, j-1, s1, s2, dp));
        ans=min(ans, 1+rec(i-1, j, s1, s2, dp));
    }
    dp[i][j]=ans;
    return ans;
}

void solve() {
    string s1;
    string s2;
    cin>>s1;
    int n = s1.length();
    cin>>s2;
    int m = s2.length();
    vector< vector < int > > dp(n, vector < int > (m, -1));
    int ans = rec(n-1, m-1, s1, s2, dp);
    cout<<ans<<'\n';
}

int main() {
    solve();
    return 0;
}
