#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int u, int p, stack<int> &path, vector<int> &visited, vector<vector<int>> &adjacency, unordered_set<int> &cycle) {
	path.push(u);
	visited[u]=1;
	for(auto next : adjacency[u]) {
		if(next==p) {
			continue;
		}
		if(!visited[next]) {
			dfs(next, u, path, visited, adjacency, cycle);
		} else {
			while(path.top()!=next) {
				cycle.insert(path.top());
				path.pop();
			}
			cycle.insert(next);
		}
		if(cycle.size()) {
			return;
		}
	}
	path.pop();
	return;
}

ll count(int node, vector<vector<int>> &adjacency, vector<int> &visited) {
	visited[node]=1;
	ll ans=1;
	for(auto next : adjacency[node]) {
		if(!visited[next]) {
			ans+=count(next, adjacency, visited);
		}
	}
	return ans;
}

void solve() {
	int n;
	cin>>n;
	vector<vector<int>> adjacency(n);
	for(int i=0; i<n; i++) {
		int u, v;
		cin>>u>>v; u--, v--;
		adjacency[u].push_back(v);
		adjacency[v].push_back(u);
	}
	vector<int> visited(n);
	stack<int> path;
	unordered_set<int> cycle;
	dfs(0, -1, path, visited, adjacency, cycle);
	for(int i=0; i<n; i++) {
		if(cycle.find(i)==cycle.end()) {
			visited[i]=0;
		} else {
			visited[i]=1;
		}
	}
	ll ans=0;
	for(auto node : cycle) {
		ll hanging=1;
		for(auto next : adjacency[node]) {
			if(!visited[next]) {
				hanging+=count(next, adjacency, visited);
			}
		}
		ans+=hanging*(2*n-hanging-1);
	}
	ans/=2;
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

