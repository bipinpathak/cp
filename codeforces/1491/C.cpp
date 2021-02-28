#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n), b(n);
    for(auto &i : a) {
        cin>>i;
    }
    ll ans=0;
    for(int i=0; i<n; i++) {
        for(int j=min(n-1, i+a[i]); j>i+1; j--) {
            b[j]++;
        }
        if(a[i]-b[i]>1) {
            ans+=a[i]-b[i]-1;
        } 
        if(i+1<n && b[i]>a[i]-1) {
            b[i+1]+=b[i]-a[i]+1;
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
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

