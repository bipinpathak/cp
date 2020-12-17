#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin>>n;
	vector<ll> time(n), target(n);
	for(int i=0; i<n; i++) {
		cin>>time[i]>>target[i];
	}
	ll pos=0, stop=0, speed=0;
	int ans=0;
	for(int i=0; i<n; i++) {
		if(time[i]>=stop) {
			ll distance=abs(pos-target[i]);
			if(i==n-1 || distance<=time[i+1]-time[i]) {
				ans++;
			}
			if(target[i]==pos) {
				speed=0;
			} else if(target[i]>pos) {
				speed=1;
			} else {
				speed=-1;
			}
			pos=target[i];
			stop=time[i]+distance;
		} else {
			ll curr=pos-speed*(stop-time[i]), nextStop=pos-((i==n-1)?0:speed*(stop-time[i+1]));
			if(i<n-1 && time[i+1]>=stop) {
				nextStop=pos;
			}
			if( (curr<=target[i] && target[i]<=nextStop) || (curr>=target[i] && target[i]>=nextStop) ) {
				ans++;
			}
		}
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

