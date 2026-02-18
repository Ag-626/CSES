#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rec(int row, vector < vector < char > > &chess, vector < int > &col, vector < vector < int > > &dia, long long &ans){
    if(row==8){
        ans++;
        return;
    }
    for(int i=0;i<8;i++){
        if((col[i]>=1)||(dia[row][i]>=1))
        continue;
        if(chess[row][i]!='*'){
            col[i]++;
            for(int j=1;j<=min(i, row);j++){
                dia[row-j][i-j]++;
            }
            for(int j=1;j<=min(7-i, 7-row);j++){
                dia[row+j][i+j]++;
            }
            for(int j=1;j<=min(row, 7-i);j++){
                dia[row-j][i+j]++;
            }
            for(int j=1;j<=min(7-row, i);j++){
                dia[row+j][i-j]++;
            }
            rec(row+1, chess, col, dia, ans);
            col[i]--;
            for(int j=1;j<=min(i, row);j++){
                dia[row-j][i-j]--;
            }
            for(int j=1;j<=min(7-i, 7-row);j++){
                dia[row+j][i+j]--;
            }
            for(int j=1;j<=min(row, 7-i);j++){
                dia[row-j][i+j]--;
            }
            for(int j=1;j<=min(7-row, i);j++){
                dia[row+j][i-j]--;
            }
        }
    }
 }

void solve() {
    vector < vector < char > > chess(8, vector < char > (8, '.'));
    char c;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>c;
            if(c=='*')
            chess[i][j]=c;
        }
    }
    vector < int > col(8, 0);
    vector < vector < int > > dia(8, vector < int > (8, 0));
    long long ans=0;
    rec(0, chess, col, dia, ans);
    cout<<ans<<'\n';
}

int main() {
    solve();
    return 0;
}
