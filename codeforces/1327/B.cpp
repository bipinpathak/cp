#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin>>n;
	vector<int> princess(n, -1), prince(n, -1);
	bool improve=false;
	int unmarriedPrincess;
	for(int i=0; i<n; i++) {
		int k;
		cin>>k;
		while(k--) {
			int g;
			cin>>g;
			if(princess[i]==-1 && prince[g-1]==-1) {
				prince[g-1]=i;
				princess[i]=g-1;
			}
		}
		if(princess[i]==-1 && !improve) {
			improve=true;
			unmarriedPrincess=i;
		}
	}
	if(improve) {
		cout<<"IMPROVE"<<endl;
		for(int i=0; i<n; i++) {
			if(prince[i]==-1) {
				cout<<unmarriedPrincess+1<<" "<<i+1<<endl;
				break;
			}
		}
	} else {
		cout<<"OPTIMAL"<<endl;
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
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}

