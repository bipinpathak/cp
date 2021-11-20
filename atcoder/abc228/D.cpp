#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    set<ll> avail;
    ll n=1<<20;
    for(ll i=0; i<n; i++) {
        avail.insert(i);
    }
    map<ll, ll> done;
    ll q;
    cin>>q;
    while(q--) {
        ll t, x;
        cin>>t>>x;
        if(t==1) {
            ll val=x, index=*avail.begin();
            x%=n;
            if(avail.lower_bound(x)!=avail.end()) {
                index=*avail.lower_bound(x);
            }
            avail.erase(index);
            done[index]=val;
        } else {
            x%=n;
            if(done.count(x)) {
                cout<<done[x];    
            } else {
                cout<<-1;
            }
            cout<<endl;
        }
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

