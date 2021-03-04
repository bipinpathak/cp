#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll p=1e9+7;

ll power(ll a, ll x) {
	ll ans=1;
	while(x) {
		if(x&1) {
			ans=(ans*a)%p;
		}
		x=x>>1;
		a=(a*a)%p;
	}
	return ans;
}

bool good(vector<vector<int>> &grid, vector<int> &row, vector<int> &col) {
    int h=(int)row.size(), w=(int)col.size();
    for(int i=0; i<h; i++) {
        int count=0;
        for(int j=0; j<w && grid[i][j]; j++) {
            count++;
        }
        if(count!=row[i]) {
            return false;
        }
    }
    for(int j=0; j<w; j++) {
        int count=0;
        for(int i=0; i<h && grid[i][j]; i++) {
            count++;
        }
        if(count!=col[j]) {
            return false;
        }
    }
    return true;
}

void solve() {
    int h, w;
    cin>>h>>w;
    vector<int> row(h), col(w);
    for(auto &i : row) {
        cin>>i;
    }
    for(auto &i : col) {
        cin>>i;
    }
    vector<vector<int>> grid(h, vector<int> (w));
    for(int i=0; i<h; i++) {
        for(int j=0; j<w && j<row[i]; j++) {
            grid[i][j]=1;
        }
    }
    for(int j=0; j<w; j++) {
        for(int i=0; i<h && i<col[j]; i++) {
            grid[i][j]=1;
        }
    }
    if(!good(grid, row, col)) {
        cout<<0<<endl;
        return;
    }
    int total=0;
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(j>row[i] && i>col[j]) {
                total++;
            }
        }
    }
    cout<<power(2, total)<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}

