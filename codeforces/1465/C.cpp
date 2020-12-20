#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void go(int head, int curr, int &ans, vector<int> &a) {
	if(curr==head) {
		ans++;
	} else if(a[curr]) {
		ans++;
		go(head, a[curr], ans, a);
	}
	a[curr]=0;
	return;
}

void solve() {
	int n, m;
	cin>>n>>m;
	vector<int> a(n+1, 0);
	while(m--) {
		int x, y;
		cin>>x>>y;
		a[x]=y;
	}
	int ans=0;
	for(int i=1; i<=n; i++) {
		if(a[i] && a[i]!=i) {
			ans++;
			go(i, a[i], ans, a);
			a[i]=0;
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

