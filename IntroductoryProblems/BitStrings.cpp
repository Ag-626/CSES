#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


long long exp(long long a, long long b){
    const long long mod = 1e9+7;
    long long ans=1;
    while(b>0){
        if(b&1){
            ans=(1LL*ans*a)%mod;
        }
        a=(a*a)%mod;
        b=b>>1;
    }
    return ans;
}
void solve() {
    int n;
    cin>>n;
    long long ans=exp(2, n);
    cout<<ans<<'\n';
}

int main() {
    solve();
    return 0;
}
