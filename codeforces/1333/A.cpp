#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, m;
	cin>>n>>m;
	vector<vector<char>> grid(n, vector<char> (m, 'B'));
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if((i+j)%2) {
				grid[i][j]='W';
			}
		}
	}
	if((n*m)%2==0) {
		if(n%2==0) {
			grid[n-1][0]='B';
		} else {
			grid[0][m-1]='B';
		}
	}
	for(auto row : grid) {
		for(auto col : row) {
			cout<<col;
		}
		cout<<endl;
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
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

