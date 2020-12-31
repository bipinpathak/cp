#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool destroy(int x, int y, vector<string> &a, vector<int> &row, vector<int> &col, int key) {
	bool ans=true;
	int n=a.size(), m=a[0].size();
	if((row[x] && row[x]!=key) || (col[y] && col[y]!=key)) {
		ans=false;
	}
	a[x][y]='.';
	if(ans && x+1<n && a[x+1][y]=='#') {
		ans&=destroy(x+1, y, a, row, col, key);
	}
	if(ans && x-1>=0 && a[x-1][y]=='#') {
		ans&=destroy(x-1, y, a, row, col, key);
	}
	if(ans && y+1<m && a[x][y+1]=='#') {
		ans&=destroy(x, y+1, a, row, col, key);
	}
	if(ans && y-1>=0 && a[x][y-1]=='#') {
		ans&=destroy(x, y-1, a, row, col, key);
	}
	row[x]=col[y]=key;
	return ans;
}

void solve() {
	int n, m;
	cin>>n>>m;
	vector<string> a(n);
	int count=0;
	for(auto &i : a) {
		cin>>i;
		for(auto j : i) {
			if(j=='#') {
				count++;
			}
		}
	}
	if(count==0) {
		cout<<0<<endl;
		return;
	}
	for(int i=0; i<n; i++) {
		int count=0;
		for(int j=0; j<m; j++) {
			if(a[i][j]=='#' && (j==0 || a[i][j]!=a[i][j-1])) {
				count++;
			}
		}
		if(count>1) {
			cout<<-1<<endl;
			return;
		}
	}
	for(int j=0; j<m; j++) {
		int count=0;
		for(int i=0; i<n; i++) {
			if(a[i][j]=='#' && (i==0 || a[i][j]!=a[i-1][j])) {
				count++;
			}
		}
		if(count>1) {
			cout<<-1<<endl;
			return;
		}
	}
	vector<int> row(n), col(m);
	int ans=0, key=1;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(a[i][j]=='#') {
				if(!destroy(i, j, a, row, col, key)) {
					cout<<-1<<endl;
					return;
				}
				key++;
				ans++;
			}
		}
	}
	int rowUsed=0, colUsed=0;
	for(int i=0; i<n; i++) {
		if(row[i]) {
			rowUsed++;
		}
	}
	for(int j=0; j<m; j++) {
		if(col[j]) {
			colUsed++;
		}
	}
	if((rowUsed==n && colUsed!=m) || (colUsed==m && rowUsed!=n)) {
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


