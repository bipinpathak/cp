#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, k, z;
	cin>>n>>k>>z;
	vector<int> a(n), left(z+1, k+1), sum(z+1, 0);
	for(int i=0; i<n; i++) {
		cin>>a[i];
		for(int j=0; j<=z; j++) {
			if(left[j]) {
				left[j]--;
				sum[j]+=a[i];
			}
		}
		for(int j=0; j<z && i; j++) {
			if(left[j]) {
				int offer=sum[j]+a[i-1], cost=1;
				if(left[j]>1) {
					offer+=a[i];
					cost++;
				}
				if(sum[j+1]<offer) {
					sum[j+1]=offer;
					left[j+1]=left[j]-cost;
				}
			}
		}
	}
	int ans=0;
	for(auto i : sum) {
		ans=max(ans, i);
	}
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

