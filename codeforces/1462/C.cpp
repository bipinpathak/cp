#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int x;
	cin>>x;
	string ans;
	for(int i=9; i && x; i--) {
		if(i<=x) {
			ans+=to_string(i);
			x-=i;
		}
	}
	reverse(ans.begin(), ans.end());
	if(x) {
		ans="-1";
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

