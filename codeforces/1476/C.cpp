#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin>>n;
	vector<ll> chains(n), top(n), bottom(n), ans(n);
	ll len=0;
	for(auto &i : chains) {
		cin>>i;
	}
	for(auto &i : top) {
		cin>>i;
	}
	for(auto &i : bottom) {
		cin>>i;
	}
	for(int i=1; i<n; i++) {
		if(top[i]<bottom[i]) {
			swap(top[i], bottom[i]);
		}
		ll gap=top[i]-bottom[i], offer=chains[i]+gap+1;
		if(gap) {
			offer=max(offer, offer+ans[i-1]-2*gap);
		}
		ans[i]=offer;
		len=max(len, ans[i]);
	}
	cout<<len<<endl;
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

