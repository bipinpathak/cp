#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
	int n, m;
	cin>>n>>m;
	vector<vector<int>> robbers(n, vector<int> (2)), lights(m, vector<int> (2));
	for(auto &i : robbers) {
		cin>>i[0]>>i[1];
	}
	for(auto &i : lights) {
		cin>>i[0]>>i[1];
	}
	int MAXX=1e6+3, ans=MAXX;
	vector<int> yNeeded(MAXX);
	for(auto robber : robbers) {
		for(auto light : lights) {
			if(robber[0]<=light[0] && robber[1]<=light[1]) {
				yNeeded[light[0]-robber[0]]=max(yNeeded[light[0]-robber[0]], light[1]-robber[1]+1);
			}
		}
	}
	for(int i=MAXX-2; i>=0; i--) {
		yNeeded[i]=max(yNeeded[i], yNeeded[i+1]);
		ans=min(ans, i+yNeeded[i]);
	}
	cout<<ans<<endl;
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

