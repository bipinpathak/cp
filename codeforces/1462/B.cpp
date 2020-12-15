#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	string s, a="2020";
	cin>>n>>s;
	for(int front=0; front<=4; front++) {
		int i;
		for(i=0; i<front && s[i]==a[i]; i++);
		if(i==front) {
			int j;
			for(j=n-4+front; j<n && s[j]==a[j-n+4]; j++);
			if(j==n) {
				cout<<"YES"<<endl;
				return;
			}
		}
	}
	cout<<"NO"<<endl;
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

