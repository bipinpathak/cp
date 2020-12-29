#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, m, sum=0, aSum=0, bSum=0, x;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>x;
		sum+=x;
		aSum=max(aSum, sum);
	}
	cin>>m;
	sum=0;
	for(int i=0; i<m; i++) {
		cin>>x;
		sum+=x;
		bSum=max(bSum, sum);
	}
	cout<<aSum+bSum<<endl;
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

