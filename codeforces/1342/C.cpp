#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll a, b, q, lcm;
	cin>>a>>b>>q;
	if(a>b) {
		swap(a, b);
	}
	lcm=(a*b)/__gcd(a, b);
	while(q--) {
		ll l, r, ans=0;
		cin>>l>>r;
		ll start=l/lcm, end=r/lcm;
		ans=(end-start+1)*b;
		ans-=min(b, l%lcm);
		if(r%lcm<b-1) {
			ans-=b-1-r%lcm;
		}
		cout<<r-l+1-ans<<" ";
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

