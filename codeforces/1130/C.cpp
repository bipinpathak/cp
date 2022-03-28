#include "bits/stdc++.h"
using namespace std;
using ll = long long;

int cost(int &r1, int &c1, int &r2, int &c2) {
    int ans=(r1-r2)*(r1-r2);
    ans+=(c1-c2)*(c1-c2);
    return ans;
}


void build(int r, int c, vector<string> &grid, vector<vector<int>> &possible) {
    int n=(int)possible.size();
    if(r+1<n && grid[r+1][c]=='0' && !possible[r+1][c]) {
        possible[r+1][c]=1;
        build(r+1, c, grid, possible);
    }
    if(r-1>=0 && grid[r-1][c]=='0' && !possible[r-1][c]) {
        possible[r-1][c]=1;
        build(r-1, c, grid, possible);
    }
    if(c+1<n && grid[r][c+1]=='0' && !possible[r][c+1]) {
        possible[r][c+1]=1;
        build(r, c+1, grid, possible);
    }
    if(c-1>=0 && grid[r][c-1]=='0' && !possible[r][c-1]) {
        possible[r][c-1]=1;
        build(r, c-1, grid, possible);
    }
    return;
}

void solve() {
    int n;
    cin>>n;
    int r1, c1, r2, c2;
    cin>>r1>>c1>>r2>>c2;
    r1--, c1--, r2--, c2--;
    vector<string> grid(n);
    for(auto &i : grid) {
        cin>>i;
    }
    vector<vector<int>> source(n, vector<int> (n)), dest;
    dest=source;
    source[r1][c1]=1;
    build(r1, c1, grid, source);
    dest[r2][c2]=1;
    build(r2, c2, grid, dest);
    vector<vector<int>> x, y;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(source[i][j]) {
                x.push_back({i, j});
            }
            if(dest[i][j]) {
                y.push_back({i, j});
            }
        }
    }
    int ans=cost(r1, c1, r2, c2);
    for(auto &i : x) {
        for(auto &j : y) {
            ans=min(ans, cost(i[0], i[1], j[0], j[1]));
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

