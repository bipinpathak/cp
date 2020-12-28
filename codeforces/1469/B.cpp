#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, m;
	cin>>n;
	vector<int> a(n);
	for(int i=0; i<n; i++) {
		cin>>a[i];
		if(i) {
			a[i]+=a[i-1];
		}
	}
	cin>>m;
	vector<int> b(m);
	for(int i=0; i<m; i++) {
		cin>>b[i];
		if(i) {
			b[i]+=b[i-1];
		}
	}
	int ans=0;
	for(int first=0; first<=n; first++) {
		for(int second=0; second<=m; second++) {
			int aSum=(first?a[first-1]:0), bSum=(second?b[second-1]:0);
			ans=max(ans, aSum+bSum);
		}
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

