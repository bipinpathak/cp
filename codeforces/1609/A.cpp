#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n);
    ll ans=0, count=0;
    for(auto &i : a) {
        cin>>i;
        while(!(i&1)) {
            count++;
            i>>=1;
        }
    }
    sort(a.begin(), a.end());
    a[n-1]*=((ll)1<<count);
    for(auto i : a) {
        ans+=i;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

