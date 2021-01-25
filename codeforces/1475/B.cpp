#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
	int n;
	cin>>n;
	int rem, div;
	rem=n%2020;
	div=n/2020;
    return rem<=div;
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

