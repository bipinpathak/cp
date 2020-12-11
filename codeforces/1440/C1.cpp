#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> fac;
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
void pre(int n) {
	ll x=1;
	fac.push_back(x);
	for(ll i=1; i<=n; i++) {
		x=(x*i)%p;
		fac.push_back(x);
	}
	return;
}

//Useful code starts//

void handle(vector<vector<int>> &a, vector<vector<int>> &ans, vector<vector<int>> &one, vector<vector<int>> &zero) {
	if(one.size()==4) {
		ans.push_back({});
		for(int k=0; k<3; k++) {
			ans.back().push_back(one.back()[0]);
			ans.back().push_back(one.back()[1]);
			zero.push_back(one.back());
			one.pop_back();
		}
	}
	if(one.size()==1) {
		ans.push_back({one[0][0], one[0][1]});
		zero.push_back(one[0]);
		one.pop_back();
		reverse(zero.begin(), zero.end());
		for(int k=0; k<2; k++) {
			ans.back().push_back(zero.back()[0]);
			ans.back().push_back(zero.back()[1]);
			one.push_back(zero.back());
			zero.pop_back();
		}
	}
	if(one.size()==2) {
		ans.push_back({one.back()[0], one.back()[1]});
		zero.push_back(one.back());
		one.pop_back();
		reverse(zero.begin(), zero.end());
		for(int k=0; k<2; k++) {
			ans.back().push_back(zero.back()[0]);
			ans.back().push_back(zero.back()[1]);
			one.push_back(zero.back());
			zero.pop_back();
		}
	}
	if(one.size()==3) {
		ans.push_back({});
		for(int k=0; k<3; k++) {
			ans.back().push_back(one.back()[0]);
			ans.back().push_back(one.back()[1]);
			zero.push_back(one.back());
			one.pop_back();
		}
	}
	for(auto k : zero) {
		a[k[0]][k[1]]=0;
	}
	return;
}

void solve() {
	int n, m;
	cin>>n>>m;
	vector<vector<int>> a(n, vector<int> (m));
	for(int i=0; i<n; i++) {
		string s;
		cin>>s;
		for(int j=0; j<m; j++) {
			a[i][j]=s[j]-'0';
		}
	}
	vector<vector<int>> ans;
	if(n%2) {
		for(int j=0; j+1<m; j++) {
			if(!a[n-1][j]) {
				continue;
			}
			vector<vector<int>> one, zero;
			for(int x=n-2; x<n; x++) {
				for(int y=j; y<j+2; y++) {
					if(a[x][y]) {
						one.push_back({x, y});
					} else {
						zero.push_back({x, y});
					}
				}
			}
			if(one.size()) {
				handle(a, ans, one, zero);
			}
		}
	}
	if(m%2) {
		for(int i=0; i+1<n; i++) {
			if(!a[i][m-1]) {
				continue;
			}
			vector<vector<int>> one, zero;
			for(int x=i; x<i+2; x++) {
				for(int y=m-2; y<m; y++) {
					if(a[x][y]) {
						one.push_back({x, y});
					} else {
						zero.push_back({x, y});
					}
				}
			}
			if(one.size()) {
				handle(a, ans, one, zero);
			}
		}
	}
	if(a[n-1][m-1]) {
		vector<vector<int>> one, zero;
		for(int x=n-2; x<n; x++) {
			for(int y=m-2; y<m; y++) {
				if(a[x][y]) {
					one.push_back({x, y});
				} else {
					zero.push_back({x, y});
				}
			}
		}
		if(one.size()) {
			handle(a, ans, one, zero);
		}
	}
	for(int i=0; i+1<n; i+=2) {
		for(int j=0; j+1<m; j+=2) {
			vector<vector<int>> one, zero;
			for(int x=i; x<i+2; x++) {
				for(int y=j; y<j+2; y++) {
					if(a[x][y]) {
						one.push_back({x, y});
					} else {
						zero.push_back({x, y});
					}
				}
			}
			if(one.size()) {
				handle(a, ans, one, zero);
			}
		}
	}
	cout<<ans.size()<<endl;
	for(auto operation : ans) {
		for(auto i : operation) {
			cout<<i+1<<" ";
		}
		cout<<endl;
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

