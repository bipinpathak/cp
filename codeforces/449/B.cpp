#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool custom(vector<ll> &a, vector<ll> &b) {
	return a[1]>b[1];
}

void solve() {
	ll n, m, k;
	cin>>n>>m>>k;
	vector<vector<pair<int, ll>>> roads(n+1);
	vector<vector<ll>> trains(k, vector<ll> (2));
	while(m--) {
		int u, v, w;
		cin>>u>>v>>w;
		roads[u].push_back({v, w});
		roads[v].push_back({u, w});
	}
	for(auto &train : trains) {
		for(auto &i : train) {
			cin>>i;
		}
	}
	sort(trains.begin(), trains.end(), custom);
	vector<ll> distance(n+1, 1e18);
	priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> dijkstra;
	int ans=k;
	distance[1]=0;
	dijkstra.push({0, 1});
	while(dijkstra.size() && trains.size()) {
		while(trains.size() && trains.back().back()<distance[dijkstra.top().back()]) {
			ll node=trains.back().front();
			ll dist=trains.back().back();
			if(distance[node]>dist) {
				distance[node]=dist;
				dijkstra.push({dist, node});
				ans--;
			}
			trains.pop_back();
		}
		if(trains.size()==0) {
			break;
		}
		ll u=dijkstra.top().back(), dist=dijkstra.top().front();
		dijkstra.pop();
		if(distance[u]<dist) {
			continue;
		}
		for(auto v : roads[u]) {
			int node=v.first;
			ll w=v.second;
			if(distance[u]+w<distance[node]) {
				distance[node]=w+distance[u];
				dijkstra.push({distance[node], node});
			}
		}
	}
	cout<<ans<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    while(t--) {
        solve();
    }
    return 0;
}
