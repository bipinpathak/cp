#include <bits/stdc++.h>
using namespace std;
using ll = long long;

set<ll> cube;

void solve() {
    ll x;
    cin>>x;
    for(ll a=1; 2*a*a*a<=x; a++) {
        ll b=x-a*a*a;
        if(cube.find(b)!=cube.end()) {
            cout<<"YES"<<endl;
            return;
        }   
    }
    cout<<"NO"<<endl;
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
    for(ll a=1; a*a*a<=(ll)1e12; a++) {
        cube.insert(a*a*a);
    }
    while(t--) {
        solve();
    }
    return 0;
}

