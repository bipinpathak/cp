#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	vector<ll> a(3);
	for(auto &i : a) {
		cin>>i;
	}
	sort(a.begin(), a.end());
	if(a[2]+a[1]>8*a[0] || (a[0]+a[1]+a[2])%9) {
		cout<<"NO"<<endl;
	} else {
		cout<<"YES"<<endl;
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

