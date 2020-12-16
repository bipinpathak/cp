#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	string s, ans="";
	cin>>s;
	int zero=0, n=s.length();
	for(auto i : s) {
		if(i=='0') {
			zero++;
		}
	}
	if(zero%n==0) {
		ans=s;
	} else {
		string loop;
		if(s[0]=='0') {
			loop="01";
		} else {
			loop="10";
		}	
		while(n--) {
			ans+=loop;
		}
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

