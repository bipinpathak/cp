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
	vector<int> a(n);
	for(auto &i : a) {
		cin>>i;
	}
	vector<pair<int, int>> ans, one;
	vector<int> three, two;
	int low=0;
	for(int i=n-1; i>=0; i--) {
		if(a[i]==1) {
			one.push_back({i, low});
			ans.push_back(one.back());
			low++;
		} else if(a[i]==2) {
			if(one.size()==0) {
				cout<<-1<<endl;
				return;
			}
			ans.push_back({i, one.back().s});
			one.pop_back();
			two.push_back(i);
		} else if(a[i]==3) {
			if(three.size()) {
				ans.push_back({three.back(), low});
				three.pop_back();
			} else if(two.size()) {
				ans.push_back({two.back(), low});
				two.pop_back();
			} else if(one.size()) {
				ans.push_back({one.back().f, low});
				one.pop_back();
			} else {
				cout<<-1<<endl;
				return;
			}
			ans.push_back({i, low});
			low++;
			three.push_back(i);
		}
	}
	cout<<ans.size()<<endl;
	for(auto i : ans) {
		cout<<n-i.s<<" "<<i.f+1<<endl;
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
	solve();
    return 0;
}

