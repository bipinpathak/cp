#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	string s;
	int q;
	cin>>s>>q;
	int n=s.length();
	int f[n][26];
	for(int i=0; i<n; i++) {
		for(int j=0; j<26; j++) {
			f[i][j]=0;
		}
		f[i][s[i]-'a']++;
	}
	for(int i=1; i<n; i++) {
		for(int j=0; j<26; j++) {
			f[i][j]+=f[i-1][j];
		}
	}
	while(q--) {
		int l, r;
		cin>>l>>r;
		l--, r--;
		int count=0;
		for(int i=0; i<26; i++) {
			int curr=f[r][i]-(l?f[l-1][i]:0);
			if(curr) {
				count++;
			}
		}
		if(r-l+1==1 || count>2 || (count==2 && s[l]!=s[r])) {
			cout<<"Yes"<<endl;
		} else {
			cout<<"No"<<endl;
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

