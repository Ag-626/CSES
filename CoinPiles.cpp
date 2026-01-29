#include <iostream>
#include <vector>
using namespace std;

// ---------- Solve one test case ----------
void solve() {
    int a;
    int b;
    cin>>a>>b;
    if(a==0 && b==0){
        cout<<"YES"<<'\n';
        return;
    }
    if(a==0 || b==0){
        cout<<"NO"<<'\n';
        return;
    }
    if((a>(2*b))||(b>(2*a))){
        cout<<"NO"<<'\n';
        return;
    }
    int x=max(a,b);
    int y=min(a,b);
    x=x-2*(x-y);
    y=y-(x-y);
    if(x%3==0){
        cout<<"YES"<<'\n';
        return;
    }
    cout<<"NO"<<'\n';
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
