#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin>>n;
	vector<vector<int>> edges;
	vector<int> ans(n-1, -1), count(n, 0);
	for(int i=1; i<n; i++) {
		int u, v;
		cin>>u>>v, u--, v--;
		edges.push_back({u, v});
		count[u]++, count[v]++;
	}
	int key=0;
	for(int i=0; i<n-1; i++) {
		if(count[edges[i][0]]==1 || count[edges[i][1]]==1) {
			ans[i]=key;
			key++;
		}
	}
	for(auto &i : ans) {
		if(i==-1) {
			i=key;
			key++;
		}
		cout<<i<<endl;
	}
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

