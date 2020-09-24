#include <bits/stdc++.h>
using namespace std;
void solve() {
	long long n, ans=0;
	cin>>n;
	vector<vector<int>> bits(n, vector<int> (30));
	for(int i=0; i<n; i++) {
		int x;
		cin>>x;
		for(int j=0; j<30; j++) {
			bits[i][j]=x%2;
			x/=2;
		}
	}
	vector<int> checked(n);
	for(int j=29; j>=0; j--) {
		long long count=0;
		for(int i=0; i<n; i++) {
			if(!checked[i]) {
				if(bits[i][j]) {
					count++;
					checked[i]=1;
				}
			}
		}
		ans+=(count*(count-1))/2;
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

