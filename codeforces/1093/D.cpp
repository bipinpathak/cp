#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll p=998244353;

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
void go(int u, vector<vector<int>> &adjacency, vector<int> &parity, int &odd, int &even) {
    if(parity[u]) {
        odd++;
    } else {
        even++;
    }
    for(auto v : adjacency[u]) {
        if(parity[v]==-1) {
            parity[v]=!parity[u];
            go(v, adjacency, parity, odd, even);
        }  else if(parity[u]==parity[v]) {
            even=odd=0;
        }
        if(max(odd, even)==0) {
            break;
        }
    }
    return;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adjacency(n);
    while(m--) {
        int x, y;
        cin>>x>>y;
        x--;
        y--;
        adjacency[x].push_back(y);
        adjacency[y].push_back(x);
    }
    vector<int> parity(n, -1);
    ll ans=1;
    for(int u=0; u<n; u++) {
        if(parity[u]!=-1) {
            continue;
        }
        if(adjacency[u].empty()) {
            ans=(ans*3)%p;
            continue;
        }
        int odd=0, even=0;
        parity[u]=0;
        go(u, adjacency, parity, odd, even);
        if(max(odd, even)==0) {
            ans=0;
            break;
        }
        ll curr=(power(2, even)+power(2, odd))%p;
        ans=(ans*curr)%p;
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
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}

