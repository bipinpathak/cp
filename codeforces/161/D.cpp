#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> go(int u, vector<vector<int>> &adjacency, vector<int> &visited, int k, ll &ans) {
	vector<ll> child(k+1);
	child[0]=1;
	visited[u]=1;
	for(auto v : adjacency[u]) {
		if(visited[v]) {
			continue;
		}
		vector<ll> option=go(v, adjacency, visited, k, ans);
		for(int i=0; i<=k; i++) {
			ans+=child[i]*option[k-i];	
			child[i]+=option[i];
		}
	}
	for(int i=k; i; i--) {
		child[i]=child[i-1];
	}
	child[0]=0;
	return child;
}

void solve() {
	int n, k;
	cin>>n>>k;
	vector<vector<int>> adjacency(n);
	for(int i=0; i<n-1; i++) {
		int u, v;
		cin>>u>>v, u--, v--;
		adjacency[u].push_back(v);
		adjacency[v].push_back(u);
	}
	vector<int> visited(n, 0);
	ll ans=0;
	go(0, adjacency, visited, k, ans);
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

