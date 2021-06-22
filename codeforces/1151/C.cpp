#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod=1e9+7;

ll power(ll a, ll x) {
	ll ans=1;
	while(x) {
		if(x&1) {
			ans=(ans*a)%mod;
		}
		x=x>>1;
		a=(a*a)%mod;
	}
	return ans;
}

ll modInv(ll a) {
	return power(a, mod-2);
}


ll sum(ll a, ll n, ll d) {
    a%=mod;
    n%=mod;
    d%=mod;
    ll ans=(n*modInv(2))%mod;
    ans=(ans*(2*a+(n-1)*d)%mod)%mod;
    return ans;
}

ll calc(ll n) {
    ll need=1, even=0, odd=0;
    int step=1;
    while(n) {
        need=min(need, n);
        if(step) {
            odd+=need;
        } else {
            even+=need;
        }
        n-=need;
        step=!step;
        need*=2;
    }
    return (sum(1, odd, 2)+sum(2, even, 2))%mod;
}

void solve() {
    ll l, r;
    cin>>l>>r;
    ll ans=calc(r)-calc(l-1);
    ans=(ans+mod)%mod;
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

