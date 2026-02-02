#include <iostream>
#include <vector>
using namespace std;

// ---------- Solve one test case ----------
void solve() {
    int n, a, b;
    cin>>n>>a>>b;
    if(n<(a+b)){
        cout<<"NO"<<'\n';
        return;
    }
    int equal = n-(a+b);
    if(equal==n){
    cout<<"YES"<<'\n';
    for(int i=0;i<n;i++){
        cout<<i+1<<" ";
    }
    cout<<'\n';
    for(int i=0;i<n;i++){
        cout<<i+1<<" ";
    }
    cout<<'\n';
        return;
    }
    if((n-equal)==max(a,b)){
        cout<<"NO"<<'\n';
        return;
    }
    int j=0;
    vector < int > playera(n, 0);
    vector < int > playerb(n, 0);
    for(int i=n;i>(n-equal);i--){
        playera[j]=i;
        playerb[j]=i;
        j++;
    }
    for(int i=(n-equal);i>(n-equal-a+1);i--){
        playera[j]=i;
        playerb[j]=i-1;
        j++;
    }
    playera[j]=n-equal-a+1;
    playerb[j]=1;
    j++;
    playera[j]=n-equal-a;
    playerb[j]=n-equal;
    j++;
    for(int i=(n-equal-a);i>1;i--){
        playera[j]=i-1;
        playerb[j]=i;
        j++;
    }
    cout<<"YES"<<'\n';
    for(int i=0;i<n;i++){
        cout<<playera[i]<<" ";
    }
    cout<<'\n';
    for(int i=0;i<n;i++){
        cout<<playerb[i]<<" ";
    }
    cout<<'\n';
}

int main() {

    int T = 1;
    // Uncomment if multiple test cases:
    cin >> T;
    while (T--){
        solve();
    } 
    return 0;
}
