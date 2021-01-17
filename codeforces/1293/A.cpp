#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, s, k;
	cin>>n>>s>>k;
	vector<int> closed(k);
	for(auto &i : closed) {
		cin>>i;
	}
	map<int, int> count;
	int curr=0;
	for(auto i : closed) {
		count[abs(s-i)]++;	
		if(i==s) {
			curr++;
		}
		while(count[curr]>=2 || (count[curr]==1 && (s-curr<=0 || s+curr>n))) {
			curr++;
		}
	}
	cout<<curr<<endl;
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

