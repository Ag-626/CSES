#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector < set < int > > rowwise(n);
    vector < set < int > > columnwise(n);
    vector < vector < int > > ans(n, vector < int > (n, -1));
    for(int i=0;i<n;i++){
        rowwise[0].insert(i);
        columnwise[i].insert(i);
        ans[0][i]=i;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            int k=0;
            if(j==0){
                while(columnwise[j].find(k)!=columnwise[j].end()){
                    k++;
                }
                rowwise[i].insert(k);
                columnwise[j].insert(k);
                ans[i][j]=k;
            }
            else{
                while((columnwise[j].find(k)!=columnwise[j].end())||(rowwise[i].find(k)!=rowwise[i].end())){
                    k++;
                }
                columnwise[j].insert(k);
                rowwise[i].insert(k);
                ans[i][j]=k;   
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<'\n';
    }
}

int main() {
    solve();
    return 0;
}
