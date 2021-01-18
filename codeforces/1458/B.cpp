#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	double fullSpace=0, fullWater=0;
	cin>>n;
	vector<vector<double>> glasses(n, vector<double> (2)), dp(n+1, vector<double> (10001, -1));
	for(auto &i : glasses) {
		for(auto &j : i) {
			cin>>j;
		}
		fullWater+=i[1];
		fullSpace+=i[0];
	}
	dp[0][0]=0;
	for(auto glass : glasses) {
		for(int total=n; total; total--) {
			for(int curr=glass[0]; curr<=10000; curr++) {
				if(dp[total-1][curr-glass[0]]==-1) {
					continue;
				}
				dp[total][curr]=max(dp[total][curr], dp[total-1][curr-glass[0]]+glass[1]);
			}
		}
	}
	for(int total=1; total<=n; total++) {
		double ans=0;
		for(int capacity=0; capacity<=10000; capacity++) {
			if(dp[total][capacity]==-1) {
				continue;
			}
			ans=max(ans, min((double)capacity, dp[total][capacity]+((fullWater-dp[total][capacity])/2)));
		}
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

