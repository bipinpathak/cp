#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void go(ll n, vector<int> &factors) {
	for(ll i=1; i*i<=n; i++) {
		if(n%i==0) {
			factors.push_back(i);
			if(n/i>i) {
				factors.push_back(n/i);
			}
		}
	}
	return;
}

void withRoot(int p, int u, vector<vector<int>> &adjacency, vector<int> &a, vector<int> &count, vector<int>&factors, vector<int> &ans, int d) {
	for(auto i : factors) {
		if(a[u]%i==0) {
			count[i]++;
		}
	}
	for(auto v : adjacency[u]) {
		if(v==p) {
			continue;
		}
		withRoot(u, v, adjacency, a, count, factors, ans, d+1);
	}
	for(auto i : factors) {
		if(count[i]==d) {
			ans[u]=max(ans[u], i);
		}
		if(a[u]%i==0) {
			count[i]--;
		}
	}
	return;
}

void withoutRoot(int p, int u, int g, vector<vector<int>> &adjacency, vector<int> &a, vector<int> &ans) {
	g=__gcd(g, a[u]);
	for(auto v : adjacency[u]) {
		if(v==p) {
			continue;
		}
		withoutRoot(u, v, g, adjacency, a, ans);
	}
	ans[u]=max(ans[u], g);
	return;
}

void solve() {
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &i : a) {
		cin>>i;
	}
	vector<vector<int>> adjacency(n);
	for(int i=0; i<n-1; i++) {
		int x, y;
		cin>>x>>y, x--, y--;
		adjacency[x].push_back(y);
		adjacency[y].push_back(x);
	}
	vector<int> factors, count(a[0]+1, 0), ans(n, 0);
	go(a[0], factors);
	sort(factors.rbegin(), factors.rend());
	for(auto i : factors) {
		count[i]++;
	}
	for(auto v : adjacency[0]) {
		withRoot(0, v, adjacency, a, count, factors, ans, 1);
	}
	for(auto v : adjacency[0]) {
		withoutRoot(0, v, 0, adjacency, a, ans);
	}
	ans[0]=a[0];
	for(auto i : ans) {
		cout<<i<<" ";
	}
	cout<<endl;
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

