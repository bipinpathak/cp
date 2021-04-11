#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll p=1e9+7;

ll fac(ll n) {
    ll ans=1;
    while(n) {
        ans=(ans*n)%p;
        n--;
    }
    return ans;
}

ll power(ll a, ll x) {
	ll ans=1;
	while(x) {
		if(x&1) {
			ans=(ans*a)%p;
		}
		x=x>>1;
		a=(a*a)%p;
	}
	return ans;
}

ll modInv(ll a) {
	return power(a, p-2);
}

void solve() {
    int n;
    cin>>n;
    vector<ll> a(n);
    ll total=0;
    for(auto &i : a) {
        cin>>i;
        total+=i;
    }
    if(total%n) {
        cout<<0<<endl;
        return;
    }
    total/=n;
    int source=0, sink=0;
    map<ll, int> count;
    for(auto i : a) {
        if(i<total) {
            sink++;
        }
        if(i>total) {
            source++;
        }
        count[i]++;
    }
    ll ans=fac(n);
    for(auto i : count) {
        ans=(ans*modInv(fac(i.second)))%p;
    }
    if(min(source, sink)>1) {
        ans=(ans*2)%p;
        ans=(ans*fac(source))%p;
        ans=(ans*fac(sink))%p;
        int filled=source+sink;
        ans=(ans*modInv(fac(filled)))%p;
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

