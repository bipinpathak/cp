#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n, rc=0, bc=0;
	string blue, red;
	cin>>n>>red>>blue;
	for(int i=0; i<n; i++) {
		if(red[i]>blue[i]) {
			rc++;
		} else if(blue[i]>red[i]) {
			bc++;
		}
	}
	if(rc>bc) {
		cout<<"RED";
	} else if(bc>rc) {
		cout<<"BLUE";
	} else {
		cout<<"EQUAL";
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

