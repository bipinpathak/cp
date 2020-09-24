#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &i : a) {
		cin>>i;
	}
	for(int i=1; i<n; i++) {
		if(a[i]>=a[i-1]) {
			cout<<"YES"<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
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

