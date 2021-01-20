#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin>>n;
	vector<int> a(n+1), prefix(n+1);
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		prefix[i]=prefix[i-1]+a[i];
	}
	prefix[0]=1e7;
	int ans=0;
	for(int key=30; key; key--) {
		vector<int> best(n+1, 1e9);
		int index=0;
		best[0]=0;
		for(int i=1; i<=n; i++) {
			if(a[i]<=key) {
				best[i]=min(best[i-1], prefix[i]);
			}
			if(a[i]>=key) {
				index=i;
			}
			if(index==0) {
				continue;
			}
			ans=max(ans, prefix[i]-best[index]-a[index]);
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
    while(t--) {
        solve();
    }
    return 0;
}

