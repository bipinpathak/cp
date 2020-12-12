#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, k;
	vector<int> count(26);
	cin>>n>>k;
	string s;
	cin>>s;
	for(auto i : s) {
		count[i-'a']++;
	}
	cin>>s;
	for(auto i : s) {
		count[i-'a']--;
	}
	for(int i=0; i+1<26; i++) {
		if(count[i]<0 || count[i]%k) {
			cout<<"No"<<endl;
			return;
		}
		count[i+1]+=count[i];
	}
	cout<<"Yes"<<endl;
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

