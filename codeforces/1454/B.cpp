#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin>>n;
	vector<int> a(n);
	map<int, int> f;
	for(auto &i : a) {
		cin>>i;
		f[i]++;
	}
	int ans=-1;
	for(int i=0; i<n; i++) {
		if(f[a[i]]>1) {
			continue;
		}
		if(ans==-1) {
			ans=i;
		} else if(a[ans]>a[i]) {
			ans=i;
		}
	}
	if(ans!=-1) {
		ans++;
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

