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

ll calc(ll a, ll x, ll k) {
    ll ans=0;
    vector<ll> dp(x+1);
    dp[x]=1;
    while(k--) {
        ll add=0;
        for(ll curr=x; curr>=0; curr--) {
            add=(add+(dp[curr]*modInv(curr+1))%mod)%mod;
            dp[curr]=add;
        }
    }
    ll val=1;
    for(ll curr=0; curr<=x; curr++) {
        ans=(ans+(val*dp[curr])%mod)%mod;
        val=(val*a)%mod;
    }
    return ans;
}

void solve() {
    ll n, k;
    cin>>n>>k;
    vector<vector<ll>> p;
    ll m=0;
    for(ll i=2; i*i<=n; i++) {
        if(n%i) {
            continue;
        }
        ll count=0;
        while(n%i==0) {
            count++;
            n/=i;
        }
        p.push_back({i, count});
        m=max(m, count);
    }
    if(n>1) {
        p.push_back({n, 1});
        m=max(m, (ll)1);
    }
    ll ans=1;
    for(auto i : p) {
        ans=(ans*calc(i[0], i[1], k))%mod;
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

