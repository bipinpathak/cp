#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, k;
	cin>>n>>k;
	int extra=n-k;
	vector<int> order(k);
	for(int i=0; i<k; i++) {
		order[i]=i+1;
	}
	if(extra>0) {
		reverse(order.begin(), order.end());
		reverse(order.begin(), order.begin()+min(extra+1, k));
		reverse(order.begin(), order.end());
	}
	for(auto i : order) {
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

