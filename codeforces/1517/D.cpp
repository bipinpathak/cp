#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<int>> edges;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m-1; j++) {
            int x;
            cin>>x;
            edges.push_back({x, i, j, i, j+1});
        }
    }
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<m; j++) {
            int x;
            cin>>x;
            edges.push_back({x, i, j, i+1, j});
        }       
    }
    if(k&1) {
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                cout<<-1<<" ";
            }
            cout<<endl;
        }
        return;
    }
    vector<vector<int>> ans(n, vector<int> (m));
    k/=2;
    while(k--) {
        vector<vector<int>> update(n, vector<int> (m, 1e9));
        for(auto e : edges) {
            int w=e[0], x1=e[1], y1=e[2], x2=e[3], y2=e[4];
            update[x1][y1]=min(update[x1][y1], ans[x1][y1]+2*w);
            update[x1][y1]=min(update[x1][y1], ans[x2][y2]+2*w);
            update[x2][y2]=min(update[x2][y2], ans[x1][y1]+2*w);
            update[x2][y2]=min(update[x2][y2], ans[x2][y2]+2*w);
        }
        ans=update;
    }
    for(auto &i : ans) {
        for(auto &j : i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
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