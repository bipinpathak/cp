#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n, i, raze=0, breach=0;
	string s, ans="1";
	cin>>n>>s;
	for(i=0; i<n; i++) {
		if(i%2 && (s[i]-'0')%2==0) breach++;
		else if(i%2==0 && (s[i]-'0')%2) raze++;
	}
	if(n%2) {
		if(!raze) ans="2";
	} else {
		if(breach) ans="2";
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
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

