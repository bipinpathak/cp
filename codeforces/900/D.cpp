#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod=1e9+7;

ll power(ll a, ll x) {
    x=x%(mod-1);
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

map<ll, ll> store;

ll go(ll n) {
    if(!store.count(n)) {
        ll ans=power(2, n-1);
        if(n>1) {
            ans-=go(1);
        }
        for(ll i=2; i*i<=n; i++) {
            if(n%i==0) {
                ans=(ans-go(i))%mod;
                if(i*i!=n) {
                    ans=(ans-go(n/i))%mod;
                }
            }
        }
        store[n]=ans;
    }
    return store[n];
}

void solve() {
    ll x, y;
    cin>>x>>y;
    ll ans=0;
    if(y%x==0) {
        y/=x;
        ans=go(y);
        if(ans<0) {
            ans+=mod;
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

