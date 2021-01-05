#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll n, x, high=0, low=0, sum=0;
	cin>>n>>x;
	vector<ll> a(n);
	for(auto &i : a) {
		cin>>i;
		high+=(i+x-1)/x;
		sum+=i;
		if(sum%x==0) {
			low+=sum/x;
			sum=0;
		}
	}
	low+=(sum+x-1)/x;
	cout<<low<<" "<<high<<endl;
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

