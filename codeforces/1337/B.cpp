#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int x, n, m;
	cin>>x>>n>>m;
	while(n && x>20) {
		x=x/2+10;
		n--;
	}
	while(m && x>0) {
		x-=10;
		m--;
	}
	if(x<=0) {
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
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

