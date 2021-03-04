#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll p=1e9+7;

ll power(ll a, ll x) {
	ll ans=1;
	while(x) {
		if(x&1) {
			ans=(ans*a)%p;
		}
		x=x>>1;
		a=(a*a)%p;
	}
	return ans;
}

void solve() {
    ll x, n;
    cin>>x>>n;
    set<ll> primes;
    for(ll i=2; i*i<=x; i++) {
        while(x%i==0) {
            primes.insert(i);
            x/=i;
        }       
    }
    if(x>1) {
        primes.insert(x);
    }
    ll ans=1;
    for(auto pi : primes) {
        ll count=0;
        x=n;
        while(x) {
            x/=pi;
            count=(count+x)%(p-1);
        }
        ans=(ans*power(pi, count))%p;
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
    while(t--) {
        solve();
    }
    return 0;
}

