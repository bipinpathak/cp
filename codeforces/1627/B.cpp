#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<int> ans;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            int d=i+j;
            d=max(d, i+m-1-j);
            d=max(d, n-1-i+j);
            d=max(d, n-1-i+m-1-j);
            ans.push_back(d);
        }
    }
    sort(ans.begin(), ans.end());
    for(auto &i : ans) {
        cout<<i<<" ";
    }
    cout<<endl;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

