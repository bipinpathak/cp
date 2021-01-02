#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll n;
	cin>>n;
	vector<ll> ans;
	ll one=1;
	while(n) {
		if(n>=one) {
			ans.push_back(one);
		} else {
			ans.push_back(n);
		}
		n-=ans.back();
		one*=2;
	}
	sort(ans.begin(), ans.end());
	n=ans.size();
	cout<<n-1<<endl;
	for(int i=1; i<n; i++) {
		cout<<ans[i]-ans[i-1]<<" ";
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

