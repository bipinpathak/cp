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
	int n, count=1, ans=0;
	string s;
	cin>>n>>s;
	vector<int> gaps;
	for(int i=1; i<n; i++) {
		if(s[i]==s[i-1]) {
			count++;
		} else {
			gaps.push_back(count);
			count=1;
		}
	}
	gaps.push_back(count);
	int surplus=0, i;
	for(i=0; i<(int) gaps.size(); i++) {
		if(gaps[i]==0) {
			continue;
		}
		if(gaps[i]>1) {
			surplus=max(surplus, i+1);
		} else {
			while(surplus<(int) gaps.size()) {
				if(gaps[surplus]>1) {
					gaps[surplus]--;
					break;
				}
				surplus++;
			}
			if(surplus==(int)gaps.size()) {
				break;
			}
		}
		ans++;
	}
	ans+=(gaps.size()-i+1)/2;
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

