#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, m, a, b;
	cin>>n>>m>>a>>b;
	if(n*a!=m*b) {
		cout<<"NO"<<endl;
		return;
	}
	cout<<"YES"<<endl;
	int ans[n][m];
	for(auto &i : ans) {
		for(auto &j : i) {
			j=0;
		}
	}
	int col=0;
	for(int i=0; i<n*a; i++) {
		if(i && i%b==0) {
			col++;
		}
		ans[i%n][col]=1;
	}
	for(auto &i : ans) {
		for(auto &j : i) {
			cout<<j;
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

