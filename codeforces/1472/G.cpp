#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(int u, vector<vector<int>> &road, vector<int> &distance, vector<int> &ans, vector<int> &active) {
	int curr=ans[u];
	active[u]=1;
	for(auto v : road[u]) {
		if(distance[v]>distance[u]) {
			if(!active[v]) {
				dfs(v, road, distance, ans, active);
			}
			curr=min(curr, ans[v]);
		}
	}
	ans[u]=curr;
	return;
}

void solve() {
	int n, m;
	cin>>n>>m;
	vector<vector<int>> road(n);
	vector<int> distance(n, 1e9);
	while(m--) {
		int u, v;
		cin>>u>>v;
		u--, v--;
		road[u].push_back(v);
	}
	priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> dijkstra;
	distance[0]=0;
	dijkstra.push({0, 0});
	while(dijkstra.size()) {
		ll u=dijkstra.top().back(), dist=dijkstra.top().front();
		dijkstra.pop();
		if(distance[u]<dist) {
			continue;
		}
		for(auto v : road[u]) {
			if(distance[v]>distance[u]+1) {
				distance[v]=distance[u]+1;
				dijkstra.push({distance[v], v});
			}
		}
	}
	vector<int> ans=distance, active(n);
	for(int u=0; u<n; u++) {
		for(auto v : road[u]) {
			if(distance[v]<distance[u]) {
				ans[u]=min(ans[u], distance[v]);
			}
		}
	}
	dfs(0, road, distance, ans, active);
	for(auto i : ans) {
		cout<<i<<" ";
	}
	cout<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--) {
		cin.ignore();
        solve();
    }
}
