#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int a, b, k;
	cin>>a>>b>>k;
	vector<int> boy(a+1), girl(b+1);
	vector<vector<int>> pairs(k, vector<int> (2));
	for(auto &i : pairs) {
		cin>>i[0];
	}
	for(auto  &i : pairs) {
		cin>>i[1];
	}
	ll ans=0;
	for(int i=0; i<k; i++) {
		ans+=i-boy[pairs[i][0]]-girl[pairs[i][1]];
		boy[pairs[i][0]]++;
		girl[pairs[i][1]]++;
	}
	cout<<ans<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
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

