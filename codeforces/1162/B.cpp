#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve() {
	int n, m;
	cin>>n>>m;
	vector<vector<int>> a(n, vector<int> (m)), b(n, vector<int> (m));
	for(auto &i : a) {
		for(auto &j : i) {
			cin>>j;
		}
	}
	for(auto &i : b) {
		for(auto &j : i) {
			cin>>j;
		}
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(a[i][j]<b[i][j]) {
				swap(a[i][j], b[i][j]);
			}
			if(a[i][j]<=max(i?a[i-1][j]:0, j?a[i][j-1]:0) || b[i][j]<=max(i?b[i-1][j]:0, j?b[i][j-1]:0)) {
				return 0;
			}
		}
	}
    return 1;
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
        if(solve()) {
			cout<<"Possible";
		} else {
			cout<<"Impossible";
		}
		cout<<endl;
    }
    return 0;
}

