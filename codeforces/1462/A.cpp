#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin>>n;
	vector<int> a(n), ans(n);
	for(auto &i : a) {
		cin>>i;
	}
	for(int i=0; 2*i<n; i++) {
		ans[2*i]=a[i];
	}
	for(int i=n-1; 2*(n-i)-1<n; i--) {
		ans[2*(n-i)-1]=a[i];
	}
	for(auto i : ans) {
		cout<<i<<" ";
	}
	cout<<endl;
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

