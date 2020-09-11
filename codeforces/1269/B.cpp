#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, m, i, j, ans;
    cin>>n>>m;
    ans=m;
    vector<int> a(n), b(n);
    for(auto &i : a) cin>>i;
    for(auto &i : b) cin>>i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(i=0; i<n; i++) {
        int diff=(b[i]-a[0]+m)%m;
        for(j=0; j<n; j++) {
            if((b[(i+j)%n]-a[j]+m)%m!=diff) break;
        }
        if(j==n) ans=min(ans, diff);
    }
    cout<<ans<<endl;
    return;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

