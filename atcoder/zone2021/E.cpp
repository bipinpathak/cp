#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int r, c;
    cin>>r>>c;
    vector<vector<int>> a(r, vector<int> (c-1)), b(r-1, vector<int> (c));
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    for(auto &i : b) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    vector<vector<int>> ans(r, vector<int> (c, INT_MAX));
    set<vector<int>> active;
    active.insert({0, 0, 0});
    while(!active.empty()) {
        auto curr=*active.begin();
        active.erase(active.begin());
        int x=curr[1], y=curr[2], d=curr[0];
        if(ans[x][y]<d) {
            continue;
        }
        ans[x][y]=d;
        if(x+1<r && ans[x+1][y]>d+b[x][y]) {
            ans[x+1][y]=d+b[x][y];
            active.insert({ans[x+1][y], x+1, y});
        }
        if(y+1<c && ans[x][y+1]>d+a[x][y]) {
            ans[x][y+1]=d+a[x][y];
            active.insert({ans[x][y+1], x, y+1});
        }
        if(y-1>=0 && ans[x][y-1]>d+a[x][y-1]) {
            ans[x][y-1]=d+a[x][y-1];
           active.insert({ans[x][y-1], x, y-1});
        }
        for(int i=0; i<x; i++) {
            if(ans[i][y]>d+x-i+1) {
                ans[i][y]=d+x-i+1;
                active.insert({ans[i][y], i, y});
            }
        }
    }
    cout<<ans[r-1][c-1]<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    auto start=clock();
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

