#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll n;
	cin>>n;
	vector<ll> a(n);
	ll sum=0;
	for(auto &i : a) {
		cin>>i;
		sum+=i;
	}
	for(ll len=n; len; len--) {
		if(sum%len) {
			continue;
		}
		vector<ll> ans(1, 0);
		ll target=sum/len, i=0;
		for(i=0; i<n; i++) {
			if(ans.back()<target) {
				ans.back()+=a[i];
			} else if(ans.back()==target) {
				ans.push_back(a[i]);
			} else {
				break;
			}
		}
		if(i==n && ans.back()==target) {
			cout<<n-len<<endl;
			return;
		}
	}
	cout<<n-1<<endl;
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

