#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll n, m;
	cin>>n>>m;
	vector<ll> a(n), b(m);
	for(auto &i : a) {
		cin>>i;
	}
	for(auto &i : b) {
		cin>>i;
	}
	if(n>1) {
		sort(a.begin(), a.end());
		for(ll i=1; i<n; i++) {
			a[i]-=a[0];
		}
		ll s=a[1];
		for(ll i=2; i<n; i++) {
			s=__gcd(s, a[i]);
		}
		for(auto &i : b) {
			i=__gcd(i+a[0], s);
		}
	} else {
		for(ll i=0; i<m; i++) {
			b[i]+=a[0];
		}
	}
	for(auto &j : b) {
		cout<<j<<" ";
	}
	cout<<endl;
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
    while(t--) {
        solve();
    }
    return 0;
}

