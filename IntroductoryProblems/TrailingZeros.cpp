#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    cin>>n;
    long long div=5;
    long long ans=0;
    while((n/div)>0){
        ans+=(1LL*n)/div;
        div*=5;
    }
    cout<<ans<<'\n';
}

int main() {
    solve();
    return 0;
}
