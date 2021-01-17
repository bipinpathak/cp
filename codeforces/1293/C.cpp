#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, q;
	cin>>n>>q;
	vector<vector<int>> grid(2, vector<int> (n, 0));
	int blocked=0;
	while(q--) {
		int r, c;
		cin>>r>>c;
		r--, c--;
		grid[r][c]=!grid[r][c];
		int change=1;
		if(grid[r][c]==0) {
			change=-1;
		}
		for(int j=c-1; j<=c+1; j++) {
			if(!(j>=0 && j<n)) {
				continue;
			}
			if(grid[(r+1)%2][j]) {
				blocked+=change;
			}
		}
		if(blocked) {
			cout<<"NO"<<endl;
		} else {
			cout<<"YES"<<endl;
		}
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

