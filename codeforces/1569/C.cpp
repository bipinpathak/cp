#include "bits/stdc++.h"
using namespace std;
using ll = long long;

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

vector<ll> fac, invFac;

ll ncr(ll n, ll r) {
	ll ans=1;	
	if(r!=0 && r!=n) {
		ans=fac[n];
        ans=(ans*invFac[r])%mod;
        ans=(ans*invFac[n-r])%mod;
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
    invFac.resize(n+1);
    invFac[n]=modInv(fac[n]);
    for(int i=n-1; i>=0; i--) {
        invFac[i]=((i+1)*invFac[i+1])%mod;
    }
	return;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i : a) {
        cin>>i;
    }
    sort(a.rbegin(), a.rend());
    ll ans=0;
    if(a[0]-a[1]<=1) {
        if(a[0]==a[1]) {
            ans=fac[n];
        } else {
            int count=0;
            for(int i=1; i<n && a[i]==a[1]; i++) {
                count++;
            }
            ans=(count*fac[count])%mod;
            ans=(ans*fac[n-count-1])%mod;
            ans=(ans*ncr(n, count+1))%mod;
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
    int t = 1;
    cin>>t;
    pre(200000);
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

