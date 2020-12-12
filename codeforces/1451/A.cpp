#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin>>n;
	if(n==1) {
		cout<<0<<endl;
	} else if(n==2) {
		cout<<1<<endl;
	} else if(n==3) {
		cout<<2<<endl;	
	} else if(n%2==0) {
		cout<<2<<endl;
	} else {
		cout<<3<<endl;
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

