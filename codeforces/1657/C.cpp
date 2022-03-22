#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    int n;
    string s;
    cin>>n>>s;
    int moves=0, left=0, done=0;
    while(done+1<n) {
        if(s[done]==s[done+1] || (s[done]=='(' && s[done+1]==')')) {
            moves++;
            done+=2;
        } else {
            int right=done+1;
            while(right<n && s[right]!=')') {
                right++;
            }
            if(right<n) {
                moves++;
                done=right+1;
            } else {
                break;
            }
        }
    }
    left=n-done;
    cout<<moves<<" "<<left<<endl;
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
    cin>>t;
    for(int i=0; i<t; i++) {
        //cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}

