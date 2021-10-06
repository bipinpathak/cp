#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<vector<ll>> a(2, vector<ll> (n));
    for(auto &i : a) {
        for(auto &j : i) {
            cin>>j;
        }
    }
    for(int i=n-2; i>=0; i--) {
        for(int j=0; j<2; j++) {
            a[j][i]=max(a[j][i]+a[!j][i+1], a[j][i+1]);
        }
    }
    cout<<max(a[0][0], a[1][0]);
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

