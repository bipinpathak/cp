#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll n, k;
	cin>>n>>k;
	if(n>=k*k && (k%2+n%2)%2==0) {
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

