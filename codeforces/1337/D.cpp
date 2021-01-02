#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll calc(ll a, ll b, ll c) {
	return (a-b)*(a-b)+(b-c)*(b-c)+(a-c)*(a-c);
}

ll small(vector<ll> &a, ll target) {
	int left=0, right=a.size()-1, mid;
	while(left<right) {
		mid=(left+right+1)/2;
		if(a[mid]>target) {
			right=mid-1;
		} else {
			left=mid;
		}
	}
	return a[left];
}

ll big(vector<ll> &a, ll target) {
	int left=0, right=a.size()-1, mid;
	while(left<right) {
		mid=left+(right-left)/2;
		if(a[mid]<target) {
			left=mid+1;
		} else {
			right=mid;
		}
	}
	return a[left];
}

ll go(vector<ll> &a, vector<ll> &b, vector<ll> &c) {
	ll ans=calc(a[0], b[0], c[0]);
	for(auto mid : b) {
		ll left=small(a, mid), right=big(c, mid);
		ans=min(ans, calc(right, mid, left));
	}
	return ans;
}

void solve() {
	int nr, ng, nb;
	cin>>nr>>ng>>nb;
	vector<ll> red(nr), green(ng), blue(nb);
	for(auto &i : red) cin>>i;
	for(auto &i : green) cin>>i;
	for(auto &i : blue) cin>>i;
	sort(red.begin(), red.end());
	sort(green.begin(), green.end());
	sort(blue.begin(), blue.end());
	ll ans=calc(red[0], green[0], blue[0]);
	ans=min(ans, go(red, green, blue));
	ans=min(ans, go(green, blue, red));
	ans=min(ans, go(blue, red, green));
	ans=min(ans, go(blue, green, red));
	ans=min(ans, go(green, red, blue));
	ans=min(ans, go(red, blue, green));
	cout<<ans<<endl;
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


