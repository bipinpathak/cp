#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> a(n+1, vector<int> (n));
    for(auto &i : a[0]) {
        cin>>i;
    }
    for(int move=1; move<=n; move++) {
        vector<int> f(n+1);
        for(int i=0; i<n; i++) {
            f[a[move-1][i]]++;
        }
        for(int i=0; i<n; i++) {
            a[move][i]=f[a[move-1][i]];
        }
    }
    int q;
    cin>>q;
    while(q--) {
        int x, k;
        cin>>x>>k;
        k=min(k, n);
        cout<<a[k][--x]<<endl;
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
    int t = 1;
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

