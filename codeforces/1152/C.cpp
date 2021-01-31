#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll x, ll y) {
	if(x==0) {
		return y;
	}
	return gcd(y%x, x);
}

ll lcm(ll x, ll y) {
	return (x*y)/gcd(x, y);
}

void solve() {
	ll a, b, d;
	cin>>a>>b;
	if(a<b) {
		swap(a, b);
	}
	d=a-b;
	set<ll> gcdValues, possible;
	for(ll i=1; i*i<=d; i++) {
		if(d%i==0) {
			gcdValues.insert(i);
			gcdValues.insert(d/i);
		}
	}
	for(auto i : gcdValues) {
		possible.insert((i-b%i)%i);
	}
	possible.insert(0);
	ll ans=1e9, val=1e18;
	for(auto k : possible) {
		ll option=lcm(a+k, b+k);
		if(option<val) {
			ans=k;
			val=option;
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
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}

