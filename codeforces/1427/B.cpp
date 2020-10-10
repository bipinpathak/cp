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
	int n, k;
	string s;
	cin>>n>>k>>s;
	vector<int> gaps;
	int z=0, start=0, end=0, ans=0, win=0;
	for(auto i : s) {
		if(i=='L') {
			z++;
			win=0;
		} else if(z) {
			gaps.push_back(z);
			z=0;
		}
		if(i=='W') {
			win=min(2, win+1);
		}
		ans+=win;
	}
	if(k==0) {
		cout<<ans<<endl;
		return;
	}
	if(z==n) {
		cout<<2*k-1<<endl;
		return;
	}
	if(z) {
		end=z;
	}
	if(s[0]=='L' && gaps.size()) {
		start=gaps[0];
		reverse(gaps.begin(), gaps.end());
		gaps.pop_back();
		reverse(gaps.begin(), gaps.end());
	}
	sort(gaps.rbegin(), gaps.rend());
	while(gaps.size() && k>=gaps.back()) {
		ans+=2*gaps.back()+1;
		k-=gaps.back();
		gaps.pop_back();
	}
	if(start) {
		gaps.push_back(start);
	}
	if(end) {
		gaps.push_back(end);
	}
	while(k && gaps.size()) {
		int add=min(k, gaps.back());
		k-=add;
		ans+=2*add;
		gaps.pop_back();
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
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

