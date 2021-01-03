#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, k;
	string s;
	cin>>n>>k>>s;
	int votes[k][26], victory[k];
	for(int i=0; i<k; i++) {
		for(int j=0; j<26; j++) {
			votes[i][j]=0;
		}
		victory[i]=0;
	}
	for(int i=0; i<n; i++) {
		votes[i%k][s[i]-'a']++;
	}
	for(int i=0; i<=k/2; i++) {
		int won=0;
		for(int j=1; j<26; j++) {
			if(votes[i][j]+votes[k-1-i][j]>votes[i][won]+votes[k-1-i][won]) {
				won=j;
			}
		}
		victory[i]=victory[k-1-i]=won;
	}
	int ans=0;
	for(int i=0; i<n; i++) {
		if((s[i]-'a')!=victory[i%k]) {
			ans++;
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

