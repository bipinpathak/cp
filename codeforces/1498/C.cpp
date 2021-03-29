#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    int n, k;
    cin>>n>>k;
    if(k==1) {
        cout<<1<<endl;
        return;
    } else if(n==1) {
        cout<<2<<endl;
        return;
    }
    k-=2;
    ll p=1e9+7, ans=1+n;
    vector<ll> a(n-1, 1);
    bool left=true;
    while(k--) {
        ll curr=0;
        if(left) {
            for(int i=n-2; i>=0; i--) {
                curr=(curr+a[i])%p;
                a[i]=curr;
                ans=(ans+a[i])%p;
            }
        } else {
            for(int i=0; i<n-1; i++) {
                curr=(curr+a[i])%p;
                a[i]=curr;
                ans=(ans+a[i])%p;
            }
        }
        left=!left;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

