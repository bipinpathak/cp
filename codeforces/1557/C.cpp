#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> fac;
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


void solve() {
    ll n, k;
    cin>>n>>k;
    if(k==0) {
        cout<<1<<endl;
        return;
    }
    ll ans=0, all=1, temp=power(2, n-1);
    if(n%2==0) {
        temp--;
        if(temp<0) {
            temp+=mod;
        }
    }
    for(int i=0; i<k; i++) {
        ll update=(all*temp)%mod;
        if(n%2==0) {
            ans=(ans+(all*power(2, n*(k-1-i))%mod))%mod;
        } else {
            update=(update+all)%mod;
        }
        all=update;
    }
    ans=(ans+all)%mod;
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
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

