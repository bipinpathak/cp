#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, k;
	string s;
	cin>>n>>k>>s;
	sort(s.rbegin(), s.rend());
	if(s[n-k]!=s.back()) {
		cout<<s[n-k]<<endl;
		return;
	}
	for(int i=1; i<k; i++) {
		s.pop_back();
	}
	reverse(s.begin(), s.end());
	if(s.size()>=2 && s[1]==s.back()) {
		int total=s.size()-1;
		total-=(total+k-1)/k;
		while(total--) {
			s.pop_back();
		}
	}
	cout<<s<<endl;
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

