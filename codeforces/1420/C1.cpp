#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n, q;
	cin>>n>>q;
	vector<long long> a(n), plus(n+1), minus(n+1);
	for(auto &i : a) {
		cin>>i;
	}
	for(int i=n-1; i>=0; i--) {
		plus[i]=max(a[i], max(plus[i+1], a[i]+minus[i+1]));
		minus[i]=max(-a[i], max(minus[i+1], -a[i]+plus[i+1]));
	}
	long long ans=plus[0];
	for(int i=1; i<n; i++) {
		ans=max(ans, plus[i]);
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

