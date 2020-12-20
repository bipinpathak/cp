#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, h, m;
	cin>>n>>h>>m;
	vector<int> a(n+1, h);
	while(m--) {
		int l, r, x;
		cin>>l>>r>>x;
		while(l<=r) {
			a[l]=min(a[l], x);
			l++;
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
		ans+=a[i]*a[i];
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
    while(t--) {
        solve();
    }
    return 0;
}

