#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll mod=1e9+7;

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

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> have(30);
    while(m--) {
        int l, r, x;
        cin>>l>>r>>x;
        for(int i=0; i<30; i++) {
            if(x&1) {
                have[i]=1;
            }
            x>>=1;
        }
    }
    ll ans=0;
    for(int i=0; i<30; i++) {
        if(have[i]) {
            ans=(ans+power(2, n-1+i))%mod;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

