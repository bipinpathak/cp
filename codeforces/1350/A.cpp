#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll n, k;
	cin>>n>>k;
	if(n%2) {
		for(ll i=2; i<=n; i++) {
			if(n%i==0) {
				n+=i;
				break;
			}
		}
		k--;
	}
	n+=2*k;
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

