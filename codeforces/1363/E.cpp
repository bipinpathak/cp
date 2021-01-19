#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
	int curr, target;
	ll cost;
};
void dfs(int p, int u, int &one, int &zero, ll cost, vector<vector<int>> &adjacency, ll &ans, vector<node> &a) {
	cost=min(cost, a[u].cost);
	a[u].cost=cost;
	for(auto v : adjacency[u]) {
		if(v==p) {
			continue;
		}
		int belowOne=0, belowZero=0;
		dfs(u, v, belowOne, belowZero, cost, adjacency, ans, a);
		one+=belowOne;
		zero+=belowZero;
	}
	if(a[u].curr!=a[u].target) {
		if(a[u].target) {
			one++;
		} else {
			zero++;
		}
	}
	if(one && zero) {
		ll settle=min(one, zero);
		ans+=2*settle*a[u].cost;
		one-=settle;
		zero-=settle;
	}
	return;
}

void solve() {
	int n;
	cin>>n;
	vector<node> a(n);
	for(auto &i : a) {
		cin>>i.cost>>i.curr>>i.target;
	}
	vector<vector<int>> adjacency(n);
	for(int i=1; i<n; i++) {
		int u, v;
		cin>>u>>v, u--, v--;
		adjacency[u].push_back(v);
		adjacency[v].push_back(u);
	}
	ll ans=0;
	int one=0, zero=0;
	dfs(-1, 0, one, zero, 1e9, adjacency, ans, a);
	if(one || zero) {
		ans=-1;
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

