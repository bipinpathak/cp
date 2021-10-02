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

void add(int index, ll val, vector<ll> &a) {
    int n=(int)a.size();
    while(index<n) {
        a[index]=(a[index]+val)%mod;
        index+=index&-index;
    }
    return;
}

ll get(int index, vector<ll> &a) {
    ll ans=0;
    while(index) {
        ans=(ans+a[index])%mod;
        index-=index&-index;
    }
    return ans;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> index(n, vector<int> (2));
    for(int i=0; i<n; i++) {
        cin>>index[i][0];
        index[i][1]=i+1;
    }
    sort(index.begin(), index.end());
    ll ans=0;
    vector<ll> a(n+1);
    for(auto z: index) {
        int i=z[1];
        ll offer=power(2, i);
        offer=(offer*get(i, a))%mod;
        ans=(ans+offer)%mod;
        offer=modInv(power(2, i+1));
        add(i, offer, a);
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
    //cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

