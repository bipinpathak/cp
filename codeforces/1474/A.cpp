#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	string s, ans="";
	cin>>n>>s;
	vector<int> sum(n), b(n, 1);
	for(int i=0; i<n; i++) {
		int curr=s[i]-'0';
		sum[i]=curr+b[i];
		if(i && sum[i]==sum[i-1]) {
			b[i]=0;
			sum[i]--;
		}
		ans+=to_string(b[i]);
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

