#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	string s;
	cin>>s;
	int n=s.size();
	vector<int> change(n);
	for(int i=0; i<n; i++) {
		int vote=0;
		if(i-1>=0 && s[i]==s[i-1] && !change[i-1]) {
			vote++;
		}
		if(i-2>=0 && s[i]==s[i-2] && !change[i-2]) {
			vote++;
		}
		if(vote) {
			change[i]=1;
		}
	}
	int ans=0;
	for(auto i : change) {
		ans+=i;
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

