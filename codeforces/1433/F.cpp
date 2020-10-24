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
	int n, m, k;
	cin>>n>>m>>k;
	vector<vector<int>> a(n, vector<int> (m));
	for(auto &row : a) {
		for(auto &col : row) {
			cin>>col;
		}
	}
	vector<vector<int>> row(n, vector<int> (k));
	for(int i=0; i<n; i++) {
		vector<vector<int>> curr(k, vector<int> (m/2+1));
		for(int j=0; j<m; j++) {
			for(int count=m/2-1; count>=0; count--) {
				for(int rem=0; rem<k; rem++) {
					if(curr[rem][count]%k==rem) {
						int option=curr[rem][count]+a[i][j];
						curr[option%k][count+1]=max(curr[option%k][count+1], option);
					}
				}
			}
		}
		for(int rem=0; rem<k; rem++) {
			for(auto option : curr[rem]) {
				row[i][rem]=max(row[i][rem], option);
			}
		}
	}
	vector<int> optimal(k);
	for(int i=0; i<n; i++) {
		vector<int> update(k);
		for(int p=0; p<k; p++) {
			for(int q=0; q<k; q++) {
				if(optimal[p]%k==p && row[i][q]%k==q) {
					update[(p+q)%k]=max(update[(p+q)%k], optimal[p]+row[i][q]);
				}
			}
		}
		optimal=update;
	}
	cout<<optimal[0]<<endl;
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
