#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	string s;
	cin>>s;
	queue<int> odd, even;
	for(auto i : s) {
		int x=i-'0';
		if(x%2) {
			odd.push(x);
		} else {
			even.push(x);
		}
	}
	string ans="";
	while(odd.size() || even.size()) {
		if(odd.size() && (even.size()==0 || even.front()>odd.front())) {
			ans+=to_string(odd.front());
			odd.pop();
		} else {
			ans+=to_string(even.front());
			even.pop();
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

