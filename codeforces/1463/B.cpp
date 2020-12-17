#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin>>n;
	vector<ll> a(n);
	ll odd=0, even=0;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		if(i%2) {
			odd+=a[i];
		} else {
			even+=a[i];
		}
	}
	for(int i=0; i<n; i++) {
		int ans=a[i];
		if((i%2) ^ (odd>even)) {
			ans=1;
		}
		cout<<ans<<" ";
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
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

