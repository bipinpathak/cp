#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool fair(ll n) {
	ll c=n;
	while(c) {
		ll div=c%10;
		c/=10;
		if(div && n%div) {
			return 0;
		}
	}
	return 1;
}

void solve() {
	ll n;
	cin>>n;
	while(!fair(n)) {
		n++;
	}
	cout<<n<<endl;
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

