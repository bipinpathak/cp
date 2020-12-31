#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cost(ll n) {
	return ((3*n*(n+1))/2)-n;
}

int go(ll n) {
	int low=0, high=n, mid;
	while(low<high) {
		mid=(low+high+1)/2;
		if(cost(mid)>n) {
			high=mid-1;
		} else {
			low=mid;
		}
	}
	if(low==0) {
		return 0;
	} 
	return 1+go(n-cost(low));
}

void solve() {
	ll n;
	cin>>n;
	cout<<go(n)<<endl;
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

