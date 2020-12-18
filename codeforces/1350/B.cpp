#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

set<int> go(int n) {
	set<int> ans;
	for(int i=1; i*i<=n; i++) {
		if(n%i) {
			continue;
		}
		ans.insert(i);
		ans.insert(n/i);
	}
	return ans;
}

void solve() {
	int n;
	cin>>n;
	vector<vector<ll>> a(n, vector<ll> (2, 0));
	for(int i=0; i<n; i++) {
		cin>>a[i][0];
		a[i][1]=i+1;
	}
	sort(a.begin(), a.end());
	vector<vector<int>> count(n, vector<int> (2, 0));
	for(int i=0; i<n; i++) {
		set<int> factors=go(a[i][1]);
		for(auto j : factors) {
			j--;
			if(count[j][1]<a[i][0]) {
				count[a[i][1]-1][0]=max(count[a[i][1]-1][0], count[j][0]+1);
			}
			count[a[i][1]-1][1]=a[i][0];
		}
	}
	int ans=0;
	for(auto i :count) {
		ans=max(ans, i[0]);
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

