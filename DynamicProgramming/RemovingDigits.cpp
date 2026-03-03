#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 1e9+7;

void digits(vector < int > &v, int n){
    while(n>0){
        v.push_back(n%10);
        n=n/10;
    }
}

int rec(int val, vector < int > &dp){
    if(val<0)
    return 1e9;
    if(val==0)
    return 0;
    if(dp[val]!=-1)
    return dp[val];
    int ans=1e9;
    vector < int > digit;
    digits(digit, val);
    for(auto &v: digit){
        if(v==0)
        continue;
        ans=min(ans, 1+rec(val-v, dp));
    }
    dp[val]=ans;
    return ans;
}



void solve() {
    int n;
    cin>>n;
    vector < int > dp(n+1, -1);
    int ans = rec(n, dp);
    cout<<ans<<'\n';
}

int main() {
    solve();
    return 0;
}
