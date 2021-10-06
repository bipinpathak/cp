#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, m, a, b, g, x, y, z;
    cin>>n>>m>>a>>b>>g>>x>>y>>z;
    vector<vector<int>> grid(n, vector<int> (m));
    for(auto &i : grid) {
        for(auto &j: i) {
            j=g;
            g=((ll)g*x)%z;
            g+=y;
            if(g>=z) {
                g-=z;
            }
        }
    }
    auto small=grid;
    for(int i=0; i<n; i++) {
        deque<int> active;
        for(int j=m-1; j>=0; j--) {
            while(!active.empty() && active.front()>=j+b) {
                active.pop_front();
            }
            while(!active.empty() && grid[i][active.back()]>=grid[i][j]) {
                active.pop_back();
            }
            if(active.empty() || grid[i][active.back()]<grid[i][j]) {
                active.push_back(j);
            }
            small[i][j]=grid[i][active.front()];
        }
    }
    grid=small;
    for(int j=0; j<m; j++) {
        deque<int> active;
        for(int i=n-1; i>=0; i--) {
            while(!active.empty() && active.front()>=i+a) {
                active.pop_front();
            }
            while(!active.empty() && grid[active.back()][j]>=grid[i][j]) {
                active.pop_back();
            }
            if(active.empty() || grid[active.back()][j]<grid[i][j]) {
                active.push_back(i);
            }
            small[i][j]=grid[active.front()][j];
        }
    }
    ll ans=0;
    for(int i=0; i<=n-a; i++) {
        for(int j=0; j<=m-b; j++) {
            ans+=small[i][j];
        }
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

