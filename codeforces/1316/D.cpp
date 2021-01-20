#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct cell{
	int x, y;
};

int n=1e3;
vector<vector<cell>> target(n, vector<cell> (n));
vector<vector<char>> ans(n, vector<char> (n, 'E'));

bool valid(int i, int j) {
	return (i>=0 && i<n && j>=0 && j<n);
}

bool operator==(const cell &a, const cell &b) {
	return a.x==b.x && a.y==b.y;
}

bool possible=true;

void go(int i, int j) {
	if(valid(i+1, j) && ans[i+1][j]=='E' && target[i][j]==target[i+1][j]) {
		ans[i+1][j]='U';
		go(i+1, j);
	}
	if(valid(i-1, j) && ans[i-1][j]=='E' && target[i][j]==target[i-1][j]) {
		ans[i-1][j]='D';
		go(i-1, j);
	}
	if(valid(i, j+1) && ans[i][j+1]=='E' && target[i][j]==target[i][j+1]) {
		ans[i][j+1]='L';
		go(i, j+1);
	}
	if(valid(i, j-1) && ans[i][j-1]=='E' && target[i][j]==target[i][j-1]) {
		ans[i][j-1]='R';
		go(i, j-1);
	}
	return;
}

void settle(int i, int j) {
	bool found=false;
	if(!found && valid(i-1, j) && target[i][j]==target[i-1][j]) {
		found=true;
		ans[i][j]='U';
	}
	if(!found && valid(i, j-1) && target[i][j]==target[i][j-1]) {
		found=true;
		ans[i][j]='L';
	}
	if(!found && valid(i+1, j) && target[i][j]==target[i+1][j]) {
		found=true;
		ans[i][j]='D';
		ans[i+1][j]='U';
	}
	if(!found && valid(i, j+1) && target[i][j]==target[i][j+1]) {
		found=true;
		ans[i][j]='R';
		ans[i][j+1]='L';
	}
	if(!found) {
		possible=false;
	}
	return;
}

void solve() {
	cin>>n;
	vector<cell> roots;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin>>target[i][j].x>>target[i][j].y;
			target[i][j].x--;
			target[i][j].y--;
			if(target[i][j].x==i && target[i][j].y==j) {
				ans[i][j]='X';
				roots.push_back(target[i][j]);
			}
		}
	}
	for(auto start : roots) {
		go(start.x, start.y);
	}
	for(int i=0; i<n && possible; i++) {
		for(int j=0; j<n && possible; j++) {
			if(ans[i][j]=='E' && target[i][j].x==-2) {
				settle(i, j);
			}
		}
	}
	for(int i=0; i<n && possible; i++) {
		for(int j=0; j<n && possible; j++) {
			if(ans[i][j]=='E') {
				possible=false;
			}
		}
	}
	if(!possible) {
		cout<<"INVALID"<<endl;
		return;
	} 
	cout<<"VALID"<<endl;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout<<ans[i][j];
		}
		cout<<endl;
	}
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    while(t--) {
        solve();
    }
    return 0;
}

