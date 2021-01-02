#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int p, int u, ll d, vector<vector<int>> &adjacency, vector<ll> &distances, vector<ll> &value, vector<ll> &child) {
	distances[u]=d;
	for(auto v : adjacency[u]) {
		if(v==p) {
			continue;
		}
		dfs(u, v, d+value[u], adjacency, distances,value, child);
		child[u]+=1+child[v];
	}
	return;
}

void solve() {
	int n, k;
	cin>>n>>k;
	vector<vector<int>> adjacency(n+1);
	for(int i=1; i<n; i++) {
		int u, v;
		cin>>u>>v;
		adjacency[u].push_back(v);
		adjacency[v].push_back(u);
	}
	vector<ll> distances(n+1), value(n+1, 1), child(n+1, 0);
	dfs(0, 1, 0, adjacency, distances, value, child);
	vector<vector<ll>> order;
	for(int i=1; i<=n; i++) {
		order.push_back({distances[i]-child[i], i});	
	}
	sort(order.rbegin(), order.rend());
	for(int i=0; i<k; i++) {
		value[order[i][1]]=0;
	}
	dfs(0, 1, 0, adjacency, distances, value, child);
	ll ans=0;
	for(int i=1; i<=n; i++) {
		if(value[i]==0) {
			ans+=distances[i];
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
    while(t--) {
        solve();
    }
    return 0;
}

