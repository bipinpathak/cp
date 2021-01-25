#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
	ll n;
	cin>>n;
	while(n%2==0) {
		n/=2;
	}
    return n>1;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    cin>>t;
    while(t--) {
        if(solve()) {
			cout<<"YES"<<endl;
        } else {
			cout<<"NO"<<endl;
		}
    }
    return 0;
}

