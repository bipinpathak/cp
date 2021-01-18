#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cost(int col, int target, vector<vector<int>> &grid) {
	int ans=0;
	for(int y=0; y<(int)grid.size(); y++) {
		int x=grid[y][col];
		ans+=(x^target)&1;	
		target=target>>1;
	}
	return ans;
}

bool satisfy(int a, int b, int len) {
	for(int x=0; x<len-1; x++) {
		int count=(a&1)+((a&2)>>1)+(b&1)+((b&2)>>1);
		if(count%2==0) {
			return false;
		}
		a=a>>1;
		b=b>>1;
	}
	return true;
}

void solve() {
	int n, m;
	cin>>n>>m;
	vector<vector<int>> grid(n);
	for(auto &i : grid) {
		string s;
		cin>>s;
		for(auto j : s) {
			i.push_back(j-'0');
		}
	}
	if(n>=4) {
		cout<<-1<<endl;
		return;
	}
	int states=pow(2, n);
	vector<vector<int>> dp(m, vector<int> (states, 1e6)), good(states);
	for(int curr=0; curr<states; curr++) {
		for(int prev=curr; prev<states; prev++) {
			if(satisfy(curr, prev, n)) {
				good[curr].push_back(prev);
				if(curr!=prev) {
					good[prev].push_back(curr);
				}
			}
		}
	}
	for(int col=0; col<m; col++) {
		for(int curr=0; curr<states; curr++) {
			if(col==0) {
				dp[col][curr]=cost(col, curr, grid);
				continue;
			}
			for(auto prev : good[curr]) {
				dp[col][curr]=min(dp[col][curr], dp[col-1][prev]+cost(col, curr, grid));	
			}
		}
	}
	int ans=1e6;
	for(auto i : dp[m-1]) {
		ans=min(ans, i);
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

