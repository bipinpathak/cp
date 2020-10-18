#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second
vector<ll> fac(1e6);
ll p=1e9+7;
ll gcd(ll x, ll y) {
	if(x==0) {
		return y;
	}
	return gcd(y%x, x);
}
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
ll modInv(ll a) {
	return power(a, p-2);
}
ll ncr(ll n, ll r) {
	ll ans=1;	
	if(r!=0 && r!=n) {
		ans=fac[n]*modInv(fac[r])%p*modInv(fac[n-r])%p;
	}
	return ans;
}
void pre() {
	fac[0]=1;
	for(int i=1; i<(int) fac.size(); i++) {
		fac[i]=(fac[i-1]*i)%p;
	}
}
void solve() {
	int n;
	cin>>n;
	vector<vector<char>> grid(n, vector<char> (n));
	for(auto &row : grid) {
		for(auto &col : row) {
			cin>>col;
		}
	}
	vector<pair<int, int>> ans;
	if(grid[0][1]==grid[1][0]) {
		if(grid[n-1][n-2]==grid[0][1]) {
			ans.push_back({n-1, n-2});
		}
		if(grid[n-2][n-1]==grid[0][1]) {
			ans.push_back({n-2, n-1});
		}
	} else {
		if(grid[n-1][n-2]==grid[n-2][n-1]) {
			if(grid[0][1]==grid[n-1][n-2]) {
				ans.push_back({0, 1});
			} else {
				ans.push_back({1, 0});
			}
		} else {
			ans.push_back({n-1, n-2});
			if(grid[n-1][n-2]!=grid[0][1]) {
				ans.push_back({0, 1});
			} else {
				ans.push_back({1, 0});			
			}
		}
	}
	cout<<ans.size()<<endl;
	for(auto i : ans) {
		cout<<i.first+1<<" "<<i.second+1<<endl;
	}
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

