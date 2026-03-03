

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    vector < int > queries(t);
    int maxVal=0;
    for(int i=0;i<t;i++){
        cin>>queries[i];
        maxVal=max(maxVal, queries[i]);
    }
    vector<int> typeA(maxVal+1, 0);
    vector<int> typeB(maxVal+1, 0);
    typeA[1]=1;
    typeB[1]=1;
    for(int i=2;i<=maxVal;i++){
        typeA[i]= (2LL*typeA[i-1]%mod + typeB[i-1])%mod;
        typeB[i]= (typeA[i-1] + 4LL*typeB[i-1]%mod)%mod;
    }

    for(int i=0;i<t;i++){
        cout<<((typeA[queries[i]] + typeB[queries[i]])%mod)<<'\n';
    }
    

    return 0;
}
