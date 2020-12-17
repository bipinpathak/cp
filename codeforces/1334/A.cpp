#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin>>n;
	vector<int> plays(n), wins(n);
	string ans="YES";
	for(int i=0; i<n; i++) {
		cin>>plays[i]>>wins[i];
	}
	for(int i=0; i<n; i++) {
		if(plays[i]<wins[i] || (i && (plays[i]<plays[i-1] || wins[i]<wins[i-1] || wins[i]-wins[i-1]>plays[i]-plays[i-1]))) {
			ans="NO";
			break;
		}
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

