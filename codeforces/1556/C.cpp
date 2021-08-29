#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void go(ll l, ll r, vector<ll> &a, ll &left, ll &right) {
    ll open=0;
    while(l<=r) {
        if(l&1) {
            open-=a[l];
        } else {
            open+=a[l];
        }
        l++;
        if(open<0) {
            left-=open;
            open=0;
        }
    }
    right=open;
    return;
}

void solve() {
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    ll ans=0;
    for(ll i=0; i<n; i+=2) {
        for(ll j=i+1; j<n; j+=2) {
            ll left=0, right=0;
            go(i+1, j-1, a, left, right);
            if(left>a[i] || right>a[j]) {
                continue;
            }
            left=a[i]-left;
            right=a[j]-right;
            ll m=1+min(left, right);
            if(left==a[i] && right==a[j]) {
                m--;
            }
            ans+=m;
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

