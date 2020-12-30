#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

void solve() {
	ll n, ans=0, p=1e9+7;
	cin>>n;
	vector<ll> a(n), total(60, 0);
	for(auto &i : a) {
		cin>>i;
	}
	vector<vector<ll>> b(n, vector<ll> (60));
	for(ll i=0; i<n; i++) {
		ll one=1;
		for(ll j=0; j<60; j++) {
			if(a[i]&one) {
				b[i][j]=1;
				total[j]++;
			}
			one=one<<1;
		}
	}
	for(ll i=0; i<n; i++) {
		ll AND=0, OR=0, one=1;
		for(ll j=0; j<60; j++) {
			if(b[i][j]) {
				AND=(AND+(total[j]*(one%p))%p)%p;
				OR=(OR+(n*(one%p))%p)%p;
			} else {
				OR=(OR+(total[j]*(one%p))%p)%p;
			}
			one=one<<1;
		}
		ans=(ans+(OR*AND)%p)%p;
	}
	cout<<ans<<endl;
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

