#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, k;
	cin>>n>>k;
	vector<int> a(k);
	for(auto &i : a) {
		cin>>i;
	}
	vector<int> up(n+1, 1), down(n+1, 1);
	set<int> seen;
	for(int i=k-1; i>=0; i--) {
		int num=a[i];
		if(up[num] && seen.find(num+1)!=seen.end()) {
			up[num]=0;
		}
		if(down[num] && seen.find(num-1)!=seen.end()) {
			down[num]=0;
		}
		seen.insert(num);
	}
	set<vector<int>> ans;
	for(int i=1; i<=n; i++) {
		if(seen.find(i)==seen.end()) {
			ans.insert({i, i});
		}
		if(up[i] && i+1<=n) {
			ans.insert({i, i+1});
		}
		if(down[i] && i-1>=1) {
			ans.insert({i, i-1});
		}
	}
	cout<<ans.size()<<endl;
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

