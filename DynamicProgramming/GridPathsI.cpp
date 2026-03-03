#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 1e9+7;



int rec(int x, int y, vector < vector < char > > &grid, vector < vector < int >  > &dp, int n){
    if(x>=n || y>=n)
    return 0;
    if(grid[x][y]=='*')
    return 0;
    if((x==n-1) && (y==n-1))
    return 1;
    if(dp[x][y]!=-1)
    return dp[x][y];

    int ans=0;
    ans=(ans+rec(x+1, y, grid, dp, n))%mod;
    ans=(ans+rec(x, y+1, grid, dp, n))%mod;
    dp[x][y]=ans;
    return ans;
}



void solve() {
    int n;
    cin>>n;
    vector < vector < char > > grid(n, vector < char > (n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    vector < vector < int > > dp(n, vector < int > (n, -1));
    int ans = rec(0,0, grid, dp, n);
    cout<<ans<<'\n';
}

int main() {
    solve();
    return 0;
}
