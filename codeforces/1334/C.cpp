#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin>>n;
	vector<ll> health(n), damage(n);
	for(int i=0; i<n; i++) {
		cin>>health[i]>>damage[i];
	}
	ll ans=0, start=1e12;
	for(int i=0; i<n; i++) {
		if(health[i]>damage[(i-1+n)%n]) {
			ans+=health[i]-damage[(i-1+n)%n];
			health[i]=damage[(i-1+n)%n];
		}
		start=min(start, health[i]);
	}
	ans+=start;
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

