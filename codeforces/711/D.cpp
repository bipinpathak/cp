#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p=1e9+7;

ll power(ll a, ll x) {
	ll ans=1;
	while(x) {
		if(x&1) {
			ans=(ans*a)%p;
		}
		x=x>>1;
		a=(a*a)%p;
	}
	return ans;
}
void dfs(int u, vector<int> &next, int d, vector<int> &depth, vector<int> &visited, int &loop) {
	if(visited[u]) {
		return;
	}
	visited[u]=1;
	depth[u]=d;
	d++;
	if(depth[next[u]]) {
		loop=depth[u]-depth[next[u]]+1;
	} else {
		dfs(next[u], next, d, depth, visited, loop);
	}
	depth[u]=0;
	return;
}

void solve() {
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &i : a) {
		cin>>i;
		i--;
	}
	vector<int> visited(n), depth(n);
	int left=n, loop;
	ll ans=1;
	for(int i=0; i<n; i++) {
		if(!visited[i]) {
			loop=0;
			dfs(i, a, 1, depth, visited, loop);
			if(loop) {
				ans=(ans*(power(2, loop)-2))%p;
				left-=loop;
			}
		}
	}
	ans=(ans*power(2, left))%p;
	cout<<ans<<endl;
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}

