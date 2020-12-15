#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p=998244353;
ll power(ll a, ll n) {
	ll ans=1, x=a;
	while(n) {
		if(n%2) {
			ans=(ans*x)%p;
		}
		x=(x*x)%p;
		n=n>>1;
	}
	return ans;
}
void solve() {
	ll n;
	cin>>n;
	vector<ll> a(n+1);
	a[1]=1;
	for(int i=2; i<=n; i++) {
		a[i]=(a[i-1]+a[i-2])%p;
	}
	a[n]=(a[n]*power(power(2, n), p-2))%p;
	cout<<a[n]<<endl;
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

