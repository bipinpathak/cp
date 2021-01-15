#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool valid(int i, int n) {
	return (i>=0 && i<n);
}

void solve() {
	int n, m, k;
	cin>>n>>m>>k;
	vector<int> a(n);
	for(auto &i : a) {
		cin>>i;
	}
	int ans=0;
	if(k>=m-1) {
		for(int front=0; front<=m-1; front++) {
			if(valid(front, n) && valid(front+n-m, n)) {
				ans=max(ans, max(a[front], a[front+n-m]));
			}
		}
	} else {
		for(int front=0; front<=k; front++) {
			int curr=1e9+1;
			for(int x=0; x<=m-1-k; x++) {
				if(valid(front+x, n) && valid(front+x+n-m, n)) {
					curr=min(curr, max(a[front+x], a[front+x+n-m]));
				}
			}
			if(curr<1e9+1) {
				ans=max(ans, curr);
			}
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

