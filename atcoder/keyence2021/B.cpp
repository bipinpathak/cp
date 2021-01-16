#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, k;
	cin>>n>>k;
	vector<int> a(n);
	vector<vector<int>> box(k);
	for(auto &i : a) {
		cin>>i;
	}
	sort(a.begin(), a.end());
	int index=0;
	for(int i=0; i<n; i++) {
		if(i && a[i]!=a[i-1]) {
			index=0;
		}
		box[index].push_back(a[i]);
		index=(index+1)%k;
	}
	ll ans=0;
	for(auto i : box) {
		ll curr=0;
		for(auto j : i) {
			if(j==curr) {
				curr++;
			}
		}
		ans+=curr;
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
    while(t--) {
        solve();
    }
    return 0;
}

