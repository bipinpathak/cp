#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll mod=998244353;

ll power(ll a, ll x) {
    a%=mod;
    if(a==0) {
        return a;
    }
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

void solve() {
    int n;
    cin>>n;
    int m=1e6;
    vector<int> f(m);
    vector<vector<int>> choices(n);
    for(int i=0; i<n; i++) {
        int k;
        cin>>k;
        while(k--) {
            int a;
            cin>>a;
            a--;
            f[a]++;
            choices[i].push_back(a);
        }
    }
    ll ans=0;
    for(int i=0; i<n; i++) {
        ll add=0;
        for(auto &j : choices[i]) {
            add+=f[j];
            if(add>=mod) {
                add-=mod;
            }
        }
        add=(add*modInv(choices[i].size()))%mod;
        add=(add*modInv(n))%mod;
        add=(add*modInv(n))%mod;
        ans+=add;
        if(ans>=mod) {
            ans-=mod;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

