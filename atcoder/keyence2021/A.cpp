#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin>>n;
	vector<ll> a(n), b(n);
	for(auto &i : a) {
		cin>>i;
	}
	for(auto &i : b) {
		cin>>i;
	}
	ll first=0, last=0;
	for(int i=0; i<n; i++) {
		first=max(first, a[i]);
		ll curr=max(b[i]*first, last);
		cout<<curr<<endl;
		last=curr;
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
    while(t--) {
        solve();
    }
    return 0;
}

