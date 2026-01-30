#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int n, int fromRod, int toRod, int auxRod) {

    if(n==0)
    return;
    solve(n-1, fromRod, auxRod, toRod);
    cout<<fromRod<<" "<<toRod<<'\n';
    solve(n-1, auxRod, toRod, fromRod);

}

int main() {
    int n;
    cin>>n;
    cout<<((1<<n)-1)<<'\n';
    solve(n, 1, 3, 2);
    return 0;
}
