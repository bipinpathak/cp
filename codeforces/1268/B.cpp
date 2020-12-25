#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll n;
	cin>>n;
	vector<ll> a(n);
	for(auto &i : a) {
		cin>>i;
	}
	ll even=0, odd=0;
	for(int i=0; i<n; i++) {
		if(i%2) {
			even+=a[i]/2;
			odd+=(a[i]+1)/2;
		} else {
			even+=(a[i]+1)/2;
			odd+=a[i]/2;
		}
	}
	cout<<min(odd, even)<<endl;
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

