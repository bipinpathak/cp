#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int f[500][500][26], dp[500][500], n;
string s;

int fetch(int l, int r) {
	if(l>r) {
		return 0;
	}
	if(!dp[l][r]) {
		if(f[l][r][s[r]-'a']==r-l+1) {
			dp[l][r]=1;
		} else {
			dp[l][r]=1+fetch(l+1, r);
			for(int m=l+1; m<=r; m++) {
				if(s[m]==s[l]) {
					dp[l][r]=min(dp[l][r], fetch(l, m-1)+fetch(m+1, r));
				}
			}
		}
	}
	return dp[l][r];
}

void solve() {
	cin>>n>>s;
	for(int i=0; i<n; i++) {
		for(int j=i; j<n; j++) {
			for(int k=i; k<=j; k++) {
				f[i][j][s[k]-'a']++;
			}
		}
	}
	cout<<fetch(0, n-1)<<endl;
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

