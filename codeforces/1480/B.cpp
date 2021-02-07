#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll A, B, n;
    cin>>A>>B>>n;
    vector<vector<ll>> a(n, vector<ll> (2));
    for(int i=0; i<n; i++) {
        cin>>a[i][0];
    }
    for(int i=0 ; i<n; i++) {
        cin>>a[i][1];
    }
    ll last=0, high=0;
    for(int i=0; i<n; i++) {
        ll blows=(a[i][1]+A-1)/A;
        B-=(blows-1)*a[i][0];
        if(B<=0) {
            cout<<"NO"<<endl;
            return;
        }
        last+=a[i][0];
        high=max(high, a[i][0]);
    }
    if(B<last-high) {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

