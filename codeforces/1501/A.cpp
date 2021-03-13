#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n), b(n), t(n);
    for(int i=0; i<n; i++) {
        cin>>a[i]>>b[i];
    }   
    for(auto &i : t) {
        cin>>i;
    }
    ll curr=0, ans=0;
    for(int i=0; i<n; i++) {
        curr+=a[i]+t[i];
        curr-=(i?b[i-1]:0);
        ans=curr;
        curr+=max((b[i]-a[i]+1)/2, b[i]-curr);
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
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

