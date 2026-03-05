#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    long long tw;
    cin>>n;
    cin>>tw;

    vector<long long> weights(n);
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }
    int N = 1<<n;
    vector<pair<int, long long>> dp(N, {n+1, 0});
    dp[0]=make_pair(1, 0);
    for(int mask=1;mask<N;mask++){
        for(int i=0;i<n;i++){
            if(mask&(1<<i)){
                int prev = mask^(1<<i);
                int prides = dp[prev].first;
                int pweight = dp[prev].second;
                if((weights[i]+pweight)<=tw){
                    dp[mask]=min(dp[mask], make_pair(prides, weights[i]+pweight));
                }else{
                    dp[mask]=min(dp[mask], make_pair(prides+1, weights[i]));
                }
            }
        }
    }

    cout<<dp[N-1].first<<'\n';
}