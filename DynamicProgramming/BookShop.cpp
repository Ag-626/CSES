

#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    cin>>n;
    int x;
    cin>>x;

    vector < int > price(n);
    vector < int > pages(n);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    vector<int> dp(x+1, 0);
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=x;j>=price[i];j--){
            dp[j]=max(dp[j], dp[j-price[i]]+pages[i]);
        }
    }
    cout<<dp[x]<<'\n';

    return 0;
}
