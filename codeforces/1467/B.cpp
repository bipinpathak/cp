#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int go(vector<int>&a, int i) {
	int n=a.size();
	if(i+1<n && i-1>=0) {
		if( (a[i]>a[i-1] && a[i]>a[i+1]) || (a[i]<a[i-1] && a[i]<a[i+1]) ) {
			return 1;
		} 
	}
	return 0;
}

int cost(vector<int> &a, int i) {
	return go(a, i)+go(a, i-1)+go(a, i+1);
}

void solve() {
	int n;
	cin>>n;
	vector<int> a(n), active(n, 0);
	for(auto &i : a) {
		cin>>i;
	}
	for(int i=1; i<n-1; i++) {
		if( (a[i]>a[i-1] && a[i]>a[i+1]) || (a[i]<a[i-1] && a[i]<a[i+1]) ) {
			active[i]=1;
		} 
	}
	int ans=0, benifit=0;
	for(auto i : active) {
		ans+=i;
	}
	for(int i=0; i<n; i++) {
		int store=a[i], original=cost(a, i);
		if(i-1>=0) {
			a[i]=a[i-1];
			benifit=max(benifit, original-cost(a, i));
		}
		if(i+1<n) {
			a[i]=a[i+1];
			benifit=max(benifit, original-cost(a, i));
		}
		a[i]=store;
	}
	ans-=benifit;
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

