#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll n, x, ans=0, low=100;
	cin>>n>>x;
	vector<ll> a(n);
	for(auto &i : a) {
		cin>>i;
		ans+=i;
		ll count=0, copy=i;
		while(copy%x==0) {
			copy/=x;
			count++;
		}
		low=min(low, count);
	}
	ll curr=low+1;
	for(auto &i : a) {
		if(curr==0) {
			break;
		}
		ll count=0, copy=i;
		while(copy%x==0) {
			copy/=x;
			count++;
		}
		ans+=min(curr, count)*i;
		if(count==low) {
			curr=low;
		}
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

