#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	ll k;
	cin>>n>>k;
	vector<ll> a(n);
	ll ans=0, sum=0;
	for(auto &i : a) {
		cin>>i;
		sum+=i;
	}
	for(int i=n-1; i; i--) {
		sum-=a[i];
		if(a[i]*100>sum*k) {
			ll original=sum;
			sum=(100*a[i]+k-1)/k;
			ans+=sum-original;
		}
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
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

