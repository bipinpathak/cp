#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, k;
ll cost[101][101], dp[101][101][101];

ll fetch(int pos, int color, int count) {
	if(!(pos && count)) {
		if(pos==count) {
			return 0;
		} else {
			return 1e12;
		}
	}
	if(dp[pos][color][count]==-1) {
		ll offer=1e15;
		for(int prev=1; prev<=m; prev++) {
			if(prev==color) {
				offer=min(offer, fetch(pos-1, prev, count)+cost[pos][color]);
			} else {
				offer=min(offer, fetch(pos-1, prev, count-1)+cost[pos][color]);
			}
		}
		dp[pos][color][count]=offer;
	}
	return dp[pos][color][count];
}

void solve() {
	cin>>n>>m>>k;
	int color[n+1];
	for(int i=1; i<=n; i++) {
		cin>>color[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin>>cost[i][j];
		}
	}
	for(int i=1; i<=n; i++) {
		if(color[i]==0) {
			continue;
		}
		for(int j=1; j<=m; j++) {
			cost[i][j]=(j==color[i])?0:1e12;
		}
	}
	for(int pos=1; pos<=n; pos++){
		for(int color=1; color<=m; color++) {
			for(int count=1; count<=k; count++) {
				dp[pos][color][count]=-1;
			}
		}
	}
	ll ans=1e12;
	if(n==1) {
		if(k==1) {
			for(int j=1; j<=m; j++) {
				ans=min(ans, cost[1][j]);
			}
			cout<<ans<<endl;
		} else {
			cout<<-1<<endl;
		}
		return;
	}
	for(int i=1; i<=m; i++) {
		ans=min(ans, fetch(n, i, k));
	}
	if(ans>1e11) {
		ans=-1;
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

