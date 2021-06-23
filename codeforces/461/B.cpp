#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod=1e9+7;

ll power(ll a, ll x) {
	ll ans=1;
	while(x) {
		if(x&1) {
			ans=(ans*a)%mod;
		}
		x=x>>1;
		a=(a*a)%mod;
	}
	return ans;
}

ll modInv(ll a) {
	return power(a, mod-2);
}
void dfs(int u, vector<vector<int>> &adjacency, vector<vector<ll>> &dp, vector<int> &x) {
    ll prod=1;
    for(auto v : adjacency[u]) {
        dfs(v, adjacency, dp, x);
        prod=(prod*(dp[v][0]+dp[v][1]))%mod;
    } 
    if(x[u]) {
        dp[u][1]=prod; 
    } else {
        dp[u][0]=prod; 
        for(auto v : adjacency[u]) {
            ll add=dp[v][1];
            add=(add*prod)%mod;
            add=(add*modInv(dp[v][0]+dp[v][1]))%mod;
            dp[u][1]=(dp[u][1]+add)%mod;
        }
    }
    return;
}   

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> adjacency(n);
    for(int i=1; i<n; i++) {
        int p;
        cin>>p;
        adjacency[p].push_back(i);
    }
    vector<int> x(n);
    for(auto &i : x) {
        cin>>i;
    }
    vector<vector<ll>> dp(n, vector<ll> (2));
    dfs(0, adjacency, dp, x);
    cout<<dp[0][1]<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    auto start=clock();
    int t = 1;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    double used= (double) (clock()-start);
    used=(used*1000)/CLOCKS_PER_SEC;
    cerr<<fixed<<setprecision(2)<<used<<" ms"<<endl;
    return 0;
}

