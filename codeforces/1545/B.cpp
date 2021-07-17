#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> fac;
ll mod=998244353;

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

void pre(int n) {
	ll x=1;
	fac.push_back(x);
	for(ll i=1; i<=n; i++) {
		x=(x*i)%mod;
		fac.push_back(x);
	}
	return;
}


void solve() {
    int n;
    string s;
    cin>>n>>s;
    int cpairs=0, zero=0, active=0;
    for(auto i : s) {
        if(i=='0') {
            zero++;
            active=0;
        } else {
            active++;
        }
        if(active>1) {
            cpairs++;
            active-=2;
        }
    }
    cout<<ncr(cpairs+zero, zero)<<endl;
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
    pre(1e5);
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

