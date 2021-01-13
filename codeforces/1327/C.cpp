#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, m, k;
	cin>>n>>m>>k;
	k*=2;
	while(k--) {
		int x, y;
		cin>>x>>y;
	}
	string ans="";
	for(int i=1; i<n; i++) {
		ans+="U";
	}
	for(int i=1; i<m; i++) {
		ans+="L";
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(i%2==0 && j<m-1) {
				ans+="R";
			} else if(i%2==1 && j>0) {
				ans+="L";
			}
		}
		if(i<n-1) {
			ans+="D";
		}
	}
	cout<<ans.size()<<endl<<ans<<endl;
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

