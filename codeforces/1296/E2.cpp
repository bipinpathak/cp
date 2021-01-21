#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	string s;
	cin>>n>>s;
	vector<int> ans(n, 0);
	for(int color=1; color<=27; color++) {
		int high=0;
		bool update=false;
		for(int i=0; i<n; i++) {
			if(ans[i]) {
				continue;
			}
			int curr=s[i]-'a';
			if(curr>=high) {
				ans[i]=color;
				high=curr;
				update=true;
			}
		}
		if(!update) {
			cout<<color-1<<endl;
			break;
		}
	}
	for(auto i : ans) {
		cout<<i<<" ";
	}
	cout<<endl;
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
    while(t--) {
        solve();
    }
    return 0;
}

