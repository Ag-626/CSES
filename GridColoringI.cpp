#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, m;
    cin>>n>>m;

    vector < vector < char > > grid(n, vector < char > (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if((i+j)%2){
                if(grid[i][j]=='C')
                grid[i][j]='D';
                else if(grid[i][j]=='D')
                grid[i][j]='C';
                else{
                    grid[i][j]='C';
                }
            }
            else{
                if(grid[i][j]=='A')
                grid[i][j]='B';
                else if(grid[i][j]=='B')
                grid[i][j]='A';
                else{
                    grid[i][j]='A';
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<grid[i][j];
        }
        cout<<'\n';
    }
}

int main() {
    solve();
    return 0;
}
