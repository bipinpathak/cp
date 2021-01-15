#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &i : a) {
		cin>>i;
	}
	for(int i=0; i<n; i++) {
		int distance=min(i, n-1-i);
		if(a[i]<distance) {
			cout<<"No"<<endl;
			return;
		}
	}
	if(n%2==0 && a[n/2]==a[n/2-1] && a[n/2]==n/2-1) {
		cout<<"No"<<endl;
		return;
	}
	cout<<"Yes"<<endl;
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

