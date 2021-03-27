#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, x, y;
    cin>>n>>m>>x>>y;
    vector<string> grid(n);
    for(auto &i : grid) {
        cin>>i;
    }
    x--;
    y--;
    int ans=1;
    for(int i=x-1; i>=0 && grid[i][y]!='#'; i--) {
        ans++;
    }
    for(int i=x+1; i<n && grid[i][y]!='#'; i++) {
        ans++;
    }
    for(int j=y-1; j>=0 && grid[x][j]!='#'; j--) {
        ans++;
    }
    for(int j=y+1; j<m && grid[x][j]!='#'; j++) {
        ans++;
    }
    cout<<ans<<endl;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

