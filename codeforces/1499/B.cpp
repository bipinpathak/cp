#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    string s;
    cin>>s;
    int one=0, curr=0;
    for(auto i : s) {
        if(one) {
            if(i=='0') {
                curr++;
            } else {
                curr=0;
            }
        } else {
            if(i=='1') {
                curr++;
            } else {
                curr=0;
            }
        }
        if(curr==2) {
            curr=0;
            if(one) {
                cout<<"NO"<<endl;
                return;
            }
            one=1;
        }
    }
    cout<<"YES"<<endl;
    return;
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
        solve();
    }
    return 0;
}

