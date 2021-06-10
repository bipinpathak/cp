#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, l, r;
    cin>>n>>l>>r;
    vector<ll> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    sort(a.begin(), a.end());
    ll ans=0;
    for(auto i : a) {
        ans+=upper_bound(a.begin(), a.end(), r-i)-lower_bound(a.begin(), a.end(), l-i);
        if(2*i>=l && 2*i<=r) {
            ans--;
        }
    }
    ans/=2;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

