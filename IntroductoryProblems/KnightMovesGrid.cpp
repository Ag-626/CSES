#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

bool isValid(int x, int y, int n){
    if((x>=0 && x<n)&&(y>=0 && y<n))
    return true;
    // cout<<"Inside isValid";
    return false;
}

void solve() {
    int n;
    cin>>n;

    vector < vector < int > > cntways(n, vector < int > (n, -1));
    vector < vector < int > > visted(n, vector < int > (n, 0));
    // cntways[0][0]=0;

    int dx_arr[] = {-1, 1, 2, 2, 1, -1, -2, -2};
    int dy_arr[] = { 2, 2, 1, -1, -2, -2, -1, 1};

    vector<int> dx(dx_arr, dx_arr + 8);
    vector<int> dy(dy_arr, dy_arr + 8);

    queue < pair < int, int > > q;
    q.push(make_pair(0, 0));
    cntways[0][0]=0;
    
    while(!(q.empty())){
        pair < int, int > coord = q.front();
        q.pop();
        int x = coord.first;
        int y = coord.second;
        if(visted[x][y])
        continue;
        visted[x][y]=1;

        int dis = cntways[x][y];
        for(int i=0;i<8;i++){
            if((isValid(x+dx[i], y+dy[i], n)) && (cntways[x+dx[i]][y+dy[i]]==-1)){
                cntways[x+dx[i]][y+dy[i]]=dis+1;
                q.push(make_pair(x+dx[i], y+dy[i]));
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<cntways[i][j]<<' ';
        }
        cout<<'\n';
    }

}

int main() {
    solve();
    return 0;
}
