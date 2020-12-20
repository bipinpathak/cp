#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	string s;
	cin>>n>>s;
	int count=0;
	while(s.size() && s.back()==')') {
		count++;
		s.pop_back();
	}
	if(count>s.size()) {
		cout<<"Yes";
	} else {
		cout<<"No";
	}
	cout<<endl;
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

