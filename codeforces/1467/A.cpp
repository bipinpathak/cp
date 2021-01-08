#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin>>n;
	string ans="";
	if(n) {
		ans+="9";
		n--;
	}
	if(n) {
		ans+="8";
		n--;
	}
	int last=9;
	while(n--) {
		ans+=to_string(last);
		last=(last+1)%10;
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

