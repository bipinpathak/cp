#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll x;
    cin>>x;
    ll a=x, b=1;
    for(ll i=2; i*i<=x; i++) {
        if(x%i==0 && max(i, x/i)<max(a, b) && __gcd(i, x/i)==1) {
            a=i;
            b=x/i;
        }
    }
    cout<<a<<" "<<b<<endl; 
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
    while(t--) {
        solve();
    }
    return 0;
}

