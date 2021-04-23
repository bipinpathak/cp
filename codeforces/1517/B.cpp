#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> b(n, vector<int> (m));
    for(auto &i : b) {
        for(auto &j : i) {
            cin>>j;
        }
        sort(i.begin(), i.end());
    }
    vector<pair<int, int>> runner(m);
    for(int i=0; i<m; i++) {
        runner[i]={1e9+1, i};
    }
    for(int i=0; i<n; i++) {
        sort(runner.rbegin(), runner.rend());
        vector<int> build(m);
        for(int j=0; j<m; j++) {
            build[runner[j].second]=b[i][j];
            runner[j].first=min(runner[j].first, b[i][j]);
        }
        for(auto j : build) {
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
    cin >> t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

