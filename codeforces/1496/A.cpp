#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool solve() {
    int n, k;
    string s;
    cin>>n>>k>>s;
    if(n<2*k+1) {
        return false;
    }
    for(int i=0; i<k; i++) {
        if(s[i]!=s[n-1-i]) {
            return false;
        }
    }
    return true;
}

int main() {
#ifdef bipinpathak
    (void)!freopen("input.txt", "r", stdin);
    (void)!freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) {
        if(solve()) {
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}

