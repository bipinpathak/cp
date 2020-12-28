#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll n, copy;
	cin>>n;
	copy=n;
	set<ll> special;
	special.insert(n);
	while(copy>2) {
		ll prev=sqrt(copy);
		if(prev*prev<copy) {
			prev++;
		}
		special.insert(prev);
		copy=prev;
	}
	vector<vector<ll>> ans;
	for(ll i=3; i<n; i++) {
		if(special.find(i)==special.end()) {
			ans.push_back({i, n});
		}
	}
	vector<ll> f;
	for(auto i : special) {
		f.push_back(i);
	}
	sort(f.begin(), f.end());
	n=f.size();
	for(int i=n-1; i>=1; i--) {
		ans.push_back({f[i], f[i-1]});
		ans.push_back({f[i], f[i-1]});
	}
	
	cout<<ans.size()<<endl;
	for(auto i : ans) {
		cout<<i[0]<<" "<<i[1]<<endl;
	}
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

