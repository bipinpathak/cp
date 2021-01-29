#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll low=0, high=0, mid;
	char response='y';
	while(response=='y') {
		low=high;
		high=max(2*low, (ll)1);
		cout<<"? "<<low<<" "<<high<<endl;
		cin>>response;
	}
	while(low<high) {
		mid=(high+low+1)/2;
		cout<<"? "<<low<<" "<<mid<<endl;
		cin>>response;
		if(response=='y') {
			low=mid;
		} else {
			high=mid-1;
		}
	}
	cout<<"! "<<high+1<<endl;
    return;
}

int main() {
#ifdef bipinpathak
    //(void)!freopen("input.txt", "r", stdin);
    //(void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	string s;
	cin>>s;
    while(s=="start") {
        solve();
		cin>>s;
    }
    return 0;
}

