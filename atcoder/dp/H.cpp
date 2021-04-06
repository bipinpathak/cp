#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<char>> grid(n, vector<char> (m));
    for(auto &i : grid) {
        for(auto &j : i) {
            cin>>j;
        }   
    }
    vector<vector<int>> ans(n, vector<int> (m));
    ans[0][0]=1;
    int p=1e9+7;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j]=='#') {
                continue;
            }   
            if(i) {
                ans[i][j]=(ans[i][j]+ans[i-1][j])%p;
            }
            if(j) {
                ans[i][j]=(ans[i][j]+ans[i][j-1])%p;
            }
        }
    }
    cout<<ans[n-1][m-1]<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

