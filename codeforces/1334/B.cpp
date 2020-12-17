#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll n, x, total=0;
	cin>>n>>x;
	vector<ll> a(n);
	for(auto &i : a) {
		cin>>i;
		total+=i;
	}
	int ans=0;
	sort(a.begin(), a.end());
	for(ll i=0; i<n; i++) {
		if((n-i)*x<=total) {
			ans=n-i;
			break;
		}
		total-=a[i];
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

