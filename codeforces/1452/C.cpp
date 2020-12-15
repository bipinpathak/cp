#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	string s;
	cin>>s;
	int ans=0, small=0, big=0;
	for(auto i : s) {
		if(i=='(') {
			small++;	
		} else if(i=='[') {
			big++;
		} else if(i==')') {
			if(small) {
				small--;
				ans++;
			}
		} else {
			if(big) {
				big--;
				ans++;
			}
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

