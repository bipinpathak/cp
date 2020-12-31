#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin>>n;
	vector<string> a(n);
	for(auto &i : a) {
		cin>>i;
	}
	bool possible=0;
	for(auto &i : a) {
		if(i[0]==i[1] && i[1]=='O') {
			i[0]=i[1]='+';
			possible=1;
		} else if(i[3]==i[4] && i[4]=='O') {
			i[3]=i[4]='+';
			possible=1;
		}
		if(possible) {
			break;
		}
	}
	if(possible) {
		cout<<"YES"<<endl;
		for(auto &i : a) {
			cout<<i<<endl;
		}
	} else {
		cout<<"NO"<<endl;
	}
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
    while(t--) {
        solve();
    }
    return 0;
}

