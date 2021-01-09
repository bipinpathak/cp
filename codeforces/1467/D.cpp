#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int p=1e9+7;

void solve() {
	int n, k, q;
	cin>>n>>k>>q;
	k++;
	vector<ll> a(n);
	for(auto &i : a) {
		cin>>i;
	}
	ll start[n][k+1], contribution[n]; 
	for(int length=1; length<=k; length++) {
		for(int i=0; i<n; i++) {
			if(length==1) {
				start[i][length]=1;
			} else {
				start[i][length]=((i?start[i-1][length-1]:0)+((i+1)<n?start[i+1][length-1]:0))%p;
			}
		}
	}
	for(int i=0; i<n; i++) {
		contribution[i]=(2*start[i][k])%p;
		for(int j=2; j<k; j++) {
			int left=j-1, right=k-j;
			if(i-1>=0) {
				contribution[i]=(contribution[i]+(start[i-1][left]*start[i-1][right])%p)%p;
			}
			if(i+1<n) {
				contribution[i]=(contribution[i]+(start[i+1][left]*start[i+1][right])%p)%p;
			}
			if(i-1>=0 && i+1<n) {
				contribution[i]=(contribution[i]+(start[i+1][left]*start[i-1][right])%p)%p;
				contribution[i]=(contribution[i]+(start[i-1][left]*start[i+1][right])%p)%p;
			}
		}
	}
	ll ans=0;
	for(int i=0; i<n; i++) {
		ans=(ans+(contribution[i]*a[i])%p)%p;
	}
	while(q--) {
		ll i, x;
		cin>>i>>x;
		i--;
		ans=(ans+p+(contribution[i]*(x-a[i]))%p)%p;
		a[i]=x;
		cout<<ans<<endl;
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
    while(t--) {
        solve();
    }
    return 0;
}

