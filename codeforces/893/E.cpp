#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> fac, lp;
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

ll ncr(ll n, ll r) {
	ll ans=1;	
	if(r!=0 && r!=n) {
		ans=fac[n]*modInv(fac[r])%mod*modInv(fac[n-r])%mod;
	}
	return ans;
}

void pre(ll n) {
	ll x=1;
	fac.push_back(x);
	for(ll i=1; i<=n; i++) {
		x=(x*i)%mod;
		fac.push_back(x);
	}
    lp.resize(n+1);
    vector<ll> primes;
    for(ll i=2; i<=n; i++) {
        if(lp[i]==0) {
            lp[i]=i;
            primes.push_back(i);
        }
        for(auto p : primes) {
            if(p>lp[i] || p*i>n) {
                break;
            }
            lp[i*p]=p;
        }
    
    }
	return;
}



void solve() {
    ll x, y;
    cin>>x>>y;
    map<ll, ll> count;
    while(x>1) {
        count[lp[x]]++;
        x/=lp[x];
    }
    ll ans=power(2, y-1);
    for(auto i : count) {
        ans=(ans*ncr(i.second+y-1, i.second))%mod;
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
    cin>>t;
    pre(2e6);
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

