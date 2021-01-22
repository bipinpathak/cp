#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct cell{
	int r, c;
};
bool custom(cell &a, cell &b) {
	return a.c<b.c;
}
bool solve() {
	int n, m;
	cin>>n>>m;
	vector<cell> blocked(m);
	for(auto &i : blocked) {
		cin>>i.r>>i.c;
	}
	sort(blocked.begin(), blocked.end(), custom);
	vector<vector<int>> grid;
	for(int i=0; i<m; i++) {
		vector<int> curr={0, 0};
		if(blocked[i].r==1) {
			curr[0]=1;
		} else {
			curr[1]=1;
		}
		if(i==0) {
			grid.push_back(curr);
			continue;
		}
		if(blocked[i].c==blocked[i-1].c) {
			grid.back()={1, 1};
			continue;
		}
		if((blocked[i].c-blocked[i-1].c+1)%2) {
			grid.push_back({0, 0});
		}
		grid.push_back(curr);
	}
	n=(int)grid.size();
	vector<vector<bool>> dp(n+1, vector<bool> (3, false));
	dp[0][0]=1;
	for(int i=1; i<=n; i++) {
		if(grid[i-1][0] && grid[i-1][1]) {
			dp[i][0]=dp[i-1][0];
		} else if(grid[i-1][0] && !grid[i-1][1]) {
			dp[i][2]=dp[i-1][0];
			dp[i][0]=dp[i-1][2];
		} else if(!grid[i-1][0] && grid[i-1][1]) {
			dp[i][1]=dp[i-1][0];
			dp[i][0]=dp[i-1][1];
		} else {
			dp[i][0]=dp[i-1][0];
			dp[i][1]=dp[i-1][2];
			dp[i][2]=dp[i-1][1];
		}
		if(!(dp[i][0] || dp[i][1] || dp[i][2])) {
			return false;
		}
	}
    return dp[n][0];
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
		cin.ignore();
        if(solve()) {
			cout<<"YES"<<endl;
        } else {
			cout<<"NO"<<endl;
		}
    }
    return 0;
}

