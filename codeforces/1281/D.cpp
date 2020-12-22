#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void go(int &rowMax, int &colMax, vector<string> grid) {
	int n=grid.size(), m=grid[0].size();
	for(int i=0; i<n; i++) {
		int sum=0;
		for(int j=0; j<m; j++) {
			if(grid[i][j]=='A') {
				sum++;
			}
		}
		rowMax=max(rowMax, sum);
	}
	for(int j=0; j<m; j++) {
		int sum=0;
		for(int i=0; i<n; i++) {
			if(grid[i][j]=='A') {
				sum++;
			}
		}
		colMax=max(colMax, sum);
	}
	return;
}

void solve() {
	int r, c;
	cin>>r>>c;
	vector<string> grid(r);
	for(auto &i : grid) {
		cin>>i;
	}
	int awesome=0;
	for(auto i : grid) {
		for(auto j : i) {
			if(j=='A') {
				awesome++;
			}
		}
	}
	if(awesome==r*c) {
		cout<<0<<endl;
	} else if(awesome==0) {
		cout<<"MORTAL"<<endl;
	} else {
		int left=0, right=0, bottom=0, top=0, rowMax=0, colMax=0;
		go(rowMax, colMax, grid);
		for(int i=0; i<r; i++) {
			if(grid[i][0]=='A') {
				left++;
			}
			if(grid[i][c-1]=='A') {
				right++;
			}
		}
		for(int i=0; i<c; i++) {
			if(grid[0][i]=='A') {
				top++;
			}
			if(grid[r-1][i]=='A') {
				bottom++;
			}
		}
		if(max(top, bottom)==c || max(left, right)==r) {
			cout<<1<<endl;
		} else if(grid[0][0]=='A' || grid[0][c-1]=='A' || grid[r-1][0]=='A' || grid[r-1][c-1]=='A' || rowMax==c || colMax==r) {
			cout<<2<<endl;
		} else if(top || bottom || left || right || rowMax==c-1 || colMax==r-1) {
			cout<<3<<endl;
		} else {
			cout<<4<<endl;
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
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

