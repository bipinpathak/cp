#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, q;
	string s;
	cin>>n>>q>>s;
	while(q--) {
		int l, r;
		string ans="NO";
		cin>>l>>r;
		l--;
		r--;
		for(int i=0; i<l && ans=="NO"; i++) {
			if(s[i]==s[l]) {
				ans="YES";
			}
		}
		for(int i=r+1; i<n && ans=="NO"; i++) {
			if(s[i]==s[r]) {
				ans="YES";
			}
		}
		cout<<ans<<endl;
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

